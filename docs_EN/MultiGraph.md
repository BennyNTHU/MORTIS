# `MultiGraph` Documentation

## Overview

The `MultiGraph.hpp` header file defines a `MultiGraph` class that represents a multigraph data structure. A multigraph is a graph that can have multiple edges between the same pair of nodes. The `MultiGraph` class supports both weighted and unweighted edges, as well as directed and undirected graphs. Each node is represented by an integer, and edges are stored as triples `{u, v, w}`, where `u` is the source node, `v` is the destination node, and `w` is the edge weight (defaulting to 1 for unweighted graphs).

## Class: `MultiGraph`

### Description
The `MultiGraph` class represents a multigraph with nodes and edges. It provides methods to add/remove nodes and edges, query properties of the graph, and perform operations like checking if the graph is Eulerian.

### Key Features
- **Weighted/Unweighted**: Supports both weighted and unweighted edges.
- **Directed/Undirected**: Can operate as either a directed or undirected graph.
- **Multiple Edges**: Allows multiple edges between the same pair of nodes.

### Constructors and Destructor

#### `MultiGraph()`
- **Description**: Default constructor. Creates an empty unweighted and undirected multigraph.
- **Usage**:
  ```cpp
  MultiGraph graph;
  ```

#### `MultiGraph(int numNodes, bool weighted = false, bool directed = false)`
- **Description**: Constructor. Initializes a multigraph with a specified number of nodes.
- **Parameters**:
  - `numNodes`: The number of nodes in the graph.
  - `weighted`: If `true`, the graph is weighted (default is `false`).
  - `directed`: If `true`, the graph is directed (default is `false`).
- **Usage**:
  ```cpp
  MultiGraph graph(5, true, false);  // Creates a weighted, undirected graph with 5 nodes
  ```

#### `MultiGraph(const std::vector<int>& nodes, bool weighted = false, bool directed = false)`
- **Description**: Constructor. Initializes a multigraph from a vector of node identifiers.
- **Parameters**:
  - `nodes`: A vector of node identifiers.
  - `weighted`: If `true`, the graph is weighted (default is `false`).
  - `directed`: If `true`, the graph is directed (default is `false`).
- **Usage**:
  ```cpp
  std::vector<int> nodes = {1, 2, 3, 4, 5};
  MultiGraph graph(nodes, true, false);  // Creates a weighted, undirected graph with the given nodes
  ```

#### `~MultiGraph()`
- **Description**: Destructor. Cleans up the multigraph by deleting all nodes and edges.
- **Usage**: Automatically called when the object goes out of scope.

### Modification Methods

#### `void AddNode(int node)`
- **Description**: Adds a new node to the multigraph.
- **Parameters**:
  - `node`: The identifier of the node to add.
- **Usage**:
  ```cpp
  MultiGraph graph;
  graph.AddNode(1);  // Adds node 1 to the graph
  ```

#### `void RemoveNode(int node)`
- **Description**: Removes a node and all its incident edges from the multigraph.
- **Parameters**:
  - `node`: The identifier of the node to remove.
- **Usage**:
  ```cpp
  MultiGraph graph;
  graph.AddNode(1);
  graph.RemoveNode(1);  // Removes node 1 and all its edges
  ```

#### `void AddEdge(int u, int v, double w = 1)`
- **Description**: Adds an edge to the multigraph. If the graph is unweighted, the weight is forced to 1.
- **Parameters**:
  - `u`: The source node.
  - `v`: The destination node.
  - `w`: The weight of the edge (default is 1).
- **Usage**:
  ```cpp
  MultiGraph graph;
  graph.AddNode(1);
  graph.AddNode(2);
  graph.AddEdge(1, 2, 3.5);  // Adds an edge from node 1 to node 2 with weight 3.5
  ```

#### `void RemoveEdge(int u, int v)`
- **Description**: Removes an edge from the multigraph.
- **Parameters**:
  - `u`: The source node.
  - `v`: The destination node.
- **Usage**:
  ```cpp
  MultiGraph graph;
  graph.AddNode(1);
  graph.AddNode(2);
  graph.AddEdge(1, 2, 3.5);
  graph.RemoveEdge(1, 2);  // Removes the edge from node 1 to node 2
  ```

### Global Properties

#### `bool IsEmpty() const`
- **Description**: Checks if the multigraph is empty (i.e., has no nodes).
- **Return Value**: `true` if the graph is empty, `false` otherwise.
- **Usage**:
  ```cpp
  MultiGraph graph;
  bool empty = graph.IsEmpty();  // empty is true
  ```

#### `bool isEulerian() const`
- **Description**: Checks if the multigraph is Eulerian (i.e., has an Eulerian circuit).
- **Return Value**: `true` if the graph is Eulerian, `false` otherwise.
- **Usage**:
  ```cpp
  MultiGraph graph;
  graph.AddNode(1);
  graph.AddNode(2);
  graph.AddEdge(1, 2);
  bool eulerian = graph.isEulerian();  // eulerian is false (no Eulerian circuit)
  ```

#### `int NumberOfNodes() const`
- **Description**: Returns the total number of nodes in the multigraph.
- **Return Value**: The number of nodes as an integer.
- **Usage**:
  ```cpp
  MultiGraph graph;
  graph.AddNode(1);
  graph.AddNode(2);
  int numNodes = graph.NumberOfNodes();  // numNodes is 2
  ```

#### `int NumberOfEdges() const`
- **Description**: Returns the total number of edges in the multigraph.
- **Return Value**: The number of edges as an integer.
- **Usage**:
  ```cpp
  MultiGraph graph;
  graph.AddNode(1);
  graph.AddNode(2);
  graph.AddEdge(1, 2);
  int numEdges = graph.NumberOfEdges();  // numEdges is 1
  ```

### Local Properties

#### `int Degree(int u) const`
- **Description**: Returns the degree of a node (number of edges incident to it).
- **Parameters**:
  - `u`: The node identifier.
- **Return Value**: The degree of the node as an integer.
- **Usage**:
  ```cpp
  MultiGraph graph;
  graph.AddNode(1);
  graph.AddNode(2);
  graph.AddEdge(1, 2);
  int degree = graph.Degree(1);  // degree is 1
  ```

#### `int EdgeCount(int u, int v) const`
- **Description**: Returns the number of edges between two nodes.
- **Parameters**:
  - `u`: The source node.
  - `v`: The destination node.
- **Return Value**: The number of edges between `u` and `v` as an integer.
- **Usage**:
  ```cpp
  MultiGraph graph;
  graph.AddNode(1);
  graph.AddNode(2);
  graph.AddEdge(1, 2);
  graph.AddEdge(1, 2);
  int edgeCount = graph.EdgeCount(1, 2);  // edgeCount is 2
  ```

### Operator Overloads

#### `MultiGraph& operator=(const MultiGraph& other)`
- **Description**: Assignment operator. Performs a deep copy of another multigraph.
- **Parameters**:
  - `other`: The `MultiGraph` to copy from.
- **Return Value**: A reference to the current multigraph.
- **Usage**:
  ```cpp
  MultiGraph graph1;
  graph1.AddNode(1);
  MultiGraph graph2;
  graph2 = graph1;  // graph2 is now a copy of graph1
  ```

#### `bool operator==(const MultiGraph& other) const`
- **Description**: Equality operator. Checks if two multigraphs have the same structure and edge weights.
- **Parameters**:
  - `other`: The `MultiGraph` to compare with.
- **Return Value**: `true` if the multigraphs are equal, `false` otherwise.
- **Usage**:
  ```cpp
  MultiGraph graph1;
  graph1.AddNode(1);
  MultiGraph graph2;
  graph2.AddNode(1);
  bool equal = (graph1 == graph2);  // equal is true
  ```

#### `bool operator!=(const MultiGraph& other) const`
- **Description**: Inequality operator. Checks if two multigraphs are not identical.
- **Parameters**:
  - `other`: The `MultiGraph` to compare with.
- **Return Value**: `true` if the multigraphs are not equal, `false` otherwise.
- **Usage**:
  ```cpp
  MultiGraph graph1;
  graph1.AddNode(1);
  MultiGraph graph2;
  graph2.AddNode(2);
  bool notEqual = (graph1 != graph2);  // notEqual is true
  ```

#### `friend std::ostream& operator<<(std::ostream& out, const MultiGraph& multigraph)`
- **Description**: Overloaded `<<` operator for printing the multigraph as a list of edge triplets `{u, v, w}`.
- **Parameters**:
  - `out`: The output stream.
  - `multigraph`: The `MultiGraph` to print.
- **Return Value**: The output stream.
- **Usage**:
  ```cpp
  MultiGraph graph;
  graph.AddNode(1);
  graph.AddNode(2);
  graph.AddEdge(1, 2, 3.5);
  std::cout << graph;  // Prints the multigraph as edge triplets
  ```

#### `friend std::istream& operator>>(std::istream& in, MultiGraph& multigraph)`
- **Description**: Overloaded `>>` operator for reading the multigraph in the form of edge triplets `{u, v, w}`.
- **Parameters**:
  - `in`: The input stream.
  - `multigraph`: The `MultiGraph` to read into.
- **Return Value**: The input stream.
- **Usage**:
  ```cpp
  MultiGraph graph;
  std::cin >> graph;  // Reads the multigraph from input
  ```

## Example Usage

```cpp
#include "MultiGraph.hpp"
#include <iostream>

int main() {
    // Create a weighted, undirected multigraph
    MultiGraph graph(3, true, false);

    // Add edges
    graph.AddEdge(1, 2, 3.5);
    graph.AddEdge(2, 3, 2.0);
    graph.AddEdge(1, 3, 1.5);

    // Print the graph
    std::cout << "Graph: " << graph << std::endl;

    // Check properties
    std::cout << "Number of nodes: " << graph.NumberOfNodes() << std::endl;
    std::cout << "Number of edges: " << graph.NumberOfEdges() << std::endl;
    std::cout << "Degree of node 1: " << graph.Degree(1) << std::endl;
    std::cout << "Edge count between 1 and 2: " << graph.EdgeCount(1, 2) << std::endl;

    // Remove an edge
    graph.RemoveEdge(1, 2);
    std::cout << "After removing edge (1, 2): " << graph << std::endl;

    return 0;
}
```

## Potential Errors and Edge Cases

1. **Invalid Node Identifiers**: When adding or removing nodes/edges, ensure that the node identifiers are valid (i.e., they exist in the graph). Invalid identifiers may lead to runtime errors.
2. **Duplicate Nodes/Edges**: Adding duplicate nodes or edges may not always result in an error, but it could lead to unexpected behavior. Ensure that nodes/edges are unique unless duplicates are intended.
3. **Memory Management**: When dynamically allocating nodes and edges, ensure proper cleanup to avoid memory leaks.

## Dependencies

- **GeneralArray.hpp**: The `MultiGraph` class uses `GeneralArray` to store the edge list. Ensure that this file is included and properly configured in your project.
- **Standard Library**: The header file includes `<vector>` and `<variant>`, which are part of the C++ Standard Library. Ensure that your environment is configured to use the standard library.

## Summary

The `MultiGraph.hpp` file provides a flexible implementation of a multigraph data structure, supporting both weighted and unweighted edges, as well as directed and undirected graphs. By following the examples and guidelines provided, you can effectively use this class to build and manipulate multigraphs in your projects.
