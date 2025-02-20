#include "Graph.hpp"
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>    // for practicing STL    
#include <stack>
#include <set>
#include <limits>

// ====================================
// Constructors and Destructor
// ====================================

// Default constructor.
// Creates an empty graph. By default, the graph is unweighted and undirected.
Graph::Graph()
    : n(0), e(0), isWeighted(false), isDirected(false),
      nodeVector(), edgelist(), adjacencyList() 
{
    // No nodes; edgelist is default constructed (and empty) and so is adjacencyList.
}

// Constructor with a specified number of nodes.
// Initializes the graph with nodes labeled 0 through numNodes-1.
Graph::Graph(int numNodes, bool weighted, bool directed)
    : n(numNodes), e(0), isWeighted(weighted), isDirected(directed),
      nodeVector(), edgelist(), adjacencyList() 
{
    // Initialize nodeVector with nodes 0, 1, ..., n-1.
    nodeVector.resize(n);
    for (int i = 0; i < n; i++) 
    {
        nodeVector[i] = i;
    }
    
    // Build the adjacency list: for each node, create an empty inner list.
    // (We assume that DoublyLinkedList has a default constructor and an InsertBack() method.)
    while (!adjacencyList.IsEmpty()) 
    {
        adjacencyList.DeleteFront();
    }
    for (int i = 0; i < n; i++) 
    {
        DoublyLinkedList<int> emptyList;
        adjacencyList.InsertBack(emptyList);
    }
    // edgelist remains empty until edges are added.
}

// Constructor from a vector of node identifiers.
Graph::Graph(const std::vector<int>& nodes, bool weighted, bool directed)
    : n(nodes.size()), e(0), isWeighted(weighted), isDirected(directed),
      nodeVector(nodes), edgelist(), adjacencyList() 
{
    // Build the adjacency list: create an empty inner list for each node.
    while (!adjacencyList.IsEmpty()) 
    {
        adjacencyList.DeleteFront();
    }
    for (size_t i = 0; i < nodeVector.size(); i++) 
    {
        DoublyLinkedList<int> emptyList;
        adjacencyList.InsertBack(emptyList);
    }
    // edgelist remains empty.
}

// Destructor.
Graph::~Graph() 
{
    // Clear nodeVector.
    nodeVector.clear();
    
    // Clear the adjacency list.
    while (!adjacencyList.IsEmpty()) 
    {
        adjacencyList.DeleteFront();
    }
    // edgelist is destroyed by its own destructor.
}


// ===================================
// Modification Methods (Add/Remove)
// ===================================

// AddNode: add a new node
void Graph::AddNode(int node) 
{
    // If node already exists, throw.
    if (std::find(nodeVector.begin(), nodeVector.end(), node) != nodeVector.end())
        throw std::invalid_argument("Node already exists.");
    
    // Append the new node.
    nodeVector.push_back(node);
    n++;

    // Append a new, empty inner list to the adjacency list.
    DoublyLinkedList<int> emptyList;
    adjacencyList.InsertBack(emptyList);
}

// Helper to convert a MIXED_TYPE to int (for node IDs)
int variantToInt(const MIXED_TYPE &v) {
    if (std::holds_alternative<int>(v))
        return std::get<int>(v);
    throw std::runtime_error("Variant does not hold an int.");
}

// RemoveNode: remove a node and all its incident edges
void Graph::RemoveNode(int node) 
{
    // Find the node in nodeVector.
    auto it = std::find(nodeVector.begin(), nodeVector.end(), node);
    if (it == nodeVector.end())
        throw std::invalid_argument("Node does not exist.");
    int index = std::distance(nodeVector.begin(), it);
    
    // Remove the corresponding inner list from adjacencyList.
    adjacencyList.Delete(index);
    
    // Erase the node from nodeVector.
    nodeVector.erase(it);
    n--;
    
    // Rebuild the edgelist (GeneralArray) without any edge that is incident to this node.
    // We assume that edgelist supports push_back(), size(), and operator[].
    GeneralArray<std::vector<MIXED_TYPE>> newEdgeList;
    // (newEdgeList is initially empty.)
    for (int i = 0; i < edgelist.Length(); i++) 
    {
        std::vector<MIXED_TYPE> edge = edgelist[i];
        // For a weighted graph, edge size should be 3; for unweighted, size 2.
        // If either u or v equals the removed node, skip it.
        if ((variantToInt(edge[0]) == node) || (variantToInt(edge[1]) == node))
            continue;
        newEdgeList.Push_back(edge);
    }

    edgelist = newEdgeList;
    e = edgelist.Length();
    
    // Also, remove the node from every inner list in adjacencyList.
    for (auto outerIt = adjacencyList.begin(); outerIt != adjacencyList.end(); ++outerIt) 
    {
        // Since *outerIt is returned as const, cast away const.
        DoublyLinkedList<int>& innerList = const_cast<DoublyLinkedList<int>&>(*outerIt);
        // Remove all occurrences of 'node' in this inner list.
        // We iterate by index; collect indices to remove then delete them in reverse order.
        std::vector<int> indicesToRemove;
        int pos = 0;

        for (auto innerIt = innerList.begin(); innerIt != innerList.end(); ++innerIt, pos++) 
            if (*innerIt == node)
                indicesToRemove.push_back(pos);
        
        for (int i = indicesToRemove.size() - 1; i >= 0; i--) 
            innerList.Delete(indicesToRemove[i]);
    }
}

// AddEdge: add an edge from u to v with weight w (w forced to 1 if unweighted)
void Graph::AddEdge(int u, int v, double w) 
{
    // Verify both nodes exist.
    auto it_u = std::find(nodeVector.begin(), nodeVector.end(), u);
    auto it_v = std::find(nodeVector.begin(), nodeVector.end(), v);

    if (it_u == nodeVector.end() || it_v == nodeVector.end())
        throw std::invalid_argument("One or both nodes do not exist.");
    
    // For unweighted graphs, force w to 1.
    if (!isWeighted)
        w = 1;
    
    // Build the edge vector.
    std::vector<MIXED_TYPE> edgeVec;
    edgeVec.push_back(u);
    edgeVec.push_back(v);
    if (isWeighted)
        edgeVec.push_back(w);
    
    // Append the edge to edgelist.
    edgelist.Push_back(edgeVec);
    
    // Update the adjacency list:
    // For node u, add v.
    int index_u = std::distance(nodeVector.begin(), it_u);
    auto outerIt = adjacencyList.begin();
    for (int i = 0; i < index_u; ++i)
        ++outerIt;
    // Insert v into the inner list. (Cast away const if needed.)
    const_cast<DoublyLinkedList<int>&>(*outerIt).InsertBack(v);
    
    // For undirected graphs, also add u to v's inner list.
    if (!isDirected) 
    {
        int index_v = std::distance(nodeVector.begin(), it_v);
        auto outerIt2 = adjacencyList.begin();
        for (int i = 0; i < index_v; ++i)
            ++outerIt2;
        const_cast<DoublyLinkedList<int>&>(*outerIt2).InsertBack(u);
    }
    
    e++;
}

// RemoveEdge: remove an edge from the graph
void Graph::RemoveEdge(int u, int v) 
{
    // Verify that both nodes exist.
    auto it_u = std::find(nodeVector.begin(), nodeVector.end(), u);
    auto it_v = std::find(nodeVector.begin(), nodeVector.end(), v);
    if (it_u == nodeVector.end() || it_v == nodeVector.end())
        throw std::invalid_argument("One or both nodes do not exist.");
    
    // Rebuild the edgelist without the edge (u,v) (and for undirected graphs, (v,u)).
    GeneralArray<std::vector<MIXED_TYPE>> newEdgeList;
    for (int i = 0; i < edgelist.Length(); i++) 
    {
        std::vector<MIXED_TYPE> edge = edgelist[i];
        bool removeEdge = false;
        if (isWeighted) 
        {
            // For weighted graphs, edge vector: {u, v, weight}
            if ((variantToInt(edge[0]) == u && variantToInt(edge[1]) == v) ||
                (!isDirected && variantToInt(edge[0]) == v && variantToInt(edge[1]) == u))
                removeEdge = true;
        } 
        else 
        {
            // For unweighted graphs, edge vector: {u, v}
            if ((variantToInt(edge[0]) == u && variantToInt(edge[1]) == v) ||
                (!isDirected && variantToInt(edge[0]) == v && variantToInt(edge[1]) == u))
                removeEdge = true;
        }
        if (!removeEdge)
            newEdgeList.Push_back(edge);
    }
    edgelist = newEdgeList;
    e = edgelist.Length();
    
    // Update the adjacency list:
    // Remove v from u's neighbor list.
    int index_u = std::distance(nodeVector.begin(), it_u);
    auto outerIt = adjacencyList.begin();
    for (int i = 0; i < index_u; ++i)
        ++outerIt;
    {
        DoublyLinkedList<int>& innerList = const_cast<DoublyLinkedList<int>&>(*outerIt);
        int pos = 0;

        for (auto innerIt = innerList.begin(); innerIt != innerList.end(); ++innerIt, pos++) {
            if (*innerIt == v) 
            {
                innerList.Delete(pos);
                break;
            }
        }
    }
    
    // For undirected graphs, remove u from v's neighbor list.
    if (!isDirected) 
    {
        int index_v = std::distance(nodeVector.begin(), it_v);
        auto outerIt2 = adjacencyList.begin();

        for (int i = 0; i < index_v; ++i)
            ++outerIt2;
        {
            DoublyLinkedList<int>& innerList = const_cast<DoublyLinkedList<int>&>(*outerIt2);
            int pos = 0;
            for (auto innerIt = innerList.begin(); innerIt != innerList.end(); ++innerIt, pos++) 
            {
                if (*innerIt == u) 
                {
                    innerList.Delete(pos);
                    break;
                }
            }
        }
    }
}

// ================================
// Accessor Methods (Properties)
// ================================

bool Graph::IsEmpty() const 
{
    // The graph is empty if there are no nodes.
    return nodeVector.empty();
}

int Graph::Degree(int u) const 
{
    if (u < 0 || u >= n) 
    {
        throw std::out_of_range("Invalid node identifier.");
    }
    
    // Obtain the out-degree from the adjacency list.
    auto outer = adjacencyList.begin();
    // Advance to the u-th inner list.
    for (int i = 0; i < u; ++i) 
    {
        ++outer;
    }
    if (outer == adjacencyList.end()) 
    {
        throw std::runtime_error("Adjacency list index error.");
    }
    int outDegree = outer->Length();

    // For undirected graphs, degree is simply outDegree.
    if (!isDirected) 
    {
        return outDegree;
    }
    
    // For directed graphs, add the in-degree: count the number of lists where u appears.
    int inDegree = 0;
    for (auto it = adjacencyList.begin(); it != adjacencyList.end(); ++it)
        for (auto inner = it->begin(); inner != it->end(); ++inner)
            if (*inner == u) 
                inDegree++;

    return outDegree + inDegree;
}

bool Graph::ExistsEdge(int u, int v) const 
{
    if (u < 0 || u >= n || v < 0 || v >= n)
        throw std::out_of_range("Invalid node identifier.");
    
    // Check the neighbor list for node u.
    auto outer = adjacencyList.begin();
    for (int i = 0; i < u; ++i) 
        ++outer;
    
    if (outer == adjacencyList.end())
        throw std::runtime_error("Adjacency list index error.");
    
    for (auto inner = outer->begin(); inner != outer->end(); ++inner)
        if (*inner == v)
            return true;
    
    // For undirected graphs, also check the neighbor list for node v.
    if (!isDirected) 
    {
        outer = adjacencyList.begin();
        for (int i = 0; i < v; ++i) 
        {
            ++outer;
        }
        if (outer == adjacencyList.end()) 
        {
            throw std::runtime_error("Adjacency list index error.");
        }
        for (auto inner = outer->begin(); inner != outer->end(); ++inner) 
        {
            if (*inner == u)
                return true;
        }
    }
    
    return false;
}


int Graph::NumberOfNodes() const 
{
    // Return the number of nodes.
    return n;
}

int Graph::NumberOfEdges() const 
{
    // Return the number of edges.
    return e;
}

// =====================================
// Spanning Tree and Component Methods
// =====================================

// ---------- Spanning Tree ----------
// Returns a spanning forest (i.e. a spanning tree for each connected component)
// using BFS. Each new edge is added with weight 1.
Graph Graph::SpanningTree() const 
{
    // Create an empty graph with the same number of nodes and type.
    Graph tree(n, isWeighted, isDirected);
    // Initially, tree has the same nodes but no edges.
    std::vector<bool> visited(n, false);
    std::queue<int> q;
    
    // For each connected component, perform BFS.
    for (int start = 0; start < n; ++start) 
    {
        if (!visited[start]) 
        {
            q.push(start);
            visited[start] = true;
            while (!q.empty()) 
            {
                int u = q.front();
                q.pop();

                // Get u's neighbor list from adjacencyList.
                auto it = adjacencyList.begin();
                for (int i = 0; i < u; ++i)
                    ++it;

                // For every neighbor v of u...
                for (auto nbrIt = it->begin(); nbrIt != it->end(); ++nbrIt) 
                {
                    int v = *nbrIt;
                    if (!visited[v]) 
                    {
                        visited[v] = true;
                        q.push(v);
                        // In the spanning tree, add edge (u,v) with weight 1.
                        tree.AddEdge(u, v, 1);
                    }
                }
            }
        }
    }
    return tree;
}

// ---------- Connected Components ----------
// Returns a vector of components; each component is represented as a vector of node IDs.
std::vector<std::vector<int>> Graph::Components() const 
{
    std::vector<bool> visited(n, false);
    std::vector<std::vector<int>> components;
    std::queue<int> q;
    
    for (int start = 0; start < n; ++start) 
    {
        if (!visited[start]) 
        {
            std::vector<int> comp;
            q.push(start);
            visited[start] = true;

            while (!q.empty()) 
            {
                int u = q.front();
                q.pop();
                comp.push_back(u);
                // Get u's neighbors.
                auto it = adjacencyList.begin();
                for (int i = 0; i < u; ++i)
                    ++it;

                for (auto nbrIt = it->begin(); nbrIt != it->end(); ++nbrIt) 
                {
                    int v = *nbrIt;
                    if (!visited[v]) 
                    {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            components.push_back(comp);
        }
    }
    return components;
}

// ---------- Biconnected Components ----------
// Helper function for DFS to compute biconnected components.
void Graph::BCCUtil(int u, std::vector<int>& disc, std::vector<int>& low,
                    std::vector<int>& parent, int& time,
                    std::stack<std::pair<int,int>>& st,
                    std::vector<std::vector<int>>& bcc) const 
{
    disc[u] = low[u] = ++time;
    int children = 0;

    auto it = adjacencyList.begin();    // Retrieve u's neighbor list.
    for (int i = 0; i < u; ++i)
        ++it;

    for (auto nbrIt = it->begin(); nbrIt != it->end(); ++nbrIt) 
    {
        int v = *nbrIt;
        if (disc[v] == -1)  // v not visited. 
        {  
            children++;
            parent[v] = u;
            st.push({u, v});
            BCCUtil(v, disc, low, parent, time, st, bcc);
            low[u] = std::min(low[u], low[v]);

            // If u is an articulation point, pop all edges till (u,v)
            if ((parent[u] == -1 && children > 1) || (parent[u] != -1 && low[v] >= disc[u])) 
            {
                std::set<int> compSet;
                while (!st.empty() && st.top() != std::make_pair(u, v)) 
                {
                    auto edge = st.top();
                    st.pop();
                    compSet.insert(edge.first);
                    compSet.insert(edge.second);
                }
                if (!st.empty()) 
                { 
                    auto edge = st.top();   // pop the (u,v) edge too.
                    st.pop();
                    compSet.insert(edge.first);
                    compSet.insert(edge.second);
                }
                std::vector<int> component(compSet.begin(), compSet.end());
                bcc.push_back(component);
            }
        } 
        else if (v != parent[u] && disc[v] < disc[u]) 
        {
            low[u] = std::min(low[u], disc[v]);
            st.push({u, v});
        }
    }
}

std::vector<std::vector<int>> Graph::Biconnected() const 
{
    if (isDirected)
        throw std::runtime_error("Biconnected components are defined only for undirected graphs.");
    
    std::vector<int> disc(n, -1);
    std::vector<int> low(n, -1);
    std::vector<int> parent(n, -1);
    int time = 0;
    std::stack<std::pair<int,int>> st;
    std::vector<std::vector<int>> bcc;
    
    for (int i = 0; i < n; i++) 
    {
        if (disc[i] == -1)
            BCCUtil(i, disc, low, parent, time, st, bcc);
        if (!st.empty()) 
        {
            std::set<int> compSet;
            while (!st.empty()) 
            {
                auto edge = st.top();
                st.pop();
                compSet.insert(edge.first);
                compSet.insert(edge.second);
            }
            std::vector<int> component(compSet.begin(), compSet.end());
            bcc.push_back(component);
        }
    }
    return bcc;
}


// ============================
// Traversal and Path Finding
// ============================

// Breadth-First Search (BFS)
std::vector<int> Graph::BFS(int start, int destination) const 
{
    if (start < 0 || start >= n)
        throw std::out_of_range("Invalid start node identifier.");

    // Initialize visited vector and parent tracker.
    std::vector<bool> visited(n, false);
    std::vector<int> parent(n, -1);
    std::queue<int> q;
    std::vector<int> order;
    bool found = false;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) 
    {
        int u = q.front();
        q.pop();
        order.push_back(u);

        // If destination is reached, we can stop.
        if (u == destination) 
        {
            found = true;
            break;
        }

        // Retrieve u's neighbor list from the adjacency list.
        auto outer = adjacencyList.begin();
        for (int i = 0; i < u; ++i)
            ++outer;
        if (outer == adjacencyList.end())
            throw std::runtime_error("Adjacency list index error.");

        // Enqueue each unvisited neighbor.
        for (auto nbr = outer->begin(); nbr != outer->end(); ++nbr) 
        {
            int v = *nbr;
            if (!visited[v]) 
            {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    // If a destination was specified, reconstruct the path.
    if (destination != -1) 
    {
        if (!found)
            return std::vector<int>();  // No path found.
        std::vector<int> path;
        for (int cur = destination; cur != -1; cur = parent[cur])
            path.push_back(cur);
        std::reverse(path.begin(), path.end());
        return path;
    }
    // Otherwise, return the BFS traversal order.
    return order;
}

// Depth-First Search (DFS)
std::vector<int> Graph::DFS(int start, int destination) const 
{
    if (start < 0 || start >= n)
        throw std::out_of_range("Invalid start node identifier.");

    std::vector<bool> visited(n, false);
    std::vector<int> parent(n, -1);
    std::stack<int> s;
    std::vector<int> order;
    bool found = false;

    s.push(start);
    while (!s.empty()) 
    {
        int u = s.top();
        s.pop();
        if (!visited[u]) 
        {
            visited[u] = true;
            order.push_back(u);
            if (u == destination) 
            {
                found = true;
                break;
            }
            // Retrieve u's neighbor list.
            auto outer = adjacencyList.begin();
            for (int i = 0; i < u; ++i)
                ++outer;
            if (outer == adjacencyList.end())
                throw std::runtime_error("Adjacency list index error.");

            // To simulate recursive DFS order, we collect neighbors
            // and push them in reverse order.
            std::vector<int> neighbors;
            for (auto nbr = outer->begin(); nbr != outer->end(); ++nbr) 
            {
                int v = *nbr;
                if (!visited[v]) 
                {
                    if (parent[v] == -1)  // Record parent if not set.
                        parent[v] = u;
                    neighbors.push_back(v);
                }
            }
            // Push in reverse so that the left-most neighbor is processed first.
            for (int i = static_cast<int>(neighbors.size()) - 1; i >= 0; --i)
            {
                s.push(neighbors[i]);
            }
        }
    }

    if (destination != -1) 
    {
        if (!found)
            return std::vector<int>();  // No path found.
        std::vector<int> path;
        for (int cur = destination; cur != -1; cur = parent[cur])
            path.push_back(cur);
        std::reverse(path.begin(), path.end());
        return path;
    }
    return order;
}

// BFSIterator and DFSIterator
std::vector<int> Graph::BFSIterator(int start) const 
{
    // If no destination is provided, BFS returns the traversal order.
    return BFS(start, -1);
}

std::vector<int> Graph::DFSIterator(int start) const 
{
    return DFS(start, -1);
}

// ======================
// Graph Algorithms
// ======================

// variantToInt is locate before RemoveNode()

// Helper to convert a MIXED_TYPE to double (for weight)
double variantToDouble(const MIXED_TYPE &v) 
{
    if (std::holds_alternative<double>(v))
        return std::get<double>(v);
    if (std::holds_alternative<int>(v))
        return static_cast<double>(std::get<int>(v));
    if (std::holds_alternative<double>(v))
        return static_cast<double>(std::get<double>(v));
    throw std::runtime_error("Variant does not hold a numeric weight.");
}

// Kruskal's algorithm
// We'll implement a basic union-find structure.
class UnionFind 
{
    public:
        std::vector<int> parent;

        UnionFind(int n) : parent(n) 
        {
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int find(int i) 
        {
            if (parent[i] != i)
                parent[i] = find(parent[i]);
            return parent[i];
        }

        void unite(int i, int j) 
        {
            int ri = find(i), rj = find(j);
            if (ri != rj)
                parent[rj] = ri;
        }
};

Graph Graph::Kruskal() 
{
    // We assume the graph is undirected.
    if (isDirected)
        throw std::runtime_error("Kruskal's algorithm requires an undirected graph.");

    // Build a list of edges (each as a tuple: u, v, weight)
    struct Edge { int u, v; double w; };
    std::vector<Edge> edges;

    for (int i = 0; i < edgelist.Length(); i++) 
    {
        std::vector<MIXED_TYPE> edgeVec = edgelist[i];
        int u = variantToInt(edgeVec[0]);
        int v = variantToInt(edgeVec[1]);
        double w = isWeighted ? variantToDouble(edgeVec[2]) : 1.0;
        edges.push_back({u, v, w});
    }

    // Sort edges by weight (ascending)
    std::sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {return a.w < b.w;});

    // Initialize union-find for all nodes.
    UnionFind uf(n);
    Graph mst(n, isWeighted, isDirected);

    // For each edge, if it does not form a cycle, add it.
    for (const auto &e : edges) 
    {
        if (uf.find(e.u) != uf.find(e.v)) 
        {
            uf.unite(e.u, e.v);
            mst.AddEdge(e.u, e.v, e.w);
        }
    }
    return mst;
}

// ====================================----
// Prim's algorithm
// ====================================----
Graph Graph::Prim() 
{
    // We assume undirected graph.
    if (isDirected)
        throw std::runtime_error("Prim's algorithm requires an undirected graph.");

    Graph mst(n, isWeighted, isDirected);
    std::vector<bool> inTree(n, false);
    // Use a priority queue: (weight, u, v) where u is the tree vertex, v is outside.
    typedef std::tuple<double, int, int> PQItem;
    std::priority_queue<PQItem, std::vector<PQItem>, std::greater<PQItem>> pq;
    
    // Start from node 0.
    inTree[0] = true;
    // Push all edges from node 0.
    // To get neighbors, iterate through adjacencyList.
    auto it0 = adjacencyList.begin();
    for (int i = 0; i < 0; i++) 
        ++it0; // already at node 0.

    // We need to find edges from node 0 in edgelist.
    for (int i = 0; i < edgelist.Length(); i++) 
    {
        std::vector<MIXED_TYPE> edgeVec = edgelist[i];
        int u = variantToInt(edgeVec[0]);
        int v = variantToInt(edgeVec[1]);

        if (u == 0 || v == 0) 
        {
            int other = (u == 0) ? v : u;
            double w = isWeighted ? variantToDouble(edgeVec[2]) : 1.0;
            pq.push({w, 0, other});
        }
    }
    while (!pq.empty()) 
    {
        auto [w, u, v] = pq.top();
        pq.pop();
        if (inTree[v])
            continue;
        
        // Add edge (u, v) to MST.
        mst.AddEdge(u, v, w);
        inTree[v] = true;

        // Push all edges from v to outside.
        for (int i = 0; i < edgelist.Length(); i++) 
        {
            std::vector<MIXED_TYPE> edgeVec = edgelist[i];
            int a = variantToInt(edgeVec[0]);
            int b = variantToInt(edgeVec[1]);
            if (a == v || b == v) 
            {
                int other = (a == v) ? b : a;
                if (!inTree[other]) 
                {
                    double w2 = isWeighted ? variantToDouble(edgeVec[2]) : 1.0;
                    pq.push({w2, v, other});
                }
            }
        }
    }
    return mst;
}

// Sollin's (Borůvka's) algorithm
Graph Graph::Sollin() 
{
    // We assume undirected graph.
    if (isDirected)
        throw std::runtime_error("Sollin's algorithm requires an undirected graph.");

    // Initially, each node is its own component.
    std::vector<int> comp(n);
    for (int i = 0; i < n; i++)
        comp[i] = i;

    auto findComp = [&](int i) -> int 
    {
        while (comp[i] != i)
            i = comp[i];
        return i;
    };

    Graph mst(n, isWeighted, isDirected);
    int numComponents = n;
    while (numComponents > 1) 
    {
        // For each component, find the cheapest edge.
        std::vector<std::tuple<int,int,double>> cheapest(n, {-1, -1, std::numeric_limits<double>::infinity()});

        // Iterate over every edge.
        for (int i = 0; i < edgelist.Length(); i++) 
        {
            std::vector<MIXED_TYPE> edgeVec = edgelist[i];
            int u = variantToInt(edgeVec[0]);
            int v = variantToInt(edgeVec[1]);
            double w = isWeighted ? variantToDouble(edgeVec[2]) : 1.0;
            int comp_u = findComp(u);
            int comp_v = findComp(v);

            if (comp_u == comp_v)
                continue;
            // Update cheapest for comp_u.
            if (w < std::get<2>(cheapest[comp_u])) 
            {
                cheapest[comp_u] = {u, v, w};
            }
            // Update cheapest for comp_v.
            if (w < std::get<2>(cheapest[comp_v])) 
            {
                cheapest[comp_v] = {u, v, w};
            }
        }

        // Add the cheapest edges.
        for (int i = 0; i < n; i++) 
        {
            auto [u, v, w] = cheapest[i];
            if (u == -1 || v == -1)
                continue;
            int comp_u = findComp(u);
            int comp_v = findComp(v);
            if (comp_u == comp_v)
                continue;
            mst.AddEdge(u, v, w);
            // Merge the two components.
            comp[comp_v] = comp_u;
            numComponents--;
        }
    }
    return mst;
}

// Dijkstra's algorithm
std::vector<int> Graph::Dijkstra(int source, int destination) 
{
    if (source < 0 || source >= n || destination < 0 || destination >= n)
        throw std::out_of_range("Invalid node identifier.");

    const double INF = std::numeric_limits<double>::infinity();
    std::vector<double> dist(n, INF);
    std::vector<int> parent(n, -1);
    dist[source] = 0.0;

    // Priority queue: (distance, node)
    typedef std::pair<double,int> PDI;
    std::priority_queue<PDI, std::vector<PDI>, std::greater<PDI>> pq;
    pq.push({0.0, source});

    while (!pq.empty()) 
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u])
            continue;
        
        // Get all edges from u.
        for (int i = 0; i < edgelist.Length(); i++) 
        {
            std::vector<MIXED_TYPE> edgeVec = edgelist[i];
            int a = variantToInt(edgeVec[0]);
            int b = variantToInt(edgeVec[1]);
            double w = isWeighted ? variantToDouble(edgeVec[2]) : 1.0;

            // For an undirected graph, consider both directions.
            if (a == u || (!isDirected && b == u)) 
            {
                int v = (a == u) ? b : a;
                if (dist[u] + w < dist[v]) 
                {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
    }
    // Reconstruct the path.
    if (dist[destination] == INF)
        return std::vector<int>();  // No path found.
    std::vector<int> path;

    for (int cur = destination; cur != -1; cur = parent[cur])
        path.push_back(cur);
    std::reverse(path.begin(), path.end());

    return path;
}

// Bellman-Ford algorithm
std::vector<int> Graph::BellmanFord(int source, int destination) 
{
    if (source < 0 || source >= n || destination < 0 || destination >= n)
        throw std::out_of_range("Invalid node identifier.");

    const double INF = std::numeric_limits<double>::infinity();
    std::vector<double> dist(n, INF);
    std::vector<int> parent(n, -1);
    dist[source] = 0.0;

    // Relax all edges n-1 times.
    for (int i = 0; i < n - 1; i++) 
    {
        bool updated = false;
        for (int j = 0; j < edgelist.Length(); j++) 
        {
            std::vector<MIXED_TYPE> edgeVec = edgelist[j];
            int u = variantToInt(edgeVec[0]);
            int v = variantToInt(edgeVec[1]);
            double w = isWeighted ? variantToDouble(edgeVec[2]) : 1.0;
            if (dist[u] != INF && dist[u] + w < dist[v]) 
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
                updated = true;
            }
            // For undirected graphs, also relax (v,u).
            if (!isDirected && dist[v] != INF && dist[v] + w < dist[u]) 
            {
                dist[u] = dist[v] + w;
                parent[u] = v;
                updated = true;
            }
        }
        if (!updated)
            break;
    }

    // Check for negative cycles.
    for (int j = 0; j < edgelist.Length(); j++) 
    {
        std::vector<MIXED_TYPE> edgeVec = edgelist[j];
        int u = variantToInt(edgeVec[0]);
        int v = variantToInt(edgeVec[1]);
        double w = isWeighted ? variantToDouble(edgeVec[2]) : 1.0;
        if (dist[u] != INF && dist[u] + w < dist[v])
            throw std::runtime_error("Graph contains a negative weight cycle");
    }

    // Reconstruct the path.
    if (dist[destination] == INF)
        return std::vector<int>();  // No path found.
    std::vector<int> path;

    for (int cur = destination; cur != -1; cur = parent[cur])
        path.push_back(cur);
    std::reverse(path.begin(), path.end());

    return path;
}

// Floyd's algorithm
std::vector<std::vector<int>> Graph::Floyd() 
{
    // Create a matrix for distances and a predecessor matrix.
    const double INF = std::numeric_limits<double>::infinity();
    std::vector<std::vector<double>> dist(n, std::vector<double>(n, INF));
    std::vector<std::vector<int>> pred(n, std::vector<int>(n, -1));
    
    // Initialize distances: 0 for self, edge weight if edge exists.
    for (int i = 0; i < n; i++) 
    {
        dist[i][i] = 0;
    }

    // For each edge in edgelist:
    for (int i = 0; i < edgelist.Length(); i++) 
    {
        std::vector<MIXED_TYPE> edgeVec = edgelist[i];
        int u = variantToInt(edgeVec[0]);
        int v = variantToInt(edgeVec[1]);
        double w = isWeighted ? variantToDouble(edgeVec[2]) : 1.0;

        dist[u][v] = w;
        pred[u][v] = u;
        if (!isDirected) 
        {
            dist[v][u] = w;
            pred[v][u] = v;
        }
    }
    
    // Floyd–Warshall
    for (int k = 0; k < n; k++) 
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                if (dist[i][k] + dist[k][j] < dist[i][j]) 
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pred[i][j] = pred[k][j];
                }
    
    // Reconstruct paths: for every pair (i,j), reconstruct the path.
    std::vector<std::vector<int>> allPaths(n, std::vector<int>());

    // For simplicity, we return a vector of paths for the pairs (i,j) where i<j.
    std::vector<std::vector<int>> paths;
    for (int i = 0; i < n; i++) 
    {
        for (int j = i+1; j < n; j++) 
        {
            if (dist[i][j] == INF)
                continue; // no path
            
            std::vector<int> path;
            int cur = j;
            while (cur != i) 
            {
                path.push_back(cur);
                cur = pred[i][cur];
            }

            path.push_back(i);
            std::reverse(path.begin(), path.end());
            paths.push_back(path);
        }
    }
    return paths;
}

// ===============================
// Adjacency Matrix Generation
// ===============================

// Helper: convert an edge (a vector of MIXED_TYPE) into its endpoints and weight.
static int getEdgeEndpoint(const std::vector<MIXED_TYPE>& edge, int index) 
{
    // We assume that the endpoint is stored as an int.
    return std::get<int>(edge[index]);
}

static double getEdgeWeight(const std::vector<MIXED_TYPE>& edge, bool isWeighted) 
{
    if (isWeighted && edge.size() >= 3)
        return std::get<double>(edge[2]);
    return 1.0;
}

// Generate the adjacency matrix as a SparseMatrix.
SparseMatrix Graph::AdjMatSparse() const 
{
    // Create a matrix of size n x n.
    SparseMatrix mat = isDirected ? SparseMatrix(n, n, e)
                                  : SparseMatrix(n, n, 2 * e);
    
    // Iterate over all edges in the edge list.
    for (int i = 0; i < edgelist.Length(); i++) 
    {
        std::vector<MIXED_TYPE> edge = edgelist[i];
        int u = getEdgeEndpoint(edge, 0);
        int v = getEdgeEndpoint(edge, 1);
        double weight = getEdgeWeight(edge, isWeighted);

        // Use StoreNum to store the weight (converted to double) at (u, v).
        mat.StoreNum(std::variant<int, double>(static_cast<double>(weight)), u, v);
        // For undirected graphs, also store the symmetric term.
        if (!isDirected)
            mat.StoreNum(std::variant<int, double>(static_cast<double>(weight)), v, u);
    }

    return mat;
}

// Generate the adjacency matrix as a LinkedSparseMatrix.
LinkedSparseMatrix Graph::AdjMatLinked() const 
{
    // Create a LinkedSparseMatrix of size n x n.
    LinkedSparseMatrix mat(n, n);

    // Iterate over all edges.
    for (int i = 0; i < edgelist.Length(); i++) 
    {
        std::vector<MIXED_TYPE> edge = edgelist[i];
        int u = getEdgeEndpoint(edge, 0);
        int v = getEdgeEndpoint(edge, 1);
        double weight = getEdgeWeight(edge, isWeighted);
        // Add the term (u,v,weight).
        mat.StoreNum(weight, u, v);
        // For undirected graphs, also add the symmetric term.
        if (!isDirected)
            mat.StoreNum(weight, v, u);
    }

    return mat;
}


// ======================
// Operator Overloads
// ======================

// Assignment operator (deep copy)
Graph& Graph::operator=(const Graph& other) 
{
    if (this != &other) 
    {
        n = other.n;
        e = other.e;
        isWeighted = other.isWeighted;
        isDirected = other.isDirected;
        nodeVector = other.nodeVector;
        edgelist = other.edgelist;
        adjacencyList = other.adjacencyList;
    }
    return *this;
}

// -------------------------------------------------------------------
// Equality operator.
// Two graphs are equal if they have the same number of nodes, edges,
// type flags, nodeVector, edgelist, and the same adjacency list.
// -------------------------------------------------------------------
bool Graph::operator==(const Graph& other) const 
{
    return (n == other.n &&
            e == other.e &&
            isWeighted == other.isWeighted &&
            isDirected == other.isDirected &&
            nodeVector == other.nodeVector &&
            edgelist == other.edgelist);
}

// Inequality operator
bool Graph::operator!=(const Graph& other) const 
{
    return !(*this == other);
}

// ----------------------------------------------------------------------
// Output stream operator for printing the graph.
// Prints a list of edges. For weighted graphs, each edge is printed as
// {u, v, w}, otherwise as {u, v}.
// ----------------------------------------------------------------------
GeneralArray<std::vector<MIXED_TYPE>> Graph::getEdgeList() const 
{
    return edgelist;
}

std::ostream& operator<<(std::ostream& out, const Graph& graph) 
{
    out << "Graph edges: ";
    // Use getEdgeList() to get a GeneralArray of edge vectors.
    auto edgeList = graph.getEdgeList();  

    for (int i = 0; i < edgeList.Length(); i++) 
    {
        std::vector<MIXED_TYPE> edge = edgeList[i];
        if (graph.isWeighted) 
        {
            // For weighted graphs, assume edge[0] and edge[1] are ints and edge[2] is a double.
            out << "{" 
                << std::get<int>(edge[0]) << ", " 
                << std::get<int>(edge[1]) << ", " 
                << std::get<double>(edge[2]) << "} ";
        } 
        else 
        {
            // For unweighted graphs, only two values.
            out << "{" 
                << std::get<int>(edge[0]) << ", " 
                << std::get<int>(edge[1]) << "} ";
        }
    }
    return out;
}

// ---------------------------------------------------
// Input stream operator for reading a graph.
// Expects input as a series of edge triplets or pairs.
// For example, for a weighted graph: 
//     {0, 1, 1.22} {0, 2, 1.5} {1, 2, 1.4} ...
// For an unweighted graph, the third value is omitted.
// ---------------------------------------------------
std::istream& operator>>(std::istream& in, Graph& graph) 
{
    // In this implementation we assume that reading an edge will
    // automatically add the edge to the graph via AddEdge().
    // The operator reads until the stream is exhausted.
    char ch;
    while (in >> ch) 
    {
        if (ch == '{') 
        {
            int u, v;
            double w = 1; // default weight

            in >> u >> ch; // read u then comma (ch should be ',')
            in >> v;
            if (graph.isWeighted) 
            {
                in >> ch; // read comma
                in >> w;
            }
            in >> ch; // read closing '}'

            graph.AddEdge(u, v, w);
        }
    }
    return in;
}
