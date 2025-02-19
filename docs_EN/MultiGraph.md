# MultiGraph API Documentation

The `MultiGraph` class is a graph data structure that supports multiple edges between the same pair of vertices. In other words, the graph allows parallel edges. This is useful in scenarios where there are multiple connections (with potentially different weights or properties) between the same nodes. The graph can be either directed or undirected and either weighted or unweighted. In unweighted mode, any weight provided is forced to 1.

## Table of Contents

1. [Overview](#overview)
2. [Graph Properties](#graph-properties)
3. [Constructors and Destructor](#constructors-and-destructor)
4. [Basic Operations](#basic-operations)
5. [Graph Search Algorithms](#graph-search-algorithms)
6. [Spanning Tree and Connectivity](#spanning-tree-and-connectivity)
7. [Shortest Paths Algorithms](#shortest-paths-algorithms)
8. [Adjacency Matrix Generation](#adjacency-matrix-generation)
9. [Example Code](#example-code)
10. [Additional Notes](#additional-notes)

---

## 1. Overview

The `MultiGraph` class provides an implementation for graphs that allow multiple edges (parallel edges) between nodes. In addition to the conventional properties of graphs, this class maintains:
- A vector of node identifiers.
- An edge list where each edge is represented by a triple `{u, v, w}`.  
  When the graph is unweighted, the weight (`w`) is automatically set to 1.
- An adjacency list that stores neighbors for each vertex.
- Attributes indicating whether the graph is weighted and/or directed.

---

## 2. Graph Properties

The key private members of `MultiGraph` are:

- **int n:**  
  The number of vertices in the graph.

- **int e:**  
  The number of edges (including parallel edges).

- **std::vector<int> nodeVector:**  
  A list of node identifiers. Nodes are typically represented as integers.

- **std::vector<std::vector<int>*> edgeVector:**  
  A list where each edge is represented as a vector of three integers: `{u, v, w}`.  
  For an unweighted graph, the weight (`w`) is set to 1.

- **DoublyLinkedList<DoublyLinkedList<int>> adjacencyList:**  
  An adjacency list structure storing the neighbors for each vertex.  
  Each inner list contains the node IDs of vertices that are adjacent (or connected via an edge) to the corresponding node.

- **bool isWeighted:**  
  Indicates whether the graph supports weighted edges. If false, all edges have a weight of 1.

- **bool isDirected:**  
  Indicates whether the graph is directed. In an undirected graph, an edge `{u, v, w}` is treated as identical to `{v, u, w}`.

---

## 3. Constructors and Destructor

### Default Constructor

```cpp
/**
 * @brief Creates an empty MultiGraph.
 *
 * By default, the graph is unweighted and undirected.
 */
MultiGraph();
```

### Constructor with Number of Nodes

```cpp
/**
 * @brief Initializes the MultiGraph with a specified number of nodes.
 *
 * The nodes are labeled from 0 to numNodes - 1.
 *
 * @param numNodes Number of nodes.
 * @param weighted True if the graph should be weighted (default false).
 * @param directed True if the graph should be directed (default false).
 */
MultiGraph(int numNodes, bool weighted = false, bool directed = false);
```

### Constructor from a Vector of Node Identifiers

```cpp
/**
 * @brief Constructs a MultiGraph from a vector of node identifiers.
 *
 * @param nodes A vector containing the node IDs.
 * @param weighted True if the graph should be weighted (default false).
 * @param directed True if the graph should be directed (default false).
 */
MultiGraph(const std::vector<int>& nodes, bool weighted = false, bool directed = false);
```

### Destructor

```cpp
/**
 * @brief Destructor.
 *
 * Frees all dynamically allocated memory associated with the MultiGraph.
 */
~MultiGraph();
```

---

## 4. Basic Operations

### Accessor Functions

- **Number of Nodes**

  ```cpp
  /**
   * @brief Returns the number of nodes in the graph.
   * @return The total number of nodes.
   */
  int NumberOfNodes() const;
  ```

- **Number of Edges**

  ```cpp
  /**
   * @brief Returns the number of edges in the graph.
   * @return The total number of edges.
   */
  int NumberOfEdges() const;
  ```

- **Degree of a Node**

  ```cpp
  /**
   * @brief Returns the degree of a given node.
   * @param u The node identifier.
   * @return The degree of node u.
   */
  int Degree(int u) const;
  ```

- **Edge Existence**

  ```cpp
  /**
   * @brief Checks whether an edge exists between two nodes.
   * @param u The source node.
   * @param v The destination node.
   * @return True if an edge exists, false otherwise.
   */
  bool ExistsEdge(int u, int v) const;
  ```

### Modification Operations

- **Add Node**

  ```cpp
  /**
   * @brief Adds a new node to the graph.
   *
   * The new node will be assigned an identifier equal to the current number of nodes.
   */
  void AddNode();
  ```

- **Remove Node**

  ```cpp
  /**
   * @brief Removes a node and all its associated edges from the graph.
   * @param u The node identifier to remove.
   */
  void RemoveNode(int u);
  ```

- **Add Edge**

  ```cpp
  /**
   * @brief Adds an edge to the graph.
   *
   * The edge is represented as a vector of three integers: {u, v, w}.  
   * For unweighted graphs, w is forced to 1.
   *
   * @param edge A vector containing the edge data: {u, v, w}.
   */
  void AddEdge(const std::vector<int>& edge);
  ```

- **Remove Edge**

  ```cpp
  /**
   * @brief Removes an edge from the graph.
   * @param u The source node.
   * @param v The destination node.
   */
  void RemoveEdge(int u, int v);
  ```

---

## 5. Graph Search Algorithms

### Breadth-First Search (BFS)

```cpp
/**
 * @brief Performs a breadth-first search (BFS) starting from a given node.
 *
 * @param start The starting node identifier.
 * @return A vector containing the node identifiers in the order they were visited.
 */
std::vector<int> BFS(int start) const;
```

### Depth-First Search (DFS)

```cpp
/**
 * @brief Performs a depth-first search (DFS) starting from a given node.
 *
 * @param start The starting node identifier.
 * @return A vector containing the node identifiers in the order they were visited.
 */
std::vector<int> DFS(int start) const;
```

*Note: The class may also provide iterator classes for BFS and DFS traversals.*

---

## 6. Spanning Tree and Connectivity

### Spanning Tree

```cpp
/**
 * @brief Computes a spanning tree of the graph using a chosen algorithm.
 *
 * @return A new MultiGraph object representing the spanning tree.
 */
MultiGraph<T> SpanningTree() const;
```

### Connected Components

```cpp
/**
 * @brief Computes the connected components of the graph.
 *
 * @return A vector of MultiGraph objects, each representing a connected component.
 */
std::vector<MultiGraph<T>> Components() const;
```

### Biconnected Components

```cpp
/**
 * @brief Computes the biconnected components of the graph.
 *
 * @return A vector of vectors, where each inner vector contains node identifiers
 *         that form one biconnected component.
 */
std::vector<std::vector<int>> Biconnected() const;
```

---

## 7. Shortest Paths Algorithms

### Dijkstra's Algorithm

```cpp
/**
 * @brief Computes the shortest paths from a source node using Dijkstra's algorithm.
 *
 * @param source The source node identifier.
 * @return A vector where the i-th element represents the shortest distance from the source to node i.
 */
std::vector<int> Dijkstra(int source) const;
```

### Bellman-Ford Algorithm

```cpp
/**
 * @brief Computes the shortest paths from a source node using the Bellman-Ford algorithm.
 *
 * @param source The source node identifier.
 * @return A vector where the i-th element represents the shortest distance from the source to node i.
 */
std::vector<int> BellmanFord(int source) const;
```

### Floyd's Algorithm

```cpp
/**
 * @brief Computes the shortest paths between all pairs of nodes using Floyd's algorithm.
 *
 * @return A 2D vector (matrix) where the element at (i, j) is the shortest distance from node i to node j.
 */
std::vector<std::vector<int>> Floyd() const;
```

---

## 8. Adjacency Matrix Generation

### Using SparseMatrix

```cpp
/**
 * @brief Generates the adjacency matrix using the SparseMatrix data structure.
 *
 * @return A SparseMatrix object representing the graph.
 */
SparseMatrix<T> AdjMatSparse() const;
```

### Using LinkedSparseMatrix

```cpp
/**
 * @brief Generates the adjacency matrix using the LinkedSparseMatrix data structure.
 *
 * @return A LinkedSparseMatrix object representing the graph.
 */
LinkedSparseMatrix<T> AdjMatLinked() const;
```

---

## 9. Example Code

### Example 1: Creating a Graph and Running BFS/DFS

```cpp
#include <iostream>
#include "MultiGraph.hpp"

using namespace std;

int main() {
    // Create a MultiGraph with 5 nodes (0 to 4), unweighted and undirected.
    MultiGraph<int> g(5);
    
    // Add edges (for unweighted graphs, the weight is always 1).
    g.AddEdge({0, 1, 1});
    g.AddEdge({0, 2, 1});
    g.AddEdge({1, 3, 1});
    g.AddEdge({2, 3, 1});
    g.AddEdge({3, 4, 1});
    g.AddEdge({0, 1, 1}); // Adding a parallel edge between 0 and 1.
    
    // Perform BFS starting from node 0.
    vector<int> bfsPath = g.BFS(0);
    cout << "BFS Path from node 0: ";
    for (int node : bfsPath)
        cout << node << " ";
    cout << endl;
    
    // Perform DFS starting from node 0.
    vector<int> dfsPath = g.DFS(0);
    cout << "DFS Path from node 0: ";
    for (int node : dfsPath)
        cout << node << " ";
    cout << endl;
    
    return 0;
}
```

### Example 2: Spanning Tree and Biconnected Components

```cpp
#include <iostream>
#include "MultiGraph.hpp"

using namespace std;

int main() {
    // Create a weighted, undirected MultiGraph with 6 nodes.
    MultiGraph<int> g(6, true, false);
    
    // Add weighted edges.
    g.AddEdge({0, 1, 5});
    g.AddEdge({0, 2, 3});
    g.AddEdge({1, 2, 2});
    g.AddEdge({1, 3, 6});
    g.AddEdge({2, 3, 7});
    g.AddEdge({2, 4, 4});
    g.AddEdge({3, 4, 2});
    g.AddEdge({3, 5, 1});
    g.AddEdge({4, 5, 3});
    
    // Compute spanning tree.
    MultiGraph<int> spanningTree = g.SpanningTree();
    cout << "Spanning Tree:" << endl;
    cout << spanningTree << endl;
    
    // Compute biconnected components.
    vector<vector<int>> bicomponents = g.Biconnected();
    cout << "Biconnected Components:" << endl;
    for (const auto& comp : bicomponents) {
        cout << "{ ";
        for (int node : comp)
            cout << node << " ";
        cout << "}" << endl;
    }
    
    return 0;
}
```

### Example 3: Shortest Paths

```cpp
#include <iostream>
#include "MultiGraph.hpp"

using namespace std;

int main() {
    // Create a weighted, directed MultiGraph with 5 nodes.
    MultiGraph<int> g(5, true, true);
    
    // Add directed, weighted edges.
    g.AddEdge({0, 1, 2});
    g.AddEdge({0, 2, 4});
    g.AddEdge({1, 2, 1});
    g.AddEdge({1, 3, 7});
    g.AddEdge({2, 4, 3});
    g.AddEdge({3, 4, 1});
    
    // Compute shortest paths from node 0 using Dijkstra's algorithm.
    vector<int> distances = g.Dijkstra(0);
    cout << "Shortest distances from node 0 (Dijkstra): ";
    for (int d : distances)
        cout << d << " ";
    cout << endl;
    
    // Compute all pairs shortest paths using Floyd's algorithm.
    vector<vector<int>> allPairs = g.Floyd();
    cout << "All-pairs shortest paths (Floyd): " << endl;
    for (const auto& row : allPairs) {
        for (int d : row)
            cout << d << "\t";
        cout << endl;
    }
    
    return 0;
}
```

---

## 10. Additional Notes

- **Iterators:**  
  The BFS and DFS functions return a vector of node identifiers indicating the order in which nodes are visited. Advanced users may create custom iterators if needed.

- **Edge Cases:**  
  The API functions throw exceptions (e.g., `std::out_of_range` or `std::runtime_error`) when inputs are invalid. Make sure to handle these exceptions using try-catch blocks in your code.

- **Adjacency List:**  
  The adjacency list is implemented using a doubly linked list of doubly linked lists. This allows efficient insertion and deletion of edges and can be used to quickly traverse neighbors of a given vertex.

- **Graph Attributes:**  
  The `isWeighted` and `isDirected` attributes determine how edges are interpreted:
  - **Weighted:** When true, edge weights are used; when false, all edge weights are 1.
  - **Directed:** When true, an edge `{u, v, w}` is different from `{v, u, w}`; when false, they are treated as identical.
