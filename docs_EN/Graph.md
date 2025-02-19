# Graph Class API Documentation

The `Graph` class provides a basic graph data structure that does not allow multiple edges. The graph is stored using an adjacency list representation. The class supports both weighted and unweighted graphs as well as directed and undirected graphs. In addition to the internal representation (using a vector of nodes and a vector of edges), the class provides several common graph algorithms.

> **Note:**  
> A node in the graph is represented by an `int` (its identifier). When the graph is weighted (i.e. `isWeighted == true`), each edge is represented as a triple `{u, v, w}` where `w` is the weight. In an unweighted graph, `w` is forced to be `1` regardless of input. When the graph is undirected (i.e. `isDirected == false`), the edge `{u, v, w}` is considered the same as `{v, u, w}`.

---

## Table of Contents

- [Graph Class API Documentation](#graph-class-api-documentation)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Graph Properties](#graph-properties)
  - [Constructors and Destructor](#constructors-and-destructor)
    - [Default Constructor](#default-constructor)
    - [Constructor with Number of Nodes](#constructor-with-number-of-nodes)
    - [Constructor from a Vector of Node Identifiers](#constructor-from-a-vector-of-node-identifiers)
    - [Destructor](#destructor)
  - [Accessors and Property Functions](#accessors-and-property-functions)
  - [Node and Edge Operations](#node-and-edge-operations)
  - [Graph Search Algorithms](#graph-search-algorithms)
  - [Spanning Tree and Components](#spanning-tree-and-components)
  - [Shortest Paths Algorithms](#shortest-paths-algorithms)
  - [Adjacency Matrix Generation](#adjacency-matrix-generation)
  - [Example Code](#example-code)
    - [Example 1: Creating a Graph and Running BFS/DFS](#example-1-creating-a-graph-and-running-bfsdfs)
    - [Example 2: Computing Spanning Tree and Biconnected Components](#example-2-computing-spanning-tree-and-biconnected-components)
    - [Example 3: Shortest Paths](#example-3-shortest-paths)
  - [Notes](#notes)

---

## Overview

The `Graph` class is designed for constructing graphs using an adjacency list. It includes:

- **Nodes:** Represented as integers.  
- **Edges:** Stored as vectors of three integers (`{u, v, w}`) where `w` is the weight (or 1 for unweighted graphs).  
- **Adjacency List:** A data structure (for example, a doubly linked list of doubly linked lists) to represent neighbors of each vertex.

The graph supports both directed and undirected modes, as well as weighted and unweighted modes.

---

## Graph Properties

The `Graph` class contains the following key private members:

- `int n;`  
  *Number of vertices.*

- `int e;`  
  *Number of edges.*

- `std::vector<int> nodeVector;`  
  *A list of node identifiers.*

- `std::vector<std::vector<int>*> edgeVector;`  
  *A list of edges, where each edge is stored as a vector of three integers: `{u, v, w}`.*

- `DoublyLinkedList<DoublyLinkedList<int>> adjacencyList;`  
  *An adjacency list that holds the neighbors for each vertex. (The inner list holds the node IDs of adjacent vertices.)*

- `bool isWeighted;`  
  *If true, the graph’s edges have weights; otherwise, every edge has a weight of 1.*

- `bool isDirected;`  
  *If true, the graph is directed; otherwise, it is undirected.*

---

## Constructors and Destructor

### Default Constructor

```cpp
/**
 * @brief Creates an empty graph.
 *
 * By default, the graph is unweighted and undirected.
 */
Graph();
```

### Constructor with Number of Nodes

```cpp
/**
 * @brief Initializes the graph with a specified number of nodes.
 *
 * Nodes are labeled from 0 to numNodes - 1.
 *
 * @param numNodes The number of nodes in the graph.
 * @param weighted True if the graph is weighted (default: false).
 * @param directed True if the graph is directed (default: false).
 */
Graph(int numNodes, bool weighted = false, bool directed = false);
```

### Constructor from a Vector of Node Identifiers

```cpp
/**
 * @brief Constructs a graph from a vector of node identifiers.
 *
 * @param nodes A vector of node IDs.
 * @param weighted True if the graph is weighted (default: false).
 * @param directed True if the graph is directed (default: false).
 */
Graph(const std::vector<int>& nodes, bool weighted = false, bool directed = false);
```

### Destructor

```cpp
/**
 * @brief Destructor.
 *
 * Frees all dynamically allocated memory associated with the graph.
 */
~Graph();
```

---

## Accessors and Property Functions

The following member functions provide information about the graph:

- `bool IsEmpty() const;`  
  *Returns true if the graph has no nodes.*

- `int Degree(int u) const;`  
  *Returns the degree of node `u` (i.e., the number of edges incident to `u`).*

- `bool ExistsEdge(int u, int v) const;`  
  *Returns true if there is an edge between node `u` and node `v`.*

- `int NumberOfNodes() const;`  
  *Returns the total number of nodes in the graph.*

- `int NumberOfEdges() const;`  
  *Returns the total number of edges in the graph.*

---

## Node and Edge Operations

The following functions allow you to modify the graph structure:

- `void AddNode();`  
  *Adds a new node to the graph. The node is given an identifier that continues from the last node.*

- `void RemoveNode(int u);`  
  *Removes the node with identifier `u` and all edges incident to it.*

- `void AddEdge(const std::vector<int>& edge);`  
  *Adds an edge to the graph. The edge is represented as a vector `{u, v, w}`. If the graph is unweighted, `w` is forced to 1.*

- `void RemoveEdge(int u, int v);`  
  *Removes the edge between nodes `u` and `v`.*

---

## Graph Search Algorithms

These functions search the graph and return the path (or sequence of nodes) discovered.

- **Breadth-First Search (BFS):**

  ```cpp
  /**
   * @brief Perform a Breadth-First Search (BFS) starting from a given node.
   * @param start The starting node identifier.
   * @return A vector containing the node identifiers in the order they were visited.
   */
  std::vector<int> BFS(int start) const;
  ```

- **Depth-First Search (DFS):**

  ```cpp
  /**
   * @brief Perform a Depth-First Search (DFS) starting from a given node.
   * @param start The starting node identifier.
   * @return A vector containing the node identifiers in the order they were visited.
   */
  std::vector<int> DFS(int start) const;
  ```

Additionally, iterators that yield nodes in BFS or DFS order may be provided.

---

## Spanning Tree and Components

Graph algorithms to extract structural properties:

- **Spanning Tree:**

  ```cpp
  /**
   * @brief Computes the spanning tree of the graph.
   * @return A new Graph object representing the spanning tree.
   */
  Graph<T> SpanningTree() const;
  ```

- **Connected Components:**

  ```cpp
  /**
   * @brief Computes the connected components of the graph.
   * @return A vector of graphs, where each graph is a connected component.
   */
  std::vector<Graph<T>> Components() const;
  ```

- **Biconnected Components:**

  ```cpp
  /**
   * @brief Computes the biconnected components of the graph.
   * @return A vector of vectors, each containing node identifiers belonging to one biconnected component.
   */
  std::vector<std::vector<int>> Biconnected() const;
  ```

---

## Shortest Paths Algorithms

These functions compute shortest path information in the graph:

- **Dijkstra's Algorithm:**

  ```cpp
  /**
   * @brief Computes the shortest paths from a source node using Dijkstra's algorithm.
   * @param source The source node identifier.
   * @return A vector where the i-th element is the distance from the source to node i.
   */
  std::vector<int> Dijkstra(int source) const;
  ```

- **Bellman-Ford Algorithm:**

  ```cpp
  /**
   * @brief Computes the shortest paths from a source node using the Bellman-Ford algorithm.
   * @param source The source node identifier.
   * @return A vector where the i-th element is the distance from the source to node i.
   */
  std::vector<int> BellmanFord(int source) const;
  ```

- **Floyd's Algorithm:**

  ```cpp
  /**
   * @brief Computes the shortest paths between all pairs of nodes using Floyd's algorithm.
   * @return A 2D vector (matrix) where the element at (i, j) is the shortest distance from node i to node j.
   */
  std::vector<std::vector<int>> Floyd() const;
  ```

---

## Adjacency Matrix Generation

The `Graph` class can generate adjacency matrices from the current graph.

- **Using SparseMatrix:**

  ```cpp
  /**
   * @brief Generates the adjacency matrix using the SparseMatrix data structure.
   * @return A SparseMatrix representing the graph.
   */
  SparseMatrix<T> AdjMatSparse() const;
  ```

- **Using LinkedSparseMatrix:**

  ```cpp
  /**
   * @brief Generates the adjacency matrix using the LinkedSparseMatrix data structure.
   * @return A LinkedSparseMatrix representing the graph.
   */
  LinkedSparseMatrix<T> AdjMatLinked() const;
  ```

---

## Example Code

Below are some example programs that demonstrate how to use various APIs of the `Graph` class.

### Example 1: Creating a Graph and Running BFS/DFS

```cpp
#include <iostream>
#include "Graph.hpp"

using namespace std;

int main() {
    // Create a graph with 5 nodes (0 to 4), unweighted and undirected.
    Graph<int> g(5);
    
    // Add some edges: For an unweighted graph, the weight is always 1.
    g.AddEdge({0, 1, 1});
    g.AddEdge({0, 2, 1});
    g.AddEdge({1, 3, 1});
    g.AddEdge({2, 3, 1});
    g.AddEdge({3, 4, 1});

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

### Example 2: Computing Spanning Tree and Biconnected Components

```cpp
#include <iostream>
#include "Graph.hpp"

using namespace std;

int main() {
    // Create a graph with 6 nodes.
    Graph<int> g(6, true, false); // weighted, undirected

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

    // Generate spanning tree using a chosen algorithm.
    Graph<int> spanningTree = g.SpanningTree();
    cout << "Spanning Tree:" << endl;
    // (Assuming operator<< is overloaded for Graph to print edges.)
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
#include "Graph.hpp"

using namespace std;

int main() {
    // Create a graph with 5 nodes.
    Graph<int> g(5, true, true); // weighted, directed

    // Add directed weighted edges.
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

## Notes

- **Iterators:**  
  The graph search algorithms (BFS and DFS) return a `std::vector<int>` containing node identifiers in the order they were visited. You can also build custom iterator classes if needed.

- **Edge Representation:**  
  When adding an edge, supply a vector of three integers. For example, to add an edge from node 0 to node 1 with weight 5, call:  
  ```cpp
  g.AddEdge({0, 1, 5});
  ```
  If the graph is unweighted, the weight is ignored (or forced to 1).

- **Spanning Tree & Shortest Path Algorithms:**  
  The spanning tree algorithms (Kruskal, Prim, Sollin) return a new `Graph` object representing the spanning tree. The shortest path algorithms (Dijkstra, Bellman-Ford, Floyd) return vectors containing distances or matrices representing path lengths.

- **Error Handling:**  
  Many functions throw exceptions (e.g., `std::out_of_range` or `std::runtime_error`) if the inputs are invalid. Be sure to use try-catch blocks as needed in your applications.
