// GraphTest.cpp
// Compile with (for example):
// g++ -std=c++17 Graph.cpp Graph-test.cpp\
    ../../array/GeneralArray/GeneralArray.cpp\
    ../../array/SparseMatrix/SparseMatrix.cpp\
    ../../chain/Node/Node.cpp\
    ../../chain/DoubleNode/DoubleNode.cpp\
    ../../chain/ChainIterator/ChainIterator.cpp\
    ../../chain/DLIterator/DLIterator.cpp\
    ../../chain/DoublyLinkedList/DoublyLinkedList.cpp\
    ../../chain/LinkedSparseMatrix/LinkedMatrixTerm.cpp\
    ../../chain/LinkedSparseMatrix/LinkedSparseMatrix.cpp -o test

#include <iostream>
#include <vector>

#include "Graph.hpp"

using namespace std;

int main() 
{
    cout << "=== Graph Test Program ===" << endl << endl;
    
    // --- Build a more complex graph ---
    // Create a weighted, undirected graph with 8 nodes (0 to 7).
    Graph g(8, true, false);
    
    // Add edges:
    // Triangle among nodes 0,1,2.
    g.AddEdge(0, 1, 10);
    g.AddEdge(1, 2, 20);
    g.AddEdge(2, 0, 30);
    
    // Bridge from triangle to node 3.
    g.AddEdge(1, 3, 40);
    
    // Cycle among nodes 3,4,5.
    g.AddEdge(3, 4, 50);
    g.AddEdge(4, 5, 60);
    g.AddEdge(5, 3, 70);
    
    // Chain from node 3 to nodes 6 and 7.
    g.AddEdge(3, 6, 80);
    g.AddEdge(6, 7, 90);
    
    cout << "Initial Graph:" << endl;
    cout << " - Number of nodes: " << g.NumberOfNodes() << endl;
    cout << " - Number of edges: " << g.NumberOfEdges() << endl;
    // cout << g << endl << endl;
    
    // --- Traversal Tests ---
    vector<int> bfsOrder = g.BFSIterator(0);
    cout << "BFS traversal order starting at node 0: ";
    for (int node : bfsOrder)
        cout << node << " ";
    cout << endl;
    
    vector<int> dfsOrder = g.DFSIterator(0);
    cout << "DFS traversal order starting at node 0: ";
    for (int node : dfsOrder)
        cout << node << " ";
    cout << endl << endl;
    
    vector<int> bfsPath = g.BFS(0, 7);
    if (!bfsPath.empty()) 
    {
        cout << "BFS path from 0 to 7: ";
        for (int node : bfsPath)
            cout << node << " ";
        cout << endl;
    } 
    else 
    {
        cout << "No BFS path found from 0 to 7." << endl;
    }
    
    vector<int> dfsPath = g.DFS(0, 7);
    if (!dfsPath.empty()) 
    {
        cout << "DFS path from 0 to 7: ";
        for (int node : dfsPath)
            cout << node << " ";
        cout << endl;
    } 
    else 
    {
        cout << "No DFS path found from 0 to 7." << endl;
    }
    cout << endl;
        
    // --- Test Operator Overloads ---
    // Assignment operator and equality.
    Graph g2;
    g2 = g; // deep copy
    cout << "Copied Graph (g2) via assignment:" << endl;
    cout << g2 << endl;
    
    // Check equality and inequality.
    if (g == g2) 
    {
        cout << "g and g2 are equal." << endl;
    } 
    else 
    {
        cout << "g and g2 are NOT equal." << endl;
    }
    
    // Modify g2: remove an edge and check inequality.
    g2.RemoveEdge(3, 4);
    if (g != g2) 
    {
        cout << "After modification, g and g2 are not equal." << endl;
    } 
    else 
    {
        cout << "After modification, g and g2 are still equal (unexpected)." << endl;
    }
    cout << endl;
    
    // --- Spanning Tree and Component Methods ---
    Graph spanningTree = g.SpanningTree();
    cout << "Spanning Tree:" << endl;
    cout << " - Number of nodes: " << spanningTree.NumberOfNodes() << endl;
    cout << " - Number of edges: " << spanningTree.NumberOfEdges() << endl;
    cout << "Spanning Tree (BFS traversal from node 0): ";
    vector<int> stBFS = spanningTree.BFSIterator(0);
    for (int node : stBFS)
        cout << node << " ";
    cout << endl << endl;

    // --- Test Modification Methods ---
    // Remove edge (1,3): disconnect the triangle from node 3.
    cout << "Removing edge (1,3)..." << endl;
    g.RemoveEdge(1, 3);
    cout << "Edge exists between 1 and 3? " << (g.ExistsEdge(1,3) ? "Yes" : "No") << endl;
    cout << "Number of edges after removal: " << g.NumberOfEdges() << endl;
    // cout << g << endl << endl;
    
    // Remove node 6.
    cout << "Removing node 6..." << endl;
    g.RemoveNode(6);
    cout << "Number of nodes after removal: " << g.NumberOfNodes() << endl;
    cout << "Number of edges after removal: " << g.NumberOfEdges() << endl;
    for (int i = 0; i < g.NumberOfNodes(); i++) {
        cout << "Degree of node " << i << ": " << g.Degree(i) << endl;
    }
    cout << endl;
    
    vector<vector<int>> components = g.Components();
    cout << "Connected Components:" << endl;
    for (size_t i = 0; i < components.size(); i++) 
    {
        cout << " Component " << i << ": ";
        for (int node : components[i])
            cout << node << " ";
        cout << endl;
    }
    cout << endl;
    
    try 
    {
        vector<vector<int>> bcc = g.Biconnected();
        cout << "Biconnected Components:" << endl;

        for (size_t i = 0; i < bcc.size(); i++) 
        {
            cout << " Component " << i << ": ";
            for (int node : bcc[i])
                cout << node << " ";
            cout << endl;
        }
    } 
    catch (const std::exception& ex) 
    {
        cout << "Error computing biconnected components: " << ex.what() << endl;
    }
    
    cout << endl << "=== End of Graph Test Program ===" << endl;
    return 0;
}
