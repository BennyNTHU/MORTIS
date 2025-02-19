#ifndef MULTIGRAPH
#define MULTIGRAPH

#include <vector>

#include "../../array/GeneralArray/GeneralArray.hpp"

using MIXED_TYPE = std::variant<int, char, float, bool, double, std::string>;

/**
 * @brief MultiGraph data structure (support for multiple edges).
 *
 * Each node is represented by an integer. Edges are stored as triples {u, v, w} where:
 * - u: source node,
 * - v: destination node,
 * - w: edge weight (if the multigraph is unweighted, w is always forced to 1).
 *
 * The multigraph can operate in both weighted and unweighted modes, and can be either directed or undirected.
 * In an undirected multigraph, the edge {u, v, w} is considered identical to {v, u, w}.
 */

using MIXED_TYPE = std::variant<int, char, float, bool, double, std::string>;

class MultiGraph 
{
    private:
        int n;                       // Number of vertices.
        int e;                       // Number of edges.
        std::vector<int> nodeVector; // List of node identifiers.
        GeneralArray<std::vector<MIXED_TYPE>> edgelist;
        bool isWeighted;  // If true, edges carry weights (otherwise, weight is forced to 1).
        bool isDirected;  // If true, the multigraph is directed; otherwise, it is undirected.

    public:
        // Constructors and Destructor
        MultiGraph();   // Creates an empty unweighted and undirected multigraph
        MultiGraph(int numNodes, bool weighted = false, bool directed = false);                     // Constructor with a specified number of nodes
        MultiGraph(const std::vector<int>& nodes, bool weighted = false, bool directed = false);    // Constructor from a vector of node identifiers.
        ~MultiGraph();  // Destructor.

        // Modification Methods (Add/Remove)
        void AddNode(int node);                     //Add a new node to the multigraph.
        void RemoveNode(int node);                  // Remove a node and all its incident edges from the multigraph.
        void AddEdge(int u, int v, double w = 1);   // Add an edge to the multigraph. w The weight (default is 1).
        void RemoveEdge(int u, int v);              // Remove an edge from the multigraph.

        // Global Properties
        bool IsEmpty() const;                 // True if there are no nodes in the multigraph
        bool isEulerian() const;              // if a multigraph is Eulerian
        int NumberOfNodes() const;            // Get the total number of nodes
        int NumberOfEdges() const;            // Get the total number of edges

        // Local Properties
        int Degree(int u) const;              // Get the degree of node u
        int EdgeCount(int u, int v) const;    // Number of edges from node u to node v

        // Operator Overloads
        MultiGraph& operator=(const MultiGraph& other); // Assignment operator (deep copy)
        bool operator==(const MultiGraph& other) const; // equal if they have the same structure and edge weights
        bool operator!=(const MultiGraph& other) const; // True if the multigraphs are not identical.
        friend std::ostream& operator<<(std::ostream& out, const MultiGraph& multigraph);   // printed as a list of edge triplets {u, v, w}
        friend std::istream& operator>>(std::istream& in, MultiGraph& multigraph);          // input in the form of edge triplets {u, v, w}
};

#endif
