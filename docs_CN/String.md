# `String.hpp` 文件說明

## 概觀

`String.hpp` 定義了一個 `String` 類別，旨在管理和操作 C++ 中的字串。該類別提供了多種字串操作方法，如字串連接、子字串擷取、字元刪除和字串反轉。此外，該類別支援各種運算子重載，並包含一個用於模式匹配的失敗函式。

---

## 主要元件

### `String` 類別

`String` 類別模擬了動態字串，支援字串連接、子字串擷取、字元刪除和字串反轉等操作。該類別利用失敗函式 (`f`) 來進行模式匹配，並提供基本的字串操作，如相等性檢查和索引。

#### 成員變數：
- **`length`**：字串的長度。
- **`str`**：指向字串的指標，字串以動態字元陣列儲存。
- **`f`**：指向整數陣列的指標，用於儲存失敗函式（用於字串模式匹配）。

#### 建構子與解構子：
- **`String()`**：預設建構子，初始化為空字串。
- **`String(const char* init)`**：建構子，使用 C 風格字串初始化。
- **`String(const String &s)`**：複製建構子，從另一個 `String` 物件初始化字串。
- **`~String()`**：解構子，釋放為字串和失敗函式分配的動態記憶體。

#### 字串操作方法：
- **`Concat(String t)`**：將當前字串與另一個字串 `t` 連接，並返回結果。
  
  範例：
  ```cpp
  String result = str1.Concat(str2);  // 連接 str1 和 str2
  ```

- **`Substr(int i, int j)`**：返回從索引 `i` 開始長度為 `j` 的子字串。
  
  範例：
  ```cpp
  String sub = str.Substr(2, 5);  // 從索引 2 開始，長度為 5 的子字串
  ```

- **`Delete(int start, int len)`**：從索引 `start` 開始刪除長度為 `len` 的字元。
  
  範例：
  ```cpp
  String result = str.Delete(2, 3);  // 刪除從索引 2 開始的 3 個字元
  ```

- **`CharDelete(char c)`**：刪除字串中所有出現的字元 `c`。
  
  範例：
  ```cpp
  String result = str.CharDelete('a');  // 移除所有的 'a' 字元
  ```

- **`Reverse()`**：反轉當前字串並返回結果。
  
  範例：
  ```cpp
  String reversed = str.Reverse();  // 反轉字串
  ```

#### 存取方法：
- **`FailureFunction()`**：計算並儲存字串的失敗函式。
  
- **`getString()`**：返回指向底層 C 風格字串的指標。
  
- **`getFailure()`**：返回指向失敗函式陣列的指標。

- **`Length()`**：返回字串的長度。
  
  範例：
  ```cpp
  int len = str.Length();  // 獲取字串長度
  ```

- **`FastFind(String pat)`**：使用失敗函式查找字串中首次出現的模式 `pat` 的索引。如果找不到模式，則返回 `-1`。
  
  範例：
  ```cpp
  int index = str.FastFind("pattern");  // 查找 "pattern" 的索引
  ```

#### 運算子重載：
- **`operator!()`**：如果字串為空，則返回 `true`，否則返回 `false`。
  
  範例：
  ```cpp
  bool isEmpty = !str;  // 檢查字串是否為空
  ```

- **`operator[](int index)`**：返回指定索引的字元。
  
  範例：
  ```cpp
  char ch = str[2];  // 獲取索引為 2 的字元
  ```

- **`operator=(const String&)`**：賦值運算子，將另一個 `String` 物件的值複製到當前物件。
  
  範例：
  ```cpp
  str1 = str2;  // 將 str2 的值賦給 str1
  ```

- **`operator==(String t1, String t2)`**：比較兩個字串是否相等，如果相等則返回 `true`。
  
  範例：
  ```cpp
  bool isEqual = (str1 == str2);  // 檢查 str1 和 str2 是否相等
  ```

- **`operator!=(String t1, String t2)`**：比較兩個字串是否不相等，如果不相等則返回 `true`。
  
  範例：
  ```cpp
  bool isNotEqual = (str1 != str2);  // 檢查 str1 和 str2 是否不相等
  ```

#### 輸入/輸出運算子：
- **`operator<<(std::ostream& out, const String& mat)`**：將字串輸出到輸出流。
  
  範例：
  ```cpp
  std::cout << str;  // 將字串輸出到終端機
  ```

- **`operator>>(std::istream& in, String& mat)`**：從輸入流中讀取字串。
  
  範例：
  ```cpp
  std::cin >> str;  // 從使用者輸入讀取字串
  ```

---

## 範例使用

```cpp
#include "String.hpp"

int main() {
    // 從 C 風格字串創建字串
    String str1("Hello");

    // 使用複製建構子創建字串
    String str2(str1);

    // 連接兩個字串
    String str3 = str1.Concat(str2);  // 結果: "HelloHello"

    // 子字串範例
    String sub = str3.Substr(0, 5);  // 結果: "Hello"

    // 刪除字串中的字元
    String newStr = str3.Delete(5, 5);  // 結果: "Hello"

    // 反轉字串
    String reversed = str1.Reverse();  // 結果: "olleH"

    // 使用 FastFind 函式查找模式
    int index = str3.FastFind("Hello");  // 結果: 0 (首次出現 "Hello" 的索引)

    // 輸出字串
    std::cout << "String: " << str1 << std::endl;

    return 0;
}
```

---

## 可能的錯誤與邊界情形

1. **超出邊界的存取**：使用下標運算子 `operator[]` 和 `Substr()` 時要小心，確保索引在有效範圍內。
2. **空字串**：`operator!()` 方法可用於檢查字串是否為空。確保在程式中妥善處理空字串。
3. **記憶體管理**：該類別使用動態記憶體配置來儲存字串和失敗函式，因此請確保字串在使用完後能正確釋放，以避免記憶體洩漏。
4. **找不到模式**：`FastFind()` 函式在找不到模式時會返回 `-1`，請確保在程式中妥善處理此情況。

---

## 相依性

- **C++ 標準函式庫**：該類別使用了標準 C++ 函式庫，如 `<iostream>`、`<cstring>` 和 `<math.h>`。
