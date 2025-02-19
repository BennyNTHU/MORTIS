# MORTIS: Memory Oriented Resource Toolkit for Information Structures

![image](./media/mortis.jpg)

## 1. Overview

**MORTIS** is a C++17-based data structure library. In this project, we implement various data structures and abstract data types (ADTs). These include:

- Array-like structures  
- Chain-based (linked) structures  
- Container types  
- Graphs  
- Trees  
- Hash tables

Some of the implemented data structures are also defined as **MortisInvariant**.

Below is a summary of the data structures provided by MORTIS:

| **Category**  | **Data Structure**       | **Description**                                                                                                                                         | **Documentation (CN)**                      | **Documentation (EN)**                      | **Data Types Accepted** |
|---------------|--------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------|---------------------------------------------|-------------------------|
| **Array**     | **GeneralArray**         | A dynamic array that can store built-in C++ types.                                                                                                    | [中文](./docs_CN/GeneralArray.md)           | [English](./docs_EN/GeneralArray.md)         |                         |
|               | **Polynomial**           | Represents a polynomial with coefficients restricted to floating-point numbers or integers and with an integer degree.                                 | [中文](./docs_CN/Polynomial.md)             | [English](./docs_EN/Polynomial.md)           |                         |
|               | **SparseMatrix**         | Implements a sparse matrix where the elements are restricted to floating-point numbers or integers.                                                   | [中文](./docs_CN/SparseMatrix.md)           | [English](./docs_EN/SparseMatrix.md)         |                         |
|               | **String**               | An enhanced C-string with additional string manipulation functions.                                                                                   | [中文](./docs_CN/String.md)                 | [English](./docs_EN/String.md)               |                         |
| **Container** | **Bag**                  | A multiset-like container that supports duplicate elements and basic insertion, deletion, and search operations.                                        | [中文](./docs_CN/Bag.md)                    | [English](./docs_EN/Bag.md)                    |                         |
|               | **DeQue**                | A double-ended queue (derived from Bag).                                                                                                              | [中文](./docs_CN/DeQue.md)                  | [English](./docs_EN/DeQue.md)                  |                         |
|               | **Dictionary**           | A multimap supporting map-reduce functionality.                                                                                                       | [中文](./docs_CN/Dictionary.md)             | [English](./docs_EN/Dictionary.md)           |                         |
|               | **Stack**                | A stack (derived from Bag).                                                                                                                             | [中文](./docs_CN/Stack.md)                  | [English](./docs_EN/Stack.md)                  |                         |
|               | **Queue**                | A queue (derived from Stack).                                                                                                                           | [中文](./docs_CN/Queue.md)                  | [English](./docs_EN/Queue.md)                  |                         |
|               | **CirQue**               | A circular queue (derived from DeQue).                                                                                                                  | [中文](./docs_CN/CirQue.md)                 | [English](./docs_EN/CirQue.md)                 |                         |
| **Chain**     | **Node, ChainIterator, LinkedList** | Basic singly linked chain structures.                                                                                                                 | [中文](./docs_CN/LinkedList.md)             | [English](./docs_EN/LinkedList.md)             |                         |
|               | **CircularList**         | A circular singly linked list (derived from LinkedList).                                                                                              | [中文](./docs_CN/CircularList.md)           | [English](./docs_EN/CircularList.md)           |                         |
|               | **DoubleNode, DLIterator, DoublyLinkedList** | Doubly linked chain structures.                                                                                                                         | [中文](./docs_CN/DoublyLinkedList.md)       | [English](./docs_EN/DoublyLinkedList.md)       |                         |
|               | **CircularDoubleList**   | A circular doubly linked list (derived from DoublyLinkedList).                                                                                          | [中文](./docs_CN/CircularDoubleList.md)     | [English](./docs_EN/CircularDoubleList.md)     |                         |
|               | **LinkedPolynomial**     | A polynomial representation using a linked structure.                                                                                                 | [中文](./docs_CN/LinkedPolynomial.md)       | [English](./docs_EN/LinkedPolynomial.md)       |                         |
|               | **LinkedSparseMatrix**   | A sparse matrix representation using a linked structure.                                                                                              | [中文](./docs_CN/LinkedSparseMatrix.md)     | [English](./docs_EN/LinkedSparseMatrix.md)     |                         |
| **Hash Table**| **HashTable**            | A generic hash table implementation.                                                                                                                  | [中文](./docs_CN/HashTable.md)              | [English](./docs_EN/HashTable.md)              |                         |
|               | **BloomFilter**          | A Bloom filter implementation.                                                                                                                          | [中文](./docs_CN/BloomFilter.md)            | [English](./docs_EN/BloomFilter.md)            |                         |
| **Tree**      | **BinaryTree**           | A general binary tree.                                                                                                                                  | [中文](./docs_CN/BinaryTree.md)             | [English](./docs_EN/BinaryTree.md)             |                         |
|               | **BinaryTreeNode**       | The node type for binary trees.                                                                                                                         | [中文](./docs_CN/BinaryTreeNode.md)         | [English](./docs_EN/BinaryTreeNode.md)         |                         |
|               | **BinarySearchTree**     | A binary search tree (derived from BinaryTree).                                                                                                         | [中文](./docs_CN/BinarySearchTree.md)       | [English](./docs_EN/BinarySearchTree.md)       |                         |
|               | **MaxHeap**              | A maximum heap (derived from BinaryTree).                                                                                                               | [中文](./docs_CN/MaxHeap.md)                | [English](./docs_EN/MaxHeap.md)                |                         |
|               | **MinHeap**              | A minimum heap (derived from MaxHeap).                                                                                                                  | [中文](./docs_CN/MinHeap.md)                | [English](./docs_EN/MinHeap.md)                |                         |
|               | **Set**                  | A set data structure (derived from BinarySearchTree) that supports typical set operations (union, intersection, difference, etc.).                      | [中文](./docs_CN/Set.md)                    | [English](./docs_EN/Set.md)                    |                         |
| **Graph**     | **Graph**                | A graph data structure that does not support multiple edges.                                                                                          | [中文](./docs_CN/Graph.md)                  | [English](./docs_EN/Graph.md)                  |                         |
|               | **MultiGraph**         | A graph data structure that supports multiple edges. Directed/undirected and weighted/unweighted graphs are treated as attributes.                     | [中文](./docs_CN/MultiGraph.md)           | [English](./docs_EN/MultiGraph.md)           |                         |


## 2. Quick Start 

<!--leave blank now-->

## 3. Q & A

- **Q: Why is the project called MORTIS?**  
  **A:** The project is named in honor of Mortis, the guitarist of the renowned girl band, Ave Mujica.

- **Q: Do you implement linked stacks or linked queues?**  
  **A:** Our chain-based structures can be utilized as both linked stacks and linked queues, depending on how they are manipulated.

- **Q: Why didn't you implement a generalized list?**  
  **A:** We believe that generalized lists have limited practical applications.


- Q: 你是MyGO廚嗎
- A: 是

![image](./media/mortis2.png)

## References

> [1] E. Horowitz, S. Sahni, and D. Mehta, *Fundamentals of Data Structures in C++*, 2nd ed. New Jersey: Silicon Press, 2006.

> [2] T.-L. Chung, "Data Structures," EECS204002, Department of Electrical Engineering and Computer Science, National Tsing Hua University, Hsinchu, Taiwan, Spring 2021.
