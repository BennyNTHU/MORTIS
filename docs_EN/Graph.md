# `Graph.hpp` Documentation

## Overview

The `Graph.hpp` file defines a templated `Graph` class that models a graph structure. The graph can be directed or undirected, weighted or unweighted, and can handle multiple nodes and edges. It uses an adjacency list representation for storing the graph's structure and provides various graph algorithms like Dijkstra's, Kruskal's, and Prim's algorithms for shortest paths and minimum spanning trees.

---

## Key Components

### `Graph` Class

The `Graph` class represents a graph where each node is identified by an integer, and edges are stored as triples `{u, v, w}`, where:
- `u`: source node,
- `v`: destination node,
- `w`: weight of the edge (in unweighted graphs, `w` is always 1).

The class supports both directed and undirected graphs, and can store both weighted and unweighted edges.

---

### Constructors & Destructor

- **`Graph()`**: Default constructor that initializes an empty graph. By default, the graph is unweighted and undirected.

  Example:
  ```cpp
  Graph graph;  // Creates an empty, unweighted, undirected graph
  ```

- **`Graph(int numNodes, bool weighted = false, bool directed = false)`**: Initializes the graph with `numNodes` nodes. Optionally, you can specify whether the graph should be weighted and whether it is directed.

  Example:
  ```cpp
  Graph graph(5, true, true);  // Creates a directed, weighted graph with 5 nodes
  ```

- **`Graph(const std::vector<int>& nodes, bool weighted = false, bool directed = false)`**: Initializes the graph from a vector of node identifiers, with options for weighted and directed graphs.

  Example:
  ```cpp
  std::vector<int> nodes = {0, 1, 2, 3};
  Graph graph(nodes, false, true);  // Directed, unweighted graph with specified nodes
  ```

- **`~Graph()`**: Destructor that cleans up the graph resources.

---

### Modification Methods (Add/Remove)

- **`AddNode(int node)`**: Adds a new node with the specified identifier `node` to the graph.

  Example:
  ```cpp
  graph.AddNode(5);  // Adds node 5 to the graph
  ```

- **`RemoveNode(int node)`**: Removes a node and all its incident edges from the graph.

  Example:
  ```cpp
  graph.RemoveNode(3);  // Removes node 3 and its edges
  ```

- **`AddEdge(int u, int v, double w = 1)`**: Adds an edge from node `u` to node `v` with weight `w`. If the graph is unweighted, the weight is set to 1 by default.

  Example:
  ```cpp
  graph.AddEdge(1, 2, 3.5);  // Adds an edge from node 1 to node 2 with weight 3.5
  ```

- **`RemoveEdge(int u, int v)`**: Removes the edge between node `u` and node `v`.

  Example:
  ```cpp
  graph.RemoveEdge(1, 2);  // Removes the edge between nodes 1 and 2
  ```

---

### Accessor Methods (Properties)

- **`IsEmpty() const`**: Returns `true` if the graph has no nodes (i.e., it is empty), otherwise `false`.

  Example:
  ```cpp
  bool isEmpty = graph.IsEmpty();  // Check if the graph is empty
  ```

- **`Degree(int u) const`**: Returns the degree of node `u`. For directed graphs, the degree is the sum of in-degree and out-degree.

  Example:
  ```cpp
  int degree = graph.Degree(1);  // Get the degree of node 1
  ```

- **`ExistsEdge(int u, int v) const`**: Returns `true` if there is an edge from node `u` to node `v`.

  Example:
  ```cpp
  bool exists = graph.ExistsEdge(1, 2);  // Check if there is an edge from 1 to 2
  ```

- **`NumberOfNodes() const`**: Returns the total number of nodes in the graph.

  Example:
  ```cpp
  int numNodes = graph.NumberOfNodes();  // Get the total number of nodes
  ```

- **`NumberOfEdges() const`**: Returns the total number of edges in the graph.

  Example:
  ```cpp
  int numEdges = graph.NumberOfEdges();  // Get the total number of edges
  ```

---

### Spanning Tree and Component Methods

- **`SpanningTree() const`**: Computes a spanning tree of the graph and returns it as a new `Graph` object.

  Example:
  ```cpp
  Graph spanningTree = graph.SpanningTree();  // Get the spanning tree of the graph
  ```

- **`Components() const`**: Computes the connected components of the graph and returns a vector of vectors, where each inner vector contains the node IDs of a connected component.

  Example:
  ```cpp
  auto components = graph.Components();  // Get the connected components
  ```

- **`Biconnected() const`**: Computes the biconnected components of the graph and returns them as a vector of vectors, where each inner vector contains the node IDs of a biconnected component.

  Example:
  ```cpp
  auto biconnectedComponents = graph.Biconnected();  // Get the biconnected components
  ```

---

### Traversal and Path Finding

- **`BFS(int start = 0, int destination = -1) const`**: Performs a Breadth-First Search (BFS) from the `start` node to the `destination` node. If no destination is specified, BFS returns the order of traversal.

  Example:
  ```cpp
  auto bfsPath = graph.BFS(0, 3);  // Get the BFS path from node 0 to node 3
  ```

- **`DFS(int start = 0, int destination = -1) const`**: Performs a Depth-First Search (DFS) from the `start` node to the `destination` node. If no destination is specified, DFS returns the order of traversal.

  Example:
  ```cpp
  auto dfsPath = graph.DFS(0, 3);  // Get the DFS path from node 0 to node 3
  ```

- **`BFSIterator(int start = 0) const`**: Returns a vector of node IDs in BFS order starting from the specified `start` node.

  Example:
  ```cpp
  auto bfsIterator = graph.BFSIterator(0);  // Get BFS order of nodes starting from node 0
  ```

- **`DFSIterator(int start = 0) const`**: Returns a vector of node IDs in DFS order starting from the specified `start` node.

  Example:
  ```cpp
  auto dfsIterator = graph.DFSIterator(0);  // Get DFS order of nodes starting from node 0
  ```

---

### Graph Algorithms

- **`Kruskal()`**: Computes the minimum spanning tree using Kruskal's algorithm.

  Example:
  ```cpp
  Graph mst = graph.Kruskal();  // Get the minimum spanning tree using Kruskal's algorithm
  ```

- **`Prim()`**: Computes the minimum spanning tree using Prim's algorithm.

  Example:
  ```cpp
  Graph mst = graph.Prim();  // Get the minimum spanning tree using Prim's algorithm
  ```

- **`Sollin()`**: Computes the minimum spanning tree using Sollin's algorithm.

  Example:
  ```cpp
  Graph mst = graph.Sollin();  // Get the minimum spanning tree using Sollin's algorithm
  ```

- **`Dijkstra(int source, int destination)`**: Computes the shortest path from `source` to `destination` using Dijkstra's algorithm.

  Example:
  ```cpp
  auto dijkstraPath = graph.Dijkstra(0, 3);  // Get the shortest path from node 0 to node 3
  ```

- **`BellmanFord(int source, int destination)`**: Computes the shortest path from `source` to `destination` using the Bellman-Ford algorithm.

  Example:
  ```cpp
  auto bellmanFordPath = graph.BellmanFord(0, 3);  // Get the shortest path from node 0 to node 3 using Bellman-Ford
  ```

- **`Floyd()`**: Computes the shortest paths between all pairs of nodes using Floyd's algorithm.

  Example:
  ```cpp
  auto floydPaths = graph.Floyd();  // Get the shortest paths between all pairs of nodes
  ```

---

### Adjacency Matrix Generation

- **`AdjMatSparse()`**: Generates the adjacency matrix as a `SparseMatrix`.

  Example:
  ```cpp
  SparseMatrix adjMatrix = graph.AdjMatSparse();  // Get the adjacency matrix as a SparseMatrix
  ```

- **`AdjMatLinked()`**: Generates the adjacency matrix as a `LinkedSparseMatrix`.

  Example:
  ```cpp
  LinkedSparseMatrix adjMatrix = graph.AdjMatLinked();  // Get the adjacency matrix as a LinkedSparseMatrix
  ```

---

### Operator Overloads

- **`operator=(const Graph& other)`**: Assignment operator for deep copying another graph.

  Example:
  ```cpp
  graph = otherGraph;  // Copy another graph into the current graph
  ```

- **`operator==(const Graph& other) const`**: Equality operator that compares two graphs for equality (same structure and edge weights).

  Example:
  ```cpp
  if (graph == otherGraph) {
      // Graphs are equal
  }
  ```

- **`operator!=(const Graph& other) const`**: Inequality operator that checks if two graphs are not equal.

  Example:
  ```cpp
  if (graph != otherGraph) {
      // Graphs are not equal
  }
  ```

- **`operator<<(std::ostream& out, const Graph& graph)`**: Output stream operator for printing the graph.

  Example:
  ```cpp
  std::cout << graph;  // Print the graph
  ```

- **`operator>>(std::istream& in, Graph& graph)`**: Input stream operator for reading a graph from the input stream.

 