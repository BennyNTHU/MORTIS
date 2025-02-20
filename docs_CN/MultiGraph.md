# `MultiGraph` 技術文件

## 概述

`MultiGraph.hpp` 標頭檔定義了一個 `MultiGraph` 類別，該類別代表一個多重圖（multigraph）資料結構。多重圖是一種可以在同一對節點之間有多條邊的圖。`MultiGraph` 類別支援加權和未加權的邊，以及有向和無向的圖。每個節點由一個整數表示，邊以三元組 `{u, v, w}` 儲存，其中 `u` 是源節點，`v` 是目標節點，`w` 是邊的權重（未加權圖中預設為 1）。

## 類別: `MultiGraph`

### 描述
`MultiGraph` 類別代表一個具有節點和邊的多重圖。它提供了添加/移除節點和邊、查詢圖的屬性以及執行操作（例如檢查圖是否為歐拉圖）的方法。

### 主要特性
- **加權/未加權**: 支援加權和未加權的邊。
- **有向/無向**: 可以作為有向圖或無向圖運作。
- **多重邊**: 允許同一對節點之間有多條邊。

### 建構函式與解構函式

#### `MultiGraph()`
- **描述**: 預設建構函式。建立一個空的未加權且無向的多重圖。
- **用法**:
  ```cpp
  MultiGraph graph;
  ```

#### `MultiGraph(int numNodes, bool weighted = false, bool directed = false)`
- **描述**: 建構函式。使用指定的節點數量初始化多重圖。
- **參數**:
  - `numNodes`: 圖中的節點數量。
  - `weighted`: 如果為 `true`，則圖為加權圖（預設為 `false`）。
  - `directed`: 如果為 `true`，則圖為有向圖（預設為 `false`）。
- **用法**:
  ```cpp
  MultiGraph graph(5, true, false);  // 建立一個加權、無向的圖，包含 5 個節點
  ```

#### `MultiGraph(const std::vector<int>& nodes, bool weighted = false, bool directed = false)`
- **描述**: 建構函式。從節點識別碼的向量初始化多重圖。
- **參數**:
  - `nodes`: 節點識別碼的向量。
  - `weighted`: 如果為 `true`，則圖為加權圖（預設為 `false`）。
  - `directed`: 如果為 `true`，則圖為有向圖（預設為 `false`）。
- **用法**:
  ```cpp
  std::vector<int> nodes = {1, 2, 3, 4, 5};
  MultiGraph graph(nodes, true, false);  // 建立一個加權、無向的圖，包含指定的節點
  ```

#### `~MultiGraph()`
- **描述**: 解構函式。通過刪除所有節點和邊來清理多重圖。
- **用法**: 當物件超出作用域時自動呼叫。

### 修改方法

#### `void AddNode(int node)`
- **描述**: 向多重圖中添加一個新節點。
- **參數**:
  - `node`: 要添加的節點識別碼。
- **用法**:
  ```cpp
  MultiGraph graph;
  graph.AddNode(1);  // 向圖中添加節點 1
  ```

#### `void RemoveNode(int node)`
- **描述**: 從多重圖中移除一個節點及其所有相關的邊。
- **參數**:
  - `node`: 要移除的節點識別碼。
- **用法**:
  ```cpp
  MultiGraph graph;
  graph.AddNode(1);
  graph.RemoveNode(1);  // 移除節點 1 及其所有邊
  ```

#### `void AddEdge(int u, int v, double w = 1)`
- **描述**: 向多重圖中添加一條邊。如果圖是未加權的，則權重強制為 1。
- **參數**:
  - `u`: 源節點。
  - `v`: 目標節點。
  - `w`: 邊的權重（預設為 1）。
- **用法**:
  ```cpp
  MultiGraph graph;
  graph.AddNode(1);
  graph.AddNode(2);
  graph.AddEdge(1, 2, 3.5);  // 添加一條從節點 1 到節點 2 的邊，權重為 3.5
  ```

#### `void RemoveEdge(int u, int v)`
- **描述**: 從多重圖中移除一條邊。
- **參數**:
  - `u`: 源節點。
  - `v`: 目標節點。
- **用法**:
  ```cpp
  MultiGraph graph;
  graph.AddNode(1);
  graph.AddNode(2);
  graph.AddEdge(1, 2, 3.5);
  graph.RemoveEdge(1, 2);  // 移除從節點 1 到節點 2 的邊
  ```

### 全域屬性

#### `bool IsEmpty() const`
- **描述**: 檢查多重圖是否為空（即沒有節點）。
- **回傳值**: 如果圖為空，則回傳 `true`，否則回傳 `false`。
- **用法**:
  ```cpp
  MultiGraph graph;
  bool empty = graph.IsEmpty();  // empty 為 true
  ```

#### `bool isEulerian() const`
- **描述**: 檢查多重圖是否為歐拉圖（即具有歐拉迴路）。
- **回傳值**: 如果圖為歐拉圖，則回傳 `true`，否則回傳 `false`。
- **用法**:
  ```cpp
  MultiGraph graph;
  graph.AddNode(1);
  graph.AddNode(2);
  graph.AddEdge(1, 2);
  bool eulerian = graph.isEulerian();  // eulerian 為 false（沒有歐拉迴路）
  ```

#### `int NumberOfNodes() const`
- **描述**: 回傳多重圖中的節點總數。
- **回傳值**: 節點數量，以整數表示。
- **用法**:
  ```cpp
  MultiGraph graph;
  graph.AddNode(1);
  graph.AddNode(2);
  int numNodes = graph.NumberOfNodes();  // numNodes 為 2
  ```

#### `int NumberOfEdges() const`
- **描述**: 回傳多重圖中的邊總數。
- **回傳值**: 邊的數量，以整數表示。
- **用法**:
  ```cpp
  MultiGraph graph;
  graph.AddNode(1);
  graph.AddNode(2);
  graph.AddEdge(1, 2);
  int numEdges = graph.NumberOfEdges();  // numEdges 為 1
  ```

### 局部屬性

#### `int Degree(int u) const`
- **描述**: 回傳節點的度數（與其相連的邊的數量）。
- **參數**:
  - `u`: 節點識別碼。
- **回傳值**: 節點的度數，以整數表示。
- **用法**:
  ```cpp
  MultiGraph graph;
  graph.AddNode(1);
  graph.AddNode(2);
  graph.AddEdge(1, 2);
  int degree = graph.Degree(1);  // degree 為 1
  ```

#### `int EdgeCount(int u, int v) const`
- **描述**: 回傳兩個節點之間的邊的數量。
- **參數**:
  - `u`: 源節點。
  - `v`: 目標節點。
- **回傳值**: `u` 和 `v` 之間的邊的數量，以整數表示。
- **用法**:
  ```cpp
  MultiGraph graph;
  graph.AddNode(1);
  graph.AddNode(2);
  graph.AddEdge(1, 2);
  graph.AddEdge(1, 2);
  int edgeCount = graph.EdgeCount(1, 2);  // edgeCount 為 2
  ```

### 運算子重載

#### `MultiGraph& operator=(const MultiGraph& other)`
- **描述**: 指派運算子。執行另一個多重圖的深層複製。
- **參數**:
  - `other`: 要複製的 `MultiGraph`。
- **回傳值**: 當前多重圖的參考。
- **用法**:
  ```cpp
  MultiGraph graph1;
  graph1.AddNode(1);
  MultiGraph graph2;
  graph2 = graph1;  // graph2 現在是 graph1 的副本
  ```

#### `bool operator==(const MultiGraph& other) const`
- **描述**: 相等運算子。檢查兩個多重圖是否具有相同的結構和邊權重。
- **參數**:
  - `other`: 要比較的 `MultiGraph`。
- **回傳值**: 如果多重圖相等，則回傳 `true`，否則回傳 `false`。
- **用法**:
  ```cpp
  MultiGraph graph1;
  graph1.AddNode(1);
  MultiGraph graph2;
  graph2.AddNode(1);
  bool equal = (graph1 == graph2);  // equal 為 true
  ```

#### `bool operator!=(const MultiGraph& other) const`
- **描述**: 不等運算子。檢查兩個多重圖是否不相同。
- **參數**:
  - `other`: 要比較的 `MultiGraph`。
- **回傳值**: 如果多重圖不相等，則回傳 `true`，否則回傳 `false`。
- **用法**:
  ```cpp
  MultiGraph graph1;
  graph1.AddNode(1);
  MultiGraph graph2;
  graph2.AddNode(2);
  bool notEqual = (graph1 != graph2);  // notEqual 為 true
  ```

#### `friend std::ostream& operator<<(std::ostream& out, const MultiGraph& multigraph)`
- **描述**: 重載 `<<` 運算子，用於將多重圖以邊三元組 `{u, v, w}` 的形式印出。
- **參數**:
  - `out`: 輸出串流。
  - `multigraph`: 要印出的 `MultiGraph`。
- **回傳值**: 輸出串流。
- **用法**:
  ```cpp
  MultiGraph graph;
  graph.AddNode(1);
  graph.AddNode(2);
  graph.AddEdge(1, 2, 3.5);
  std::cout << graph;  // 以邊三元組的形式印出多重圖
  ```

#### `friend std::istream& operator>>(std::istream& in, MultiGraph& multigraph)`
- **描述**: 重載 `>>` 運算子，用於以邊三元組 `{u, v, w}` 的形式讀取多重圖。
- **參數**:
  - `in`: 輸入串流。
  - `multigraph`: 要讀取的 `MultiGraph`。
- **回傳值**: 輸入串流。
- **用法**:
  ```cpp
  MultiGraph graph;
  std::cin >> graph;  // 從輸入中讀取多重圖
  ```

## 範例用法

```cpp
#include "MultiGraph.hpp"
#include <iostream>

int main() {
    // 建立一個加權、無向的多重圖
    MultiGraph graph(3, true, false);

    // 添加邊
    graph.AddEdge(1, 2, 3.5);
    graph.AddEdge(2, 3, 2.0);
    graph.AddEdge(1, 3, 1.5);

    // 印出圖
    std::cout << "圖: " << graph << std::endl;

    // 檢查屬性
    std::cout << "節點數量: " << graph.NumberOfNodes() << std::endl;
    std::cout << "邊數量: " << graph.NumberOfEdges() << std::endl;
    std::cout << "節點 1 的度數: " << graph.Degree(1) << std::endl;
    std::cout << "節點 1 和 2 之間的邊數量: " << graph.EdgeCount(1, 2) << std::endl;

    // 移除一條邊
    graph.RemoveEdge(1, 2);
    std::cout << "移除邊 (1, 2) 後: " << graph << std::endl;

    return 0;
}
```

## 潛在錯誤與邊界情況

1. **無效的節點識別碼**: 在添加或移除節點/邊時，確保節點識別碼是有效的（即它們存在於圖中）。無效的識別碼可能導致執行時錯誤。
2. **重複的節點/邊**: 添加重複的節點或邊可能不會導致錯誤，但可能導致意外行為。除非有意為之，否則確保節點/邊是唯一的。
3. **記憶體管理**: 當動態分配節點和邊時，請確保正確清理以避免記憶體洩漏。

## 相依性

- **GeneralArray.hpp**: `MultiGraph` 類別使用 `GeneralArray` 來儲存邊列表。請確保此檔案已包含並在專案中正確配置。
- **標準函式庫**: 標頭檔包含 `<vector>` 和 `<variant>`，這些是 C++ 標準函式庫的一部分。請確保您的環境已配置為使用標準函式庫。

## 總結

`MultiGraph.hpp` 檔案提供了一個靈活的多重圖資料結構實作，支援加權和未加權的邊，以及有向和無向的圖。通過遵循提供的範例和指南，您可以在專案中有效地使用此類別來建立和操作多重圖。
