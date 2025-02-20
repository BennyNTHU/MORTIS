#include <vector>
#include "MultiGraph.hpp"

// ================================
// Constructors and Destructor
// ================================

// Default constructor: creates an empty unweighted, undirected multigraph.
MultiGraph::MultiGraph(): n(0), e(0), isWeighted(false), isDirected(false), nodeVector(), edgelist() {}

// Constructor with a specified number of nodes.
// Initializes nodeVector with nodes 0, 1, ..., numNodes-1.
MultiGraph::MultiGraph(int numNodes, bool weighted, bool directed): n(numNodes), e(0), 
                       isWeighted(weighted), isDirected(directed), nodeVector(), edgelist() 
{
    // Create nodes 0 through numNodes-1.
    nodeVector.resize(n);
    for (int i = 0; i < n; i++) 
    {
        nodeVector[i] = i;
    }
    // edgelist remains empty.
}

// Constructor from a vector of node identifiers.
MultiGraph::MultiGraph(const std::vector<int>& nodes, bool weighted, bool directed)
    : n(nodes.size()), e(0), isWeighted(weighted), isDirected(directed), nodeVector(nodes), edgelist() {}

// Destructor.
MultiGraph::~MultiGraph() {}    // Standard containers (nodeVector, edgelist) clean themselves up.

// ================================
// Modification Methods
// ================================

// AddNode: adds a new node. If it already exists, throw an error.
void MultiGraph::AddNode(int node) 
{
    if (std::find(nodeVector.begin(), nodeVector.end(), node) != nodeVector.end())
        throw std::invalid_argument("Node already exists.");
    
    nodeVector.push_back(node);
    n++;    // (edgelist remains unchanged.)
}

// RemoveNode: remove the node and all incident edges.
void MultiGraph::RemoveNode(int node) 
{
    // Remove node from nodeVector.
    auto it = std::find(nodeVector.begin(), nodeVector.end(), node);
    if (it == nodeVector.end())
        throw std::invalid_argument("Node does not exist.");
    nodeVector.erase(it);
    n--;

    // Rebuild edgelist without any edge incident to 'node'.
    GeneralArray<std::vector<MIXED_TYPE>> newEdgeList;

    for (int i = 0; i < edgelist.Length(); i++) 
    {
        std::vector<MIXED_TYPE> edge = edgelist[i];
        // Get endpoints using a helper (here we assume that the endpoints are stored as ints).
        // We use std::get<int> safely since our graph stores integer node IDs.
        int u = std::get<int>(edge[0]);
        int v = std::get<int>(edge[1]);
        if (u == node || v == node)
            continue; // skip this edge
        newEdgeList.Push_back(edge);
    }

    edgelist = newEdgeList;
    e = edgelist.Length();
}

// AddEdge: add an edge from u to v with weight w (w forced to 1 if unweighted).
void MultiGraph::AddEdge(int u, int v, double w) 
{
    // Verify that both nodes exist.
    if (std::find(nodeVector.begin(), nodeVector.end(), u) == nodeVector.end() ||
        std::find(nodeVector.begin(), nodeVector.end(), v) == nodeVector.end())
    {
        throw std::invalid_argument("One or both nodes do not exist.");
    }
    // For unweighted graphs, force weight to 1.
    if (!isWeighted)
        w = 1;
    
    // Build the edge vector.
    std::vector<MIXED_TYPE> edgeVec;
    edgeVec.push_back(u);
    edgeVec.push_back(v);
    if (isWeighted)
        edgeVec.push_back(w);
    
    // Append the edge to the edgelist.
    edgelist.Push_back(edgeVec);
    e++;
}

// RemoveEdge: remove one occurrence of an edge from u to v.
// (For an undirected multigraph, an edge (u,v) is considered identical to (v,u).)
void MultiGraph::RemoveEdge(int u, int v) 
{
    // We do not need to verify existence of nodes here because we simply remove matching edges.
    // Rebuild edgelist excluding the first occurrence of an edge connecting u and v.
    bool removed = false;
    GeneralArray<std::vector<MIXED_TYPE>> newEdgeList;

    for (int i = 0; i < edgelist.Length(); i++) 
    {
        std::vector<MIXED_TYPE> edge = edgelist[i];
        int a = std::get<int>(edge[0]);
        int b = std::get<int>(edge[1]);
        bool match = false;

        if (isDirected) 
        {
            if (a == u && b == v)
                match = true;
        } 
        else 
        {
            if ((a == u && b == v) || (a == v && b == u))
                match = true;
        }
        if (match && !removed) 
        {
            removed = true;  // remove only one occurrence
            continue;
        }
        newEdgeList.Push_back(edge);
    }
    if (removed) 
    {
        edgelist = newEdgeList;
        e = edgelist.Length();
    } 
    else 
    {
        throw std::invalid_argument("Edge does not exist.");
    }
}

// ================================
// Global Properties
// ================================

// IsEmpty: returns true if there are no nodes.
bool MultiGraph::IsEmpty() const 
{
    return nodeVector.empty();
}

// Additional functions: isEulerian and isHamilton.
// (These are usually NP-hard; here we implement simple criteria.)

// isEulerian: For undirected graph, Eulerian if every node has even degree.
// For directed graph, Eulerian if for every node, indegree equals outdegree.
bool MultiGraph::isEulerian() const 
{
    if (IsEmpty())
        return false;
    
    if (!isDirected) 
    {
        // Check that every node has even degree.
        for (int node : nodeVector) 
        {
            if (Degree(node) % 2 != 0)
                return false;
        }
        return true;
    } 
    else 
    {
        // For directed: compute indegree and outdegree.
        std::vector<int> indegree(n, 0), outdegree(n, 0);

        for (int i = 0; i < edgelist.Length(); i++) 
        {
            std::vector<MIXED_TYPE> edge = edgelist[i];
            int u = std::get<int>(edge[0]);
            int v = std::get<int>(edge[1]);
            outdegree[u]++;
            indegree[v]++;
        }
        for (int i = 0; i < n; i++) 
        {
            if (indegree[i] != outdegree[i])
                return false;
        }
        return true;
    }
}

int MultiGraph::NumberOfNodes() const 
{
    return n;
}

int MultiGraph::NumberOfEdges() const 
{
    return e;
}

// ================================
// Local Properties
// ================================

// Degree: returns the degree of node u.
// For directed graphs, degree is outdegree + indegree.
int MultiGraph::Degree(int u) const 
{
    // Verify that u exists.
    if (std::find(nodeVector.begin(), nodeVector.end(), u) == nodeVector.end())
        throw std::invalid_argument("Node does not exist.");

    int deg = 0;

    for (int i = 0; i < edgelist.Length(); i++) 
    {
        std::vector<MIXED_TYPE> edge = edgelist[i];
        int a = std::get<int>(edge[0]);
        int b = std::get<int>(edge[1]);
        if (isDirected) 
        {
            if (a == u) deg++;       // out edge
            if (b == u) deg++;       // in edge
        } 
        else 
        {
            if (a == u || b == u)
                deg++; // each edge incident to u
        }
    }

    return deg;
}

// EdgeCount: returns the number of edges between u and v.
// For undirected graphs, count both (u,v) and (v,u) as the same.
int MultiGraph::EdgeCount(int u, int v) const 
{
    int count = 0;

    for (int i = 0; i < edgelist.Length(); i++) 
    {
        std::vector<MIXED_TYPE> edge = edgelist[i];
        int a = std::get<int>(edge[0]);
        int b = std::get<int>(edge[1]);

        if (isDirected)
        {
            if (a == u && b == v)
                count++;
        } 
        else 
        {
            if ((a == u && b == v) || (a == v && b == u))
                count++;
        }
    }

    return count;
}

// ================================
// Operator Overloads
// ================================

MultiGraph& MultiGraph::operator=(const MultiGraph& other) 
{
    if (this != &other) 
    {
        n = other.n;
        e = other.e;
        isWeighted = other.isWeighted;
        isDirected = other.isDirected;
        nodeVector = other.nodeVector;
        edgelist = other.edgelist;
    }

    return *this;
}

bool MultiGraph::operator==(const MultiGraph& other) const 
{
    return (n == other.n &&
            e == other.e &&
            isWeighted == other.isWeighted &&
            isDirected == other.isDirected &&
            nodeVector == other.nodeVector &&
            edgelist == other.edgelist);
}

bool MultiGraph::operator!=(const MultiGraph& other) const 
{
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const MultiGraph& mg) 
{
    out << "MultiGraph edges: ";
    // Print every edge in the edgelist.
    // For weighted graphs, print {u, v, w}; for unweighted, {u, v}.

    for (int i = 0; i < mg.edgelist.Length(); i++) 
    {
        std::vector<MIXED_TYPE> edge = mg.edgelist[i];
        out << "{";
        out << std::get<int>(edge[0]) << ", " << std::get<int>(edge[1]);
        if (mg.isWeighted && edge.size() >= 3)
            out << ", " << std::get<double>(edge[2]);
        out << "} ";
    }

    return out;
}

std::istream& operator>>(std::istream& in, MultiGraph& mg) 
{
    // Input format: a list of edge triplets in the form {u,v,w} (or {u,v} for unweighted).
    // For simplicity, we assume that the input is given as:
    //   {u,v,w} {u,v,w} ... 
    // and that nodes and weight are separated by commas.
    char ch;

    while (in >> ch) 
    {
        if (ch != '{')
            break;

        int u, v;
        double w = 1;

        in >> u >> ch; // read comma
        in >> v;
        in >> ch; // either comma or '}'

        if (mg.isWeighted && ch == ',') 
        {
            in >> w;
            in >> ch; // read the closing '}'
        } 
        else if (ch != '}') // Skip to the end of the edge specification.
        {
            while (ch != '}' && in >> ch) {}
        }
        mg.AddEdge(u, v, w);
    }
    return in;
}
