# `LinkedSparseMatrix` 技術文件

## 概述

`LinkedSparseMatrix.hpp` 定義了 `LinkedSparseMatrix` 類別，用於管理稀疏矩陣，其中僅儲存非零項，並將這些項表示為鏈結節點。`LinkedMatrixTerm` 類別用於表示矩陣中的每個項，包含行索引、列索引和值（可以是整數或浮點數）。

## 主要元件

### `LinkedMatrixTerm.hpp`

#### **建構函式與解構函式**
- **`LinkedMatrixTerm()`**: 預設建構函式。
  
  範例：
  ```cpp
  LinkedMatrixTerm term;  // 建立一個具有預設值的空 LinkedMatrixTerm
  ```

- **`LinkedMatrixTerm(int r, int c, std::variant<int, double> v)`**: 使用指定的行、列和值初始化一個項。

  範例：
  ```cpp
  LinkedMatrixTerm term(0, 0, 5);  // 建立一個行 0、列 0、值為 5 的項
  ```

#### **存取器與設置器**
- **`getRow()`**: 回傳項的行索引。

  範例：
  ```cpp
  int row = term.getRow();  // 取得項的行（回傳 0）
  ```

- **`getCol()`**: 回傳項的列索引。

  範例：
  ```cpp
  int col = term.getCol();  // 取得項的列（回傳 0）
  ```

- **`getValue()`**: 回傳項的值（可以是 `int` 或 `double`）。

  範例：
  ```cpp
  auto value = term.getValue();  // 取得項的值（回傳 5）
  ```

- **`setRow(int r)`**: 設置項的行索引。

  範例：
  ```cpp
  term.setRow(1);  // 將項的行設置為 1
  ```

- **`setCol(int c)`**: 設置項的列索引。

  範例：
  ```cpp
  term.setCol(2);  // 將項的列設置為 2
  ```

- **`setValue(std::variant<int, double> v)`**: 設置項的值。

  範例：
  ```cpp
  term.setValue(3.5);  // 將項的值設置為 3.5
  ```

#### **串流運算子**
- **`operator<<`**: 用於印出項的重載運算子。

  範例：
  ```cpp
  std::cout << term;  // 印出項，例如：(0,0): 5
  ```

- **`operator>>`**: 用於讀取項的重載運算子。

  範例：
  ```cpp
  std::cin >> term;  // 從輸入中讀取項（例如："1 1 2.5"）
  ```

---

### `LinkedSparseMatrix.hpp`

#### **建構函式與解構函式**
- **`LinkedSparseMatrix()`**: 初始化一個空的稀疏矩陣。

  範例：
  ```cpp
  LinkedSparseMatrix matrix;  // 建立一個空的稀疏矩陣
  ```

- **`LinkedSparseMatrix(int r, int c, int t=0)`**: 使用指定的維度和可選的非零項數量初始化稀疏矩陣。

  範例：
  ```cpp
  LinkedSparseMatrix matrix(3, 3);  // 建立一個 3x3 的矩陣
  ```

- **`LinkedSparseMatrix(const LinkedSparseMatrix &b)`**: 複製建構函式，通過複製另一個矩陣來初始化稀疏矩陣。

  範例：
  ```cpp
  LinkedSparseMatrix matrix2 = matrix;  // 建立矩陣的副本
  ```

- **`~LinkedSparseMatrix()`**: 解構函式，清理稀疏矩陣。

  範例：
  ```cpp
  // 當矩陣超出作用域時自動清理
  ```

#### **存取器**
- **`get_rows()`**: 回傳矩陣的行數。

  範例：
  ```cpp
  int rows = matrix.get_rows();  // 取得矩陣的行數（回傳 3）
  ```

- **`get_cols()`**: 回傳矩陣的列數。

  範例：
  ```cpp
  int cols = matrix.get_cols();  // 取得矩陣的列數（回傳 3）
  ```

- **`get_terms()`**: 回傳矩陣中非零項的數量。

  範例：
  ```cpp
  int terms = matrix.get_terms();  // 取得矩陣中非零項的數量
  ```

#### **矩陣操作**
- **`StoreNum(const std::variant<int, double>& num, const int r, const int c)`**: 在矩陣的位置 `(r, c)` 儲存值 `num`。如果值為非零，則將新項添加到矩陣中。

  範例：
  ```cpp
  matrix.StoreNum(5, 0, 0);  // 在位置 (0, 0) 儲存 5
  matrix.StoreNum(3.5, 1, 2);  // 在位置 (1, 2) 儲存 3.5
  ```

- **`printMatrix()`**: 以密集格式印出矩陣（用於除錯）。

  範例：
  ```cpp
  matrix.printMatrix();  // 以密集格式印出矩陣
  ```

- **`Clear()`**: 清除矩陣，移除所有非零項。

  範例：
  ```cpp
  matrix.Clear();  // 清除矩陣
  ```

- **`FastTranspose()`**: 使用稀疏矩陣的高效演算法回傳矩陣的轉置版本。

  範例：
  ```cpp
  LinkedSparseMatrix transposed = matrix.FastTranspose();  // 取得轉置矩陣
  ```

- **`Norm()`**: 計算矩陣的 Frobenius 範數，即所有非零項平方和的平方根。

  範例：
  ```cpp
  double norm = matrix.Norm();  // 取得矩陣的 Frobenius 範數
  ```

#### **運算子重載**
- **`operator+`**: 將兩個稀疏矩陣相加並回傳結果。

  範例：
  ```cpp
  LinkedSparseMatrix result = matrix + matrix2;  // 將矩陣與 matrix2 相加
  ```

- **`operator-`**: 將一個稀疏矩陣減去另一個稀疏矩陣並回傳結果。

  範例：
  ```cpp
  LinkedSparseMatrix result = matrix - matrix2;  // 將 matrix2 從矩陣中減去
  ```

- **`operator*` (矩陣乘法)**: 將兩個稀疏矩陣相乘並回傳結果。

  範例：
  ```cpp
  LinkedSparseMatrix result = matrix * matrix2;  // 矩陣乘法
  ```

- **`operator*` (向量乘法)**: 將稀疏矩陣與密集向量相乘並回傳結果。

  範例：
  ```cpp
  std::vector<double> vec = {1.0, 2.0, 3.0};
  LinkedSparseMatrix result = matrix * vec;  // 將矩陣與向量相乘
  ```

- **`operator*` (純量乘法)**: 將稀疏矩陣乘以純量（可以是整數或浮點數）。

  範例：
  ```cpp
  LinkedSparseMatrix result = matrix * 2;  // 將矩陣乘以純量 2
  ```

- **`operator=`**: 指派運算子，用於複製另一個稀疏矩陣。

  範例：
  ```cpp
  matrix = matrix2;  // 將 matrix2 的內容複製到矩陣
  ```

- **`operator==`**: 比較兩個稀疏矩陣是否相等（相同的維度和非零項）。

  範例：
  ```cpp
  if (matrix == matrix2) {
      // 矩陣相等
  }
  ```

- **`operator!=`**: 比較兩個稀疏矩陣是否不相等。

  範例：
  ```cpp
  if (matrix != matrix2) {
      // 矩陣不相等
  }
  ```

---

## 潛在錯誤與邊界情況

1. **索引超出範圍**: 使用 `StoreNum()` 插入值時，確保行和列索引在矩陣範圍內。

2. **矩陣大小不匹配**: 執行矩陣乘法或加法等操作時，確保矩陣是相容的（例如，第一個矩陣的列數必須等於第二個矩陣的行數才能進行乘法）。

3. **空矩陣**: 在執行矩陣加法、乘法或範數計算時，小心處理空矩陣的操作。確保矩陣具有非零項後再執行這些操作。

4. **記憶體管理**: 由於矩陣使用動態記憶體（通過鏈結節點），請確保在複製或刪除矩陣時正確管理記憶體。

---

## 相依性

- **`LinkedMatrixTerm.hpp`**: `LinkedSparseMatrix` 類別依賴於 `LinkedMatrixTerm` 類別來表示矩陣中的非零項。請確保 `LinkedMatrixTerm` 已正確實作。
- **其他包含檔案**: 該檔案包含了 `Node.hpp`、`DoubleNode.hpp` 和迭代器（`ChainIterator`、`DLIterator`），這些需要正確定義和實作以確保功能正常。
