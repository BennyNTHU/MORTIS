# `Graph` 技術文件

## 概述

`Graph.hpp` 檔案定義了一個模板化的 `Graph` 類別，該類別用於建模圖形結構。圖形可以是有向或無向的，加權或未加權的，並且可以處理多個節點和邊。它使用鄰接表來儲存圖形的結構，並提供了多種圖形演算法，如 Dijkstra、Kruskal 和 Prim 演算法，用於計算最短路徑和最小生成樹。

---

## 主要元件

### `Graph` 類別

`Graph` 類別代表一個圖形，其中每個節點由一個整數識別，邊以三元組 `{u, v, w}` 儲存，其中：
- `u`: 源節點，
- `v`: 目標節點，
- `w`: 邊的權重（在未加權圖形中，`w` 始終為 1）。

該類別支援有向和無向圖形，並且可以儲存加權和未加權的邊。

---

### 建構函式與解構函式

- **`Graph()`**: 預設建構函式，初始化一個空的圖形。預設情況下，圖形是未加權且無向的。

  範例：
  ```cpp
  Graph graph;  // 建立一個空的、未加權、無向的圖形
  ```

- **`Graph(int numNodes, bool weighted = false, bool directed = false)`**: 使用 `numNodes` 個節點初始化圖形。可選地，可以指定圖形是否為加權以及是否為有向。

  範例：
  ```cpp
  Graph graph(5, true, true);  // 建立一個有向、加權的圖形，包含 5 個節點
  ```

- **`Graph(const std::vector<int>& nodes, bool weighted = false, bool directed = false)`**: 從節點識別碼的向量初始化圖形，並可選擇是否為加權和有向圖形。

  範例：
  ```cpp
  std::vector<int> nodes = {0, 1, 2, 3};
  Graph graph(nodes, false, true);  // 有向、未加權的圖形，包含指定的節點
  ```

- **`~Graph()`**: 解構函式，清理圖形的資源。

---

### 修改方法（添加/移除）

- **`AddNode(int node)`**: 將具有指定識別碼 `node` 的新節點添加到圖形中。

  範例：
  ```cpp
  graph.AddNode(5);  // 將節點 5 添加到圖形中
  ```

- **`RemoveNode(int node)`**: 從圖形中移除一個節點及其所有相關的邊。

  範例：
  ```cpp
  graph.RemoveNode(3);  // 移除節點 3 及其邊
  ```

- **`AddEdge(int u, int v, double w = 1)`**: 添加一條從節點 `u` 到節點 `v` 的邊，權重為 `w`。如果圖形是未加權的，則權重預設為 1。

  範例：
  ```cpp
  graph.AddEdge(1, 2, 3.5);  // 添加一條從節點 1 到節點 2 的邊，權重為 3.5
  ```

- **`RemoveEdge(int u, int v)`**: 移除節點 `u` 和節點 `v` 之間的邊。

  範例：
  ```cpp
  graph.RemoveEdge(1, 2);  // 移除節點 1 和節點 2 之間的邊
  ```

---

### 存取方法（屬性）

- **`IsEmpty() const`**: 如果圖形沒有節點（即為空），則回傳 `true`，否則回傳 `false`。

  範例：
  ```cpp
  bool isEmpty = graph.IsEmpty();  // 檢查圖形是否為空
  ```

- **`Degree(int u) const`**: 回傳節點 `u` 的度數。對於有向圖形，度數是入度和出度的總和。

  範例：
  ```cpp
  int degree = graph.Degree(1);  // 取得節點 1 的度數
  ```

- **`ExistsEdge(int u, int v) const`**: 如果存在從節點 `u` 到節點 `v` 的邊，則回傳 `true`。

  範例：
  ```cpp
  bool exists = graph.ExistsEdge(1, 2);  // 檢查是否存在從節點 1 到節點 2 的邊
  ```

- **`NumberOfNodes() const`**: 回傳圖形中節點的總數。

  範例：
  ```cpp
  int numNodes = graph.NumberOfNodes();  // 取得圖形中節點的總數
  ```

- **`NumberOfEdges() const`**: 回傳圖形中邊的總數。

  範例：
  ```cpp
  int numEdges = graph.NumberOfEdges();  // 取得圖形中邊的總數
  ```

---

### 生成樹與連通元件方法

- **`SpanningTree() const`**: 計算圖形的生成樹，並將其作為一個新的 `Graph` 物件回傳。

  範例：
  ```cpp
  Graph spanningTree = graph.SpanningTree();  // 取得圖形的生成樹
  ```

- **`Components() const`**: 計算圖形的連通元件，並回傳一個向量的向量，其中每個內部向量包含一個連通元件的節點識別碼。

  範例：
  ```cpp
  auto components = graph.Components();  // 取得圖形的連通元件
  ```

- **`Biconnected() const`**: 計算圖形的雙連通元件，並將其作為一個向量的向量回傳，其中每個內部向量包含一個雙連通元件的節點識別碼。

  範例：
  ```cpp
  auto biconnectedComponents = graph.Biconnected();  // 取得圖形的雙連通元件
  ```

---

### 遍歷與路徑查找

- **`BFS(int start = 0, int destination = -1) const`**: 從 `start` 節點到 `destination` 節點執行廣度優先搜尋（BFS）。如果未指定目標節點，BFS 回傳遍歷的順序。

  範例：
  ```cpp
  auto bfsPath = graph.BFS(0, 3);  // 取得從節點 0 到節點 3 的 BFS 路徑
  ```

- **`DFS(int start = 0, int destination = -1) const`**: 從 `start` 節點到 `destination` 節點執行深度優先搜尋（DFS）。如果未指定目標節點，DFS 回傳遍歷的順序。

  範例：
  ```cpp
  auto dfsPath = graph.DFS(0, 3);  // 取得從節點 0 到節點 3 的 DFS 路徑
  ```

- **`BFSIterator(int start = 0) const`**: 回傳從指定 `start` 節點開始的 BFS 順序的節點識別碼向量。

  範例：
  ```cpp
  auto bfsIterator = graph.BFSIterator(0);  // 取得從節點 0 開始的 BFS 順序
  ```

- **`DFSIterator(int start = 0) const`**: 回傳從指定 `start` 節點開始的 DFS 順序的節點識別碼向量。

  範例：
  ```cpp
  auto dfsIterator = graph.DFSIterator(0);  // 取得從節點 0 開始的 DFS 順序
  ```

---

### 圖形演算法

- **`Kruskal()`**: 使用 Kruskal 演算法計算最小生成樹。

  範例：
  ```cpp
  Graph mst = graph.Kruskal();  // 使用 Kruskal 演算法取得最小生成樹
  ```

- **`Prim()`**: 使用 Prim 演算法計算最小生成樹。

  範例：
  ```cpp
  Graph mst = graph.Prim();  // 使用 Prim 演算法取得最小生成樹
  ```

- **`Sollin()`**: 使用 Sollin 演算法計算最小生成樹。

  範例：
  ```cpp
  Graph mst = graph.Sollin();  // 使用 Sollin 演算法取得最小生成樹
  ```

- **`Dijkstra(int source, int destination)`**: 使用 Dijkstra 演算法計算從 `source` 到 `destination` 的最短路徑。

  範例：
  ```cpp
  auto dijkstraPath = graph.Dijkstra(0, 3);  // 取得從節點 0 到節點 3 的最短路徑
  ```

- **`BellmanFord(int source, int destination)`**: 使用 Bellman-Ford 演算法計算從 `source` 到 `destination` 的最短路徑。

  範例：
  ```cpp
  auto bellmanFordPath = graph.BellmanFord(0, 3);  // 使用 Bellman-Ford 演算法取得從節點 0 到節點 3 的最短路徑
  ```

- **`Floyd()`**: 使用 Floyd 演算法計算所有節點對之間的最短路徑。

  範例：
  ```cpp
  auto floydPaths = graph.Floyd();  // 取得所有節點對之間的最短路徑
  ```

---

### 鄰接矩陣生成

- **`AdjMatSparse()`**: 生成鄰接矩陣作為 `SparseMatrix`。

  範例：
  ```cpp
  SparseMatrix adjMatrix = graph.AdjMatSparse();  // 取得鄰接矩陣作為 SparseMatrix
  ```

- **`AdjMatLinked()`**: 生成鄰接矩陣作為 `LinkedSparseMatrix`。

  範例：
  ```cpp
  LinkedSparseMatrix adjMatrix = graph.AdjMatLinked();  // 取得鄰接矩陣作為 LinkedSparseMatrix
  ```

---

### 運算子重載

- **`operator=(const Graph& other)`**: 用於深層複製另一個圖形的指派運算子。

  範例：
  ```cpp
  graph = otherGraph;  // 將另一個圖形複製到當前圖形
  ```

- **`operator==(const Graph& other) const`**: 比較兩個圖形是否相等的相等運算子（相同的結構和邊權重）。

  範例：
  ```cpp
  if (graph == otherGraph) {
      // 圖形相等
  }
  ```

- **`operator!=(const Graph& other) const`**: 檢查兩個圖形是否不相等的運算子。

  範例：
  ```cpp
  if (graph != otherGraph) {
      // 圖形不相等
  }
  ```

- **`operator<<(std::ostream& out, const Graph& graph)`**: 用於印出圖形的輸出串流運算子。

  範例：
  ```cpp
  std::cout << graph;  // 印出圖形
  ```

- **`operator>>(std::istream& in, Graph& graph)`**: 用於從輸入串流中讀取圖形的輸入串流運算子。
