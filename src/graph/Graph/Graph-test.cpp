// GraphTest.cpp
// Compile with (for example):
// g++ -std=c++17 GraphTest.cpp ../BinaryTree/BinaryTree.cpp ../BinaryTreeNode/BinaryTreeNode.cpp \
//     ../../array/SparseMatrix/SparseMatrix.cpp ../../chain/LinkedSparseMatrix/LinkedSparseMatrix.cpp \
//     -o GraphTest

#include <iostream>
#include <vector>

#include "Graph.hpp"
#include "../../array/SparseMatrix/SparseMatrix.hpp"
#include "../../chain/LinkedSparseMatrix/LinkedSparseMatrix.hpp"

using namespace std;

int main() 
{
    cout << "=== Graph Test Program ===" << endl << endl;

    // ==================================================
    // Construct Graph
    // ==================================================
    // Create a weighted, undirected graph with 5 nodes (0 through 4).
    Graph<int> g(5, true, false);

    cout << "Initial Graph:" << endl;
    cout << " - Number of nodes: " << g.NumberOfNodes() << endl;
    cout << " - Number of edges: " << g.NumberOfEdges() << endl;
    cout << " - Is graph empty? " << (g.IsEmpty() ? "Yes" : "No") << endl << endl;

    // Add a new node (node 5) using AddNode.
    g.AddNode(5);
    cout << "After adding node 5:" << endl;
    cout << " - Number of nodes: " << g.NumberOfNodes() << endl << endl;

    // ==================================================
    // Add Edges
    // ==================================================
    // Add several edges with specified weights.
    g.AddEdge(0, 1, 10);
    g.AddEdge(0, 2, 20);
    g.AddEdge(1, 2, 30);
    g.AddEdge(1, 3, 40);
    g.AddEdge(2, 4, 50);
    g.AddEdge(3, 4, 60);
    g.AddEdge(3, 0, 70); // For undirected graphs, this edge is equivalent to edge (0,3).

    cout << "After adding edges:" << endl;
    cout << " - Number of edges: " << g.NumberOfEdges() << endl;
    cout << endl;

    // ==================================================
    // Degree and Edge Existence
    // ==================================================
    for (int i = 0; i < g.NumberOfNodes(); i++) {
        cout << "Degree of node " << i << ": " << g.Degree(i) << endl;
    }
    cout << endl;
    
    cout << "Edge exists between 0 and 1? " << (g.ExistsEdge(0,1) ? "Yes" : "No") << endl;
    cout << "Edge exists between 2 and 3? " << (g.ExistsEdge(2,3) ? "Yes" : "No") << endl;
    cout << endl;

    // ==================================================
    // Traversal: BFS and DFS with Path Return
    // ==================================================
    // Perform BFS and DFS from node 0 to node 4.
    vector<int> bfsPath = g.BFS(0, 4);
    cout << "BFS path from 0 to 4: ";
    for (int node : bfsPath) {
        cout << node << " ";
    }
    cout << endl;
    
    vector<int> dfsPath = g.DFS(0, 4);
    cout << "DFS path from 0 to 4: ";
    for (int node : dfsPath) {
        cout << node << " ";
    }
    cout << endl << endl;

    // ==================================================
    // Traversal Iterators: Full BFS/DFS Order
    // ==================================================
    vector<int> bfsOrder = g.BFSIterator(0);
    cout << "BFS traversal order starting at 0: ";
    for (int node : bfsOrder) {
        cout << node << " ";
    }
    cout << endl;
    
    vector<int> dfsOrder = g.DFSIterator(0);
    cout << "DFS traversal order starting at 0: ";
    for (int node : dfsOrder) {
        cout << node << " ";
    }
    cout << endl << endl;

    // ==================================================
    // Spanning Tree and Components
    // ==================================================
    Graph<int> spanningTree = g.SpanningTree();
    cout << "Spanning Tree (edge list):" << endl;
    cout << spanningTree << endl;

    vector<vector<int>> components = g.Components();
    cout << "Connected Components:" << endl;
    for (size_t i = 0; i < components.size(); i++) {
        cout << "  Component " << i << ": ";
        for (int node : components[i])
            cout << node << " ";
        cout << endl;
    }
    cout << endl;

    vector<vector<int>> bicomps = g.Biconnected();
    cout << "Biconnected Components:" << endl;
    for (size_t i = 0; i < bicomps.size(); i++) {
        cout << "  Component " << i << ": ";
        for (int node : bicomps[i])
            cout << node << " ";
        cout << endl;
    }
    cout << endl;

    // ==================================================
    // Adjacency Matrix Generation
    // ==================================================
    SparseMatrix<int> adjMatSparse = g.AdjMatSparse();
    cout << "Adjacency Matrix (SparseMatrix):" << endl;
    cout << adjMatSparse << endl;

    LinkedSparseMatrix<int> adjMatLinked = g.AdjMatLinked();
    cout << "Adjacency Matrix (LinkedSparseMatrix):" << endl;
    cout << adjMatLinked << endl;

    // ==================================================
    // Minimum Spanning Tree Algorithms
    // ==================================================
    Graph<int> mstKruskal = g.Kruskal();
    cout << "Minimum Spanning Tree (Kruskal's algorithm):" << endl;
    cout << mstKruskal << endl;

    Graph<int> mstPrim = g.Prim();
    cout << "Minimum Spanning Tree (Prim's algorithm):" << endl;
    cout << mstPrim << endl;

    Graph<int> mstSollin = g.Sollin();
    cout << "Minimum Spanning Tree (Sollin's algorithm):" << endl;
    cout << mstSollin << endl;

    // ==================================================
    // Shortest Path Algorithms
    // ==================================================
    vector<int> dijkstraPath = g.Dijkstra(0, 4);
    cout << "Shortest path from 0 to 4 (Dijkstra's algorithm): ";
    for (int node : dijkstraPath)
        cout << node << " ";
    cout << endl;

    vector<int> bellmanPath = g.BellmanFord(0, 4);
    cout << "Shortest path from 0 to 4 (Bellman-Ford algorithm): ";
    for (int node : bellmanPath)
        cout << node << " ";
    cout << endl;

    vector<vector<int>> floydPaths = g.Floyd();
    cout << "All-pairs shortest paths (Floyd's algorithm):" << endl;
    for (const auto& row : floydPaths) {
        for (int dist : row)
            cout << dist << " ";
        cout << endl;
    }
    cout << endl;

    // ==================================================
    // I/O Operators
    // ==================================================
    // Print the graph using the overloaded << operator.
    cout << "Graph printed using << operator:" << endl;
    cout << g << endl;

    // (Optionally, you can test >> operator if you implement it to read graph data from input)

    cout << "=== End of Graph Test Program ===" << endl;
    return 0;
}
