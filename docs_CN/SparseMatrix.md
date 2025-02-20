# `SparseMatrix.hpp` 文件說明

## 概觀

`SparseMatrix.hpp` 標頭文件定義了一個 `SparseMatrix` 類別，該類別使用 `MatrixTerm` 物件陣列來表示稀疏矩陣。此類別提供了矩陣運算、存取和操作的方法，如加法、減法、乘法、轉置和範數計算。由於僅表示非零元素，矩陣元素的儲存非常高效，有助於節省記憶體。

---

## 主要元件

### `MatrixTerm` 類別

`MatrixTerm` 代表稀疏矩陣中的單一非零元素。每個項目儲存以下資料：
- **`row`**：矩陣項目的行索引。
- **`col`**：矩陣項目的列索引。
- **`value`**：項目的值，可以是 `int` 或 `double`（使用 `std::variant`）。

#### 方法：
- **`get_row()`**：返回項目的行索引。
- **`get_col()`**：返回項目的列索引。
- **`get_value()`**：返回項目的值，該值儲存為 `std::variant<int, double>`。
- **`write_term(int r, int c, const std::variant<int, double>& v)`**：使用新的行、列和數值更新項目。
- **運算子重載**：
  - **`operator->()`**：重載指標運算子，返回指向當前項目的指標。
  - **`operator*()`**：重載解引用運算子，返回當前項目。
  - **`operator==(const MatrixTerm& other)`**：比較兩個矩陣項目的相等性。
  - **`operator!=(const MatrixTerm& other)`**：比較兩個矩陣項目的不相等性。

---

### `SparseMatrix` 類別

`SparseMatrix` 類別使用動態配置的 `MatrixTerm` 物件陣列來表示稀疏矩陣。它僅儲存矩陣中的非零元素，對於具有大量零元素的大型矩陣，顯著降低了記憶體使用。

#### 成員變數：
- **`rows`**：矩陣的行數。
- **`cols`**：矩陣的列數。
- **`terms`**：矩陣中的非零項數量。
- **`capacity`**：用於儲存矩陣項的陣列容量。
- **`smArray`**：指向 `MatrixTerm` 物件的動態配置陣列的指標。

#### 建構子與解構子：
- **`SparseMatrix()`**：預設建構子，初始化一個空的稀疏矩陣。
- **`SparseMatrix(int r, int c, int t = 0)`**：使用指定的行數 `r`、列數 `c` 和可選的非零項數量 `t` 初始化稀疏矩陣。
- **`SparseMatrix(const SparseMatrix& b)`**：複製建構子，建立另一個稀疏矩陣的深層副本。
- **`~SparseMatrix()`**：解構子，釋放為矩陣項分配的動態記憶體。

#### 成員函式：
- **`get_rows()`**：返回矩陣的行數。
- **`get_cols()`**：返回矩陣的列數。
- **`get_terms()`**：返回矩陣中的非零項數量。
- **`get_capacity()`**：返回矩陣項陣列的容量。
- **`get_smArray()`**：返回矩陣項陣列的指標。

- **`StoreNum(const std::variant<int, double>& num, int r, int c)`**：將非零值 `num` 儲存在指定的行 `r` 和列 `c` 中。如果 `num` 為零，則不儲存該項。
  
- **`ChangeSize1D(int newSize)`**：更改矩陣項陣列的大小。
  
- **`printMatrix()`**：以密集格式列印矩陣，主要用於除錯。

- **`FastTranspose()`**：返回一個新的稀疏矩陣，該矩陣是當前矩陣的轉置，並使用高效的演算法來計算。

- **`Norm()`**：返回矩陣的 Frobenius 範數，計算方法為非零元素平方和的平方根。

#### 運算子重載：
- **`operator+(const SparseMatrix& b)`**：將兩個稀疏矩陣相加並返回結果。
- **`operator-(const SparseMatrix& b)`**：將一個稀疏矩陣從另一個稀疏矩陣中減去並返回結果。
- **`operator*(const SparseMatrix& b)`**：將兩個稀疏矩陣相乘並返回結果。
- **`operator*(const std::vector<double>& vec)`**：將稀疏矩陣與一個密集向量相乘並返回結果。
- **`operator*(std::variant<int, double> scalar)`**：將矩陣乘以標量並返回結果。

- **`operator=(const SparseMatrix& other)`**：賦值運算子，將另一個稀疏矩陣的內容複製過來。
- **`operator==(const SparseMatrix& other)`**：檢查兩個稀疏矩陣是否相等（項目相同，值相同）。
- **`operator!=(const SparseMatrix& other)`**：檢查兩個稀疏矩陣是否不相等。
- **`operator[](int index)`**：返回矩陣內部項陣列中索引 `i` 處的項目值。

#### 輸入/輸出運算子：
- **`operator<<(std::ostream& out, const SparseMatrix& mat)`**：將稀疏矩陣以可讀格式輸出。
- **`operator>>(std::istream& in, SparseMatrix& mat)`**：從輸入流中讀取稀疏矩陣。

---

## 範例使用

```cpp
#include "SparseMatrix.hpp"

int main() {
    // 創建一個 3x3 的稀疏矩陣，並包含 2 個非零項
    SparseMatrix mat(3, 3, 2);
    
    // 在矩陣中儲存項目
    mat.StoreNum(3.5, 0, 1);  // 設定 (0, 1) 位置的值為 3.5
    mat.StoreNum(4.2, 2, 2);  // 設定 (2, 2) 位置的值為 4.2
    
    // 列印矩陣
    mat.printMatrix();

    // 獲取矩陣的 Frobenius 範數
    double norm = mat.Norm();
    std::cout << "Frobenius Norm: " << norm << std::endl;

    // 轉置矩陣
    SparseMatrix transposed = mat.FastTranspose();
    std::cout << "Transposed Matrix: " << transposed << std::endl;

    // 加法操作
    SparseMatrix mat2(3, 3, 1);
    mat2.StoreNum(1.5, 1, 1);
    SparseMatrix result = mat + mat2;
    std::cout << "Result of Addition: " << result << std::endl;

    return 0;
}
```

---

## 可能的錯誤與邊界情形

1. **零項**：在加法或減法操作中，確保兩個矩陣擁有相同數量的非零項，或處理其中一個矩陣有更多非零項的情況。
2. **越界存取**：確保在 `StoreNum` 和其他函式中使用的行列索引在有效範圍內。
3. **空矩陣**：確保處理矩陣可能為空的邊界情況（例如，零行或零列）。
4. **大型矩陣**：對於非常大的稀疏矩陣，確保矩陣已正確調整大小，並處理任何記憶體分配失敗的情況。

---

## 相依性

- **C++ 標準庫**：該類別使用了標準 C++ 函式庫，如 `<iostream>`、`<vector>`、`<cmath>` 和 `<algorithm>`。
- **C++17 或更高版本**：需要 `std::variant`。
