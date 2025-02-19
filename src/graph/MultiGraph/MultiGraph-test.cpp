// MultiGraph-test.cpp
// Compile with (for example):
// g++ -std=c++17 MultiGraph.cpp MultiGraph-test.cpp ../../array/GeneralArray/GeneralArray.cpp -o test

#include <iostream>
#include <vector>
#include <cassert>
#include "MultiGraph.hpp"

using namespace std;

int main() 
{
    try {
        cout << "=== MultiGraph Test Program ===" << endl << endl;
        
        // --- Test Constructors ---
        // Create an empty multigraph (default: unweighted, undirected)
        MultiGraph mg1;
        assert(mg1.IsEmpty());
        cout << "mg1 is empty initially." << endl;
        
        // Create a multigraph with 5 nodes (0 to 4), weighted and undirected.
        MultiGraph mg2(5, true, false);
        cout << "mg2 created with 5 nodes, weighted = true, undirected." << endl;
        cout << "Number of nodes: " << mg2.NumberOfNodes() << endl;
        
        // --- Test Modification Methods ---
        // Add a new node.
        mg2.AddNode(5);
        cout << "After adding node 5, mg2 nodes: " << mg2.NumberOfNodes() << endl;
        
        // Try adding a duplicate node (should throw).
        try 
        {
            mg2.AddNode(5);
            assert(false);
        } 
        catch (const std::invalid_argument& e) 
        {
            cout << "Caught expected exception on duplicate AddNode: " << e.what() << endl;
        }
        
        // Add some edges.
        // We'll add: (0,1,2.5), (0,2,3.0), (1,2,1.2), (2,3,4.0), (3,4,2.2), (4,0,5.0)
        mg2.AddEdge(0, 1, 2.5);
        mg2.AddEdge(0, 2, 3.0);
        mg2.AddEdge(1, 2, 1.2);
        mg2.AddEdge(2, 3, 4.0);
        mg2.AddEdge(3, 4, 2.2);
        mg2.AddEdge(4, 0, 5.0);
        cout << "\nAfter adding 6 edges, mg2 edge count: " << mg2.NumberOfEdges() << endl;
        cout << "mg2 edges:" << endl << mg2 << endl;
        
        // Test Degree and EdgeCount.
        cout << "\nDegree of node 0: " << mg2.Degree(0) << endl;
        cout << "Edge count between 0 and 1: " << mg2.EdgeCount(0, 1) << endl;
        
        // Test isEulerian and isHamilton.
        cout << "\nIs mg2 Eulerian? " << (mg2.isEulerian() ? "Yes" : "No") << endl;
        
        // --- Test Assignment and Equality Operators ---
        MultiGraph mg3;
        mg3 = mg2;  // deep copy
        cout << "\nAfter assignment, mg3 (copy of mg2):" << endl << mg3 << endl;
        assert(mg3 == mg2);
        cout << "mg3 equals mg2." << endl;
        
        // Remove an edge from mg3.
        mg3.RemoveEdge(0, 1);
        cout << "\nAfter removing edge (0,1) from mg3:" << endl;
        cout << mg3 << endl;
        cout << "Edge count between 0 and 1 in mg3: " << mg3.EdgeCount(0, 1) << endl;
        
        // --- Test RemoveNode ---
        // Remove node 2 from mg3.
        mg3.RemoveNode(2);
        cout << "\nAfter removing node 2 from mg3:" << endl;
        cout << "Number of nodes: " << mg3.NumberOfNodes() << endl;
        cout << "Number of edges: " << mg3.NumberOfEdges() << endl;
        for (int node : {0,1,3,4,5}) 
        {
            cout << "Degree of node " << node << ": " << mg3.Degree(node) << endl;
        }
        cout << "mg3 edges after removal:" << endl << mg3 << endl;
        
        // --- Test Input Operator ---
        // (For demonstration, we'll simulate input using istringstream.)
        /*
        std::istringstream iss("{0,1,2.5} {1,2,1.2} {2,3,4.0}");
        MultiGraph mg4;
        iss >> mg4;
        cout << "\nmg4 read from input:" << endl << mg4 << endl;
        */
        
        // --- Final Output ---
        cout << "\nMultiGraph tests completed successfully." << endl;
    }
    catch (const std::exception& ex) 
    {
        cerr << "Exception: " << ex.what() << endl;
    }
    
    return 0;
}
