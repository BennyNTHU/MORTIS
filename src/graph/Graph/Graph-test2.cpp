// Graph-algorithms-test.cpp
// Compile with (for example):
// g++ -std=c++17 Graph.cpp Graph-test2.cpp \
    ../../array/GeneralArray/GeneralArray.cpp \
    ../../array/SparseMatrix/SparseMatrix.cpp \
    ../../chain/Node/Node.cpp \
    ../../chain/DoubleNode/DoubleNode.cpp \
    ../../chain/ChainIterator/ChainIterator.cpp \
    ../../chain/DLIterator/DLIterator.cpp \
    ../../chain/DoublyLinkedList/DoublyLinkedList.cpp \
    ../../chain/LinkedSparseMatrix/LinkedMatrixTerm.cpp \
    ../../chain/LinkedSparseMatrix/LinkedSparseMatrix.cpp -o test

#include <iostream>
#include <vector>
#include "Graph.hpp"
#include "../../array/SparseMatrix/SparseMatrix.hpp"
#include "../../chain/LinkedSparseMatrix/LinkedSparseMatrix.hpp"

using namespace std;

int main() 
{
    cout << "=== Graph Algorithms Test Program ===" << endl << endl;
    
    // Build a weighted, undirected graph with 10 nodes (0 through 9).
    // We'll use a sample graph (similar to the classic example from textbooks).
    //   (0)--4--(1)
    //    |      /  \
    //    8    8     11
    //    |   /        \
    //   (7)-----------(2)
    //    | \         / | 
    //    1  2       7  2
    //   (6)--2--(5)-(3)--9--(4)
    //          \     /
    //           6   14
    //            \ /
    //           (8)---3---(9)
    //
    // Edges (u, v, weight):
    // 0-1: 4, 0-7: 8,
    // 1-2: 8, 1-7: 11,
    // 2-3: 7, 2-5: 4, 2-8: 2,
    // 3-4: 9, 3-5: 14,
    // 4-? we'll add an edge (not used in MST) to ensure all 10 nodes are connected.
    // 5-6: 2,
    // 6-7: 1, 6-8: 6,
    // 7-8: 7, 7-9: 2,
    // 8-9: 3.
    
    Graph g(10, true, false);
    g.AddEdge(0, 1, 4);
    g.AddEdge(0, 7, 8);
    g.AddEdge(1, 2, 8);
    g.AddEdge(1, 7, 11);
    g.AddEdge(2, 3, 7);
    g.AddEdge(2, 5, 4);
    g.AddEdge(2, 8, 2);
    g.AddEdge(3, 4, 9);
    g.AddEdge(3, 5, 14);
    g.AddEdge(5, 6, 2);
    g.AddEdge(6, 7, 1);
    g.AddEdge(6, 8, 6);
    g.AddEdge(7, 8, 7);
    g.AddEdge(7, 9, 2);
    g.AddEdge(8, 9, 3);

    // --- Test Minimum Spanning Tree Algorithms ---
    Graph mstKruskal = g.Kruskal();
    cout << "Kruskal's MST:" << endl;
    cout << mstKruskal << endl << endl;

    Graph mstPrim = g.Prim();
    cout << "Prim's MST:" << endl;
    cout << mstPrim << endl << endl;

    Graph mstSollin = g.Sollin();
    cout << "Sollin's MST:" << endl;
    cout << mstSollin << endl << endl;

    // --- Test Shortest Path Algorithms ---
    int source = 0, destination = 4;
    vector<int> dijkstraPath = g.Dijkstra(source, destination);
    cout << "Dijkstra's shortest path from " << source << " to " << destination << ":" << endl;
    for (int node : dijkstraPath)
        cout << node << " ";
    cout << endl << endl;

    vector<int> bellmanPath = g.BellmanFord(source, destination);
    cout << "Bellman-Ford shortest path from " << source << " to " << destination << ":" << endl;
    for (int node : bellmanPath)
        cout << node << " ";
    cout << endl << endl;

    vector<vector<int>> floydPaths = g.Floyd();
    cout << "Floyd's all-pairs shortest paths (showing one path per pair):" << endl;
    for (size_t i = 0; i < floydPaths.size(); i++) 
    {
        cout << "Path " << i << ": ";
        for (int node : floydPaths[i])
            cout << node << " ";
        cout << endl;
    }
    cout << endl;

    // Generate the adjacency matrix as a SparseMatrix.
    SparseMatrix sm = g.AdjMatSparse();
    cout << "Adjacency Matrix (SparseMatrix):" << endl;
    cout << sm << endl << endl;
    
    // Generate the adjacency matrix as a LinkedSparseMatrix.
    LinkedSparseMatrix lsm = g.AdjMatLinked();
    cout << "Adjacency Matrix (LinkedSparseMatrix):" << endl;
    cout << lsm << endl << endl;
    
    cout << "=== End of Graph Adjacency Matrix Test Program ===" << endl;
    return 0;
}
