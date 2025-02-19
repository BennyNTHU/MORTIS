#include "Graph.hpp"
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <vector>

// -------------------------
// Constructors and Destructor
// -------------------------

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
    for (int i = 0; i < n; i++) {
        nodeVector[i] = i;
    }
    
    // Build the adjacency list: for each node, create an empty inner list.
    // (We assume that DoublyLinkedList has a default constructor and an InsertBack() method.)
    while (!adjacencyList.IsEmpty()) {
        adjacencyList.DeleteFront();
    }
    for (int i = 0; i < n; i++) {
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
    while (!adjacencyList.IsEmpty()) {
        adjacencyList.DeleteFront();
    }
    for (size_t i = 0; i < nodeVector.size(); i++) {
        DoublyLinkedList<int> emptyList;
        adjacencyList.InsertBack(emptyList);
    }
    // edgelist remains empty.
}

// Destructor.
Graph::~Graph() {
    // Clear nodeVector.
    nodeVector.clear();
    
    // Clear the adjacency list.
    while (!adjacencyList.IsEmpty()) {
        adjacencyList.DeleteFront();
    }
    // edgelist is destroyed by its own destructor.
}


// ==================================================
// Modification Methods (Add/Remove)
// ==================================================

// ------------------------------
// AddNode: add a new node
// ------------------------------
void Graph::AddNode(int node) {
    // If node already exists, throw.
    if (std::find(nodeVector.begin(), nodeVector.end(), node) != nodeVector.end())
        throw std::invalid_argument("Node already exists.");
    // Append the new node.
    nodeVector.push_back(node);
    n++;
    // Append a new, empty inner list to the adjacency list.
    DoublyLinkedList<int> emptyList;
    adjacencyList.InsertBack(emptyList);
    // (The edgelist remains unchanged.)
}

// ------------------------------
// RemoveNode: remove a node and all its incident edges
// ------------------------------

// Helper function to convert MIXED_TYPE (a std::variant) to int.
// You can expand this if you want to support other types.
int variantToInt(const MIXED_TYPE &v) {
    // This will throw std::bad_variant_access if v is not holding an int.
    return std::get<int>(v);
}

void Graph::RemoveNode(int node) {
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
    for (int i = 0; i < edgelist.length(); i++) {
        std::vector<MIXED_TYPE> edge = edgelist[i];
        // For a weighted graph, edge size should be 3; for unweighted, size 2.
        // If either u or v equals the removed node, skip it.
        if ((variantToInt(edge[0]) == node) || (variantToInt(edge[1]) == node))
            continue;
        newEdgeList.push_back(edge);
    }
    edgelist = newEdgeList;
    e = edgelist.length();
    
    // Also, remove the node from every inner list in adjacencyList.
    for (auto outerIt = adjacencyList.begin(); outerIt != adjacencyList.end(); ++outerIt) {
        // Since *outerIt is returned as const, cast away const.
        DoublyLinkedList<int>& innerList = const_cast<DoublyLinkedList<int>&>(*outerIt);
        // Remove all occurrences of 'node' in this inner list.
        // We iterate by index; collect indices to remove then delete them in reverse order.
        std::vector<int> indicesToRemove;
        int pos = 0;
        for (auto innerIt = innerList.begin(); innerIt != innerList.end(); ++innerIt, pos++) {
            if (*innerIt == node)
                indicesToRemove.push_back(pos);
        }
        for (int i = indicesToRemove.size() - 1; i >= 0; i--) {
            innerList.Delete(indicesToRemove[i]);
        }
    }
}

// ------------------------------
// AddEdge: add an edge from u to v with weight w (w forced to 1 if unweighted)
// ------------------------------
void Graph::AddEdge(int u, int v, double w) {
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
    edgelist.push_back(edgeVec);
    
    // Update the adjacency list:
    // For node u, add v.
    int index_u = std::distance(nodeVector.begin(), it_u);
    auto outerIt = adjacencyList.begin();
    for (int i = 0; i < index_u; ++i)
        ++outerIt;
    // Insert v into the inner list. (Cast away const if needed.)
    const_cast<DoublyLinkedList<int>&>(*outerIt).InsertBack(v);
    
    // For undirected graphs, also add u to v's inner list.
    if (!isDirected) {
        int index_v = std::distance(nodeVector.begin(), it_v);
        auto outerIt2 = adjacencyList.begin();
        for (int i = 0; i < index_v; ++i)
            ++outerIt2;
        const_cast<DoublyLinkedList<int>&>(*outerIt2).InsertBack(u);
    }
    
    e++;
}

// ------------------------------
// RemoveEdge: remove an edge from the graph
// ------------------------------
void Graph::RemoveEdge(int u, int v) {
    // Verify that both nodes exist.
    auto it_u = std::find(nodeVector.begin(), nodeVector.end(), u);
    auto it_v = std::find(nodeVector.begin(), nodeVector.end(), v);
    if (it_u == nodeVector.end() || it_v == nodeVector.end())
        throw std::invalid_argument("One or both nodes do not exist.");
    
    // Rebuild the edgelist without the edge (u,v) (and for undirected graphs, (v,u)).
    GeneralArray<std::vector<MIXED_TYPE>> newEdgeList;
    for (int i = 0; i < edgelist.length(); i++) {
        std::vector<MIXED_TYPE> edge = edgelist[i];
        bool removeEdge = false;
        if (isWeighted) {
            // For weighted graphs, edge vector: {u, v, weight}
            if ((variantToInt(edge[0]) == u && variantToInt(edge[1]) == v) ||
                (!isDirected && variantToInt(edge[0]) == v && variantToInt(edge[1]) == u))
                removeEdge = true;
        } else {
            // For unweighted graphs, edge vector: {u, v}
            if ((variantToInt(edge[0]) == u && variantToInt(edge[1]) == v) ||
                (!isDirected && variantToInt(edge[0]) == v && variantToInt(edge[1]) == u))
                removeEdge = true;
        }
        if (!removeEdge)
            newEdgeList.push_back(edge);
    }
    edgelist = newEdgeList;
    e = edgelist.length();
    
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
            if (*innerIt == v) {
                innerList.Delete(pos);
                break;
            }
        }
    }
    
    // For undirected graphs, remove u from v's neighbor list.
    if (!isDirected) {
        int index_v = std::distance(nodeVector.begin(), it_v);
        auto outerIt2 = adjacencyList.begin();
        for (int i = 0; i < index_v; ++i)
            ++outerIt2;
        {
            DoublyLinkedList<int>& innerList = const_cast<DoublyLinkedList<int>&>(*outerIt2);
            int pos = 0;
            for (auto innerIt = innerList.begin(); innerIt != innerList.end(); ++innerIt, pos++) {
                if (*innerIt == u) {
                    innerList.Delete(pos);
                    break;
                }
            }
        }
    }
}

