#ifndef GRAPH
#define GRAPH

#include <vector>
#include <stdexcept>
#include <iterator> 
#include <list>
#include <stack>

#include "../../array/GeneralArray/GeneralArray.hpp"
#include "../../array/SparseMatrix/SparseMatrix.hpp"
#include "../../chain/LinkedSparseMatrix/LinkedSparseMatrix.hpp"
#include "../../chain/DoublyLinkedList/DoublyLinkedList.hpp"

using MIXED_TYPE = std::variant<int, char, float, bool, double, std::string>;

/**
 * @brief Graph data structure (without support for multiple edges).
 *
 * Each node is represented by an integer. Edges are stored as triples {u, v, w} where:
 * - u: source node,
 * - v: destination node,
 * - w: edge weight (if the graph is unweighted, w is always forced to 1).
 *
 * The graph can operate in both weighted and unweighted modes, and can be either directed or undirected.
 * In an undirected graph, the edge {u, v, w} is considered identical to {v, u, w}.
 *
 * The graph is stored using an adjacency matrix (via either SparseMatrix or LinkedSparseMatrix)
 * while also maintaining a vector of node IDs and a vector of edges (for convenience).
 */

class Graph 
{
    private:
        int n;   // Number of vertices.
        int e;   // Number of edges.
        std::vector<int> nodeVector; // List of node identifiers.
        GeneralArray<std::vector<MIXED_TYPE>> edgelist;
        DoublyLinkedList<DoublyLinkedList<int>> adjacencyList;    // The adjacency list reprecentation of a graph
        bool isWeighted;  // If true, edges carry weights (otherwise, weight is forced to 1).
        bool isDirected;  // If true, the graph is directed; otherwise, it is undirected.

        // helper function for finding biconnected part
        GeneralArray<std::vector<MIXED_TYPE>> getEdgeList() const;
        void BCCUtil(int u, std::vector<int>& disc, std::vector<int>& low,
            std::vector<int>& parent, int& time,
            std::stack<std::pair<int,int>>& st,
            std::vector<std::vector<int>>& bcc) const;

    public:
        // ==================================================
        // Constructors and Destructor
        // ==================================================

        /**
         * @brief Default constructor.
         *
         * Creates an empty graph. By default, the graph is unweighted and undirected.
         */
        Graph();

        /**
         * @brief Constructor with a specified number of nodes.
         *
         * Initializes the graph with nodes labeled 0 through numNodes-1.
         *
         * @param numNodes Number of nodes.
         * @param weighted True if the graph should be weighted (default false).
         * @param directed True if the graph should be directed (default false).
         */
        Graph(int numNodes, bool weighted = false, bool directed = false);

        /**
         * @brief Constructor from a vector of node identifiers.
         *
         * @param nodes A vector of node IDs.
         * @param weighted True if the graph should be weighted (default false).
         * @param directed True if the graph should be directed (default false).
         */
        Graph(const std::vector<int>& nodes, bool weighted = false, bool directed = false);

        /**
         * @brief Destructor.
         */
        ~Graph();

        // ==================================================
        // Modification Methods (Add/Remove)
        // ==================================================

        /**
         * @brief Add a new node to the graph.
         *
         * @param node The node identifier to add.
         */
        void AddNode(int node);

        /**
         * @brief Remove a node and all its incident edges from the graph.
         *
         * @param node The node identifier to remove.
         */
        void RemoveNode(int node);

        /**
         * @brief Add an edge to the graph.
         *
         * Adds an edge from u to v with weight w. For unweighted graphs, w is forced to 1.
         *
         * @param u The source node.
         * @param v The destination node.
         * @param w The weight (default is 1).
         */
        void AddEdge(int u, int v, double w = 1);

        /**
         * @brief Remove an edge from the graph.
         *
         * @param u The source node.
         * @param v The destination node.
         */
        void RemoveEdge(int u, int v);

        // ==================================================
        // Accessor Methods (Properties)
        // ==================================================

        /**
         * @brief Check if the graph is empty.
         * @return True if there are no nodes in the graph.
         */
        bool IsEmpty() const;

        /**
         * @brief Get the degree of node u.
         *
         * For directed graphs, the degree is the sum of in-degree and out-degree.
         *
         * @param u Node identifier.
         * @return The degree of node u.
         */
        int Degree(int u) const;

        /**
         * @brief Determine whether an edge exists from node u to node v.
         *
         * For undirected graphs, (u, v) and (v, u) are considered identical.
         *
         * @param u The source node.
         * @param v The destination node.
         * @return True if the edge exists.
         */
        bool ExistsEdge(int u, int v) const;

        /**
         * @brief Get the total number of nodes.
         * @return Number of nodes.
         */
        int NumberOfNodes() const;

        /**
         * @brief Get the total number of edges.
         * @return Number of edges.
         */
        int NumberOfEdges() const;

        // ==================================================
        // Spanning Tree and Component Methods
        // ==================================================

        /**
         * @brief Compute a spanning tree of the graph.
         *
         * @return A Graph object representing the spanning tree.
         */
        Graph SpanningTree() const;

        /**
         * @brief Compute the connected components of the graph.
         *
         * @return A vector of vectors, where each inner vector contains the node IDs of a connected component.
         */
        std::vector<std::vector<int>> Components() const;

        /**
         * @brief Compute the biconnected components of the graph.
         *
         * @return A vector of vectors, where each inner vector contains the node IDs of a biconnected component.
         */
        std::vector<std::vector<int>> Biconnected() const;

        // ==================================================
        // Traversal and Path Finding
        // ==================================================

        /**
         * @brief Perform a Breadth-First Search (BFS) from a starting node to a destination node.
         *
         * If no destination is specified (destination = -1), BFS returns the order of traversal.
         *
         * @param start The starting node identifier (default is the first node in nodeVector).
         * @param destination The destination node identifier (-1 if not specified).
         * @return A vector of node identifiers representing the BFS path.
         */
        std::vector<int> BFS(int start = 0, int destination = -1) const;

        /**
         * @brief Perform a Depth-First Search (DFS) from a starting node to a destination node.
         *
         * If no destination is specified (destination = -1), DFS returns the order of traversal.
         *
         * @param start The starting node identifier (default is the first node in nodeVector).
         * @param destination The destination node identifier (-1 if not specified).
         * @return A vector of node identifiers representing the DFS path.
         */
        std::vector<int> DFS(int start = 0, int destination = -1) const;

        /**
         * @brief Get an iterator (vector) of node IDs in BFS order.
         *
         * @param start The starting node identifier.
         * @return A vector of node identifiers in BFS order.
         */
        std::vector<int> BFSIterator(int start = 0) const;

        /**
         * @brief Get an iterator (vector) of node IDs in DFS order.
         *
         * @param start The starting node identifier.
         * @return A vector of node identifiers in DFS order.
         */
        std::vector<int> DFSIterator(int start = 0) const;

        // ==================================================
        // Graph Algorithms
        // ==================================================

        /**
         * @brief Compute the minimum spanning tree using Kruskal's algorithm.
         *
         * @return A Graph object representing the minimum spanning tree.
         */
        Graph Kruskal();

        /**
         * @brief Compute the minimum spanning tree using Prim's algorithm.
         *
         * @return A Graph object representing the minimum spanning tree.
         */
        Graph Prim();

        /**
         * @brief Compute the minimum spanning tree using Sollin's algorithm.
         *
         * @return A Graph object representing the minimum spanning tree.
         */
        Graph Sollin();

        /**
         * @brief Compute the shortest path from a source to a destination using Dijkstra's algorithm.
         *
         * @param source The source node identifier.
         * @param destination The destination node identifier.
         * @return A vector of node IDs representing the shortest path.
         */
        std::vector<int> Dijkstra(int source, int destination);

        /**
         * @brief Compute the shortest path from a source to a destination using the Bellman-Ford algorithm.
         *
         * @param source The source node identifier.
         * @param destination The destination node identifier.
         * @return A vector of node IDs representing the shortest path.
         */
        std::vector<int> BellmanFord(int source, int destination);

        /**
         * @brief Compute the shortest paths between all pairs of nodes using Floyd's algorithm.
         *
         * @return A two-dimensional vector, where each inner vector represents the shortest path between a pair of nodes.
         */
        std::vector<std::vector<int>> Floyd();

        // ==================================================
        // Adjacency Matrix Generation
        // ==================================================

        /**
         * @brief Generate the adjacency matrix as a SparseMatrix.
         *
         * @return A SparseMatrix representing the graph.
         */
        SparseMatrix AdjMatSparse() const;

        /**
         * @brief Generate the adjacency matrix as a LinkedSparseMatrix.
         *
         * @return A LinkedSparseMatrix representing the graph.
         */
        LinkedSparseMatrix AdjMatLinked() const;

        // ==================================================
        // Operator Overloads
        // ==================================================

        /**
         * @brief Assignment operator (deep copy).
         */
        Graph& operator=(const Graph& other);

        /**
         * @brief Equality operator.
         *
         * Two graphs are considered equal if they have the same structure and edge weights.
         */
        bool operator==(const Graph& other) const;

        /**
         * @brief Inequality operator.
         *
         * @return True if the graphs are not identical.
         */
        bool operator!=(const Graph& other) const;

        /**
         * @brief Output stream operator for printing the graph.
         *
         * The graph is printed as a list of edge triplets {u, v, w}.
         *
         * @param out Output stream.
         * @param graph The graph to print.
         * @return The output stream.
         */
        friend std::ostream& operator<<(std::ostream& out, const Graph& graph);

        /**
         * @brief Input stream operator for reading a graph.
         *
         * Expects input in the form of edge triplets {u, v, w}.
         *
         * @param in Input stream.
         * @param graph The graph to populate.
         * @return The input stream.
         */
        friend std::istream& operator>>(std::istream& in, Graph& graph);
};

#endif