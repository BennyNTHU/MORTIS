# **MORTIS：C++資料結構函式庫專案**
#### MORTIS: Memory Oriented Resource Toolkit for Information Structures

![image](./media/mortis.jpg)

## **1. 摘要**

**MORTIS** 是一個基於 C++17 的資料結構函式庫。本專案實作了各種資料結構和抽象資料型別（ADT），包括：

- 陣列結構  
- 基於鏈結串列(Linked lists)的結構  
- 容器
- 圖
- 樹
- 雜湊表

其中部分資料結構也被定義為 **MortisInvariant**。

以下是 MORTIS 提供的資料結構總覽：

| **類別**  | **資料結構**       | **描述**                                                                                                                                         | **文檔（中文）**                      | **文檔（英文）**                      | **支持的資料型別** |
|-----------|------------------|-------------------------------------------------------------------------------------------------------------|---------------------------------|---------------------------------|-------------------------|
| **陣列**  | **GeneralArray**  | 一個動態陣列，可存儲 C++ 內建型別。                                                                        | [中文](./docs_CN/GeneralArray.md) | [English](./docs_EN/GeneralArray.md) |                         |
|           | **Polynomial**    | 表示多項式，係數限制為浮點數或整數，次數為整數。                                                            | [中文](./docs_CN/Polynomial.md) | [English](./docs_EN/Polynomial.md) |                         |
|           | **SparseMatrix**  | 稀疏矩陣，元素限制為浮點數或整數。                                                                          | [中文](./docs_CN/SparseMatrix.md) | [English](./docs_EN/SparseMatrix.md) |                         |
|           | **String**        | 增強版 C 字符串，提供額外的字符串操作函數。                                                                | [中文](./docs_CN/String.md) | [English](./docs_EN/String.md) |                         |
| **容器**  | **Bag**           | 支持重複元素的多重集合容器，具有基本的插入、刪除和搜尋操作。                                                  | [中文](./docs_CN/Bag.md) | [English](./docs_EN/Bag.md) |                         |
|           | **DeQue**         | 雙端佇列（繼承自 Bag）。                                                                                | [中文](./docs_CN/DeQue.md) | [English](./docs_EN/DeQue.md) |                         |
|           | **Dictionary**    | 一種支持 Map-Reduce 功能的多重映射結構。                                                                   | [中文](./docs_CN/Dictionary.md) | [English](./docs_EN/Dictionary.md) |                         |
|           | **Stack**         | 堆疊結構（繼承自 Bag）。                                                                                     | [中文](./docs_CN/Stack.md) | [English](./docs_EN/Stack.md) |                         |
|           | **Queue**         | 佇列（繼承自 Stack）。                                                                                     | [中文](./docs_CN/Queue.md) | [English](./docs_EN/Queue.md) |                         |
|           | **CirQue**        | 環狀佇列（繼承自 DeQue）。                                                                               | [中文](./docs_CN/CirQue.md) | [English](./docs_EN/CirQue.md) |                         |
| **鏈結串列**  | **Node, ChainIterator, LinkedList** | 基本的單鏈結串列結構。                                                                                    | [中文](./docs_CN/LinkedList.md) | [English](./docs_EN/LinkedList.md) |                         |
|           | **CircularList**  | 環狀單鏈結串列（繼承自 LinkedList）。                                                                      | [中文](./docs_CN/CircularList.md) | [English](./docs_EN/CircularList.md) |                         |
|           | **DoubleNode, DLIterator, DoublyLinkedList** | 雙向鏈結串列結構。                                                                                      | [中文](./docs_CN/DoublyLinkedList.md) | [English](./docs_EN/DoublyLinkedList.md) |                         |
|           | **CircularDoubleList**  | 環狀雙向鏈結串列（繼承自 DoublyLinkedList）。                                                             | [中文](./docs_CN/CircularDoubleList.md) | [English](./docs_EN/CircularDoubleList.md) |                         |
|           | **LinkedPolynomial**  | 使用鏈結結構表示的多項式。                                                                            | [中文](./docs_CN/LinkedPolynomial.md) | [English](./docs_EN/LinkedPolynomial.md) |                         |
|           | **LinkedSparseMatrix**  | 使用鏈結結構表示的稀疏矩陣。                                                                          | [中文](./docs_CN/LinkedSparseMatrix.md) | [English](./docs_EN/LinkedSparseMatrix.md) |                         |
| **雜湊表** | **HashTable**    | 通用雜湊表實作。                                                                                       | [中文](./docs_CN/HashTable.md) | [English](./docs_EN/HashTable.md) |                         |
|           | **BloomFilter**   | BloomFilter實作。                                                                                       | [中文](./docs_CN/BloomFilter.md) | [English](./docs_EN/BloomFilter.md) |                         |
| **樹結構** | **BinaryTree**   | 通用二元樹結構。                                                                                       | [中文](./docs_CN/BinaryTree.md) | [English](./docs_EN/BinaryTree.md) |                         |
|           | **BinaryTreeNode** | 二元樹節點型別。                                                                                     | [中文](./docs_CN/BinaryTreeNode.md) | [English](./docs_EN/BinaryTreeNode.md) |                         |
|           | **BinarySearchTree** | 二元搜尋樹（繼承自 BinaryTree）。                                                                  | [中文](./docs_CN/BinarySearchTree.md) | [English](./docs_EN/BinarySearchTree.md) |                         |
|           | **MaxHeap**       | 最大堆積（繼承自 BinaryTree）。                                                                          | [中文](./docs_CN/MaxHeap.md) | [English](./docs_EN/MaxHeap.md) |                         |
|           | **MinHeap**       | 最小堆積（繼承自 MaxHeap）。                                                                           | [中文](./docs_CN/MinHeap.md) | [English](./docs_EN/MinHeap.md) |                         |
|           | **Set**           | 集合資料結構（繼承自 BinarySearchTree），支持交集、聯集、差集等操作。                                 | [中文](./docs_CN/Set.md) | [English](./docs_EN/Set.md) |                         |
| **圖結構** | **Graph**        | 不支持多重邊的圖。                                                                                | [中文](./docs_CN/Graph.md) | [English](./docs_EN/Graph.md) |                         |
|           | **MultiGraph**  | 支持多重邊的圖，可設置為有向/無向、加權/無加權圖。                                               | [中文](./docs_CN/MultiGraph.md) | [English](./docs_EN/MultiGraph.md) |                         |

---

## **2. 快速入門**
<!--此部分暫時留空-->

---

## **3. Q & A**

- **Q: 為什麼這個專案叫 MORTIS？**  
  **A:** 致敬傳奇少女樂團 **Ave Mujica** 的吉他手 **Mortis**。

- **Q: MORTIS有實作有鏈結堆疊（Linked Stack）或鏈結佇列（Linked Queue）嗎？**  
  **A:** 鏈結堆疊或鏈結佇列可以當作鏈結結構來操作。

- **Q: 為什麼沒有實作廣義表（Generalized List）？**  
  **A:** 我認為廣義表的實際應用很少。

- **Q: 你是 MyGO 廚嗎？**  
  **A:** 是。

![image](./media/mortis2.png)

## 參考資料

> [1] E. Horowitz, S. Sahni, and D. Mehta, *Fundamentals of Data Structures in C++*, 2nd ed. New Jersey: Silicon Press, 2006.

> [2] 清大電機系鐘太郎教授於109學年度下學期開設的「資料結構」課程（開課單位：國立清華大學電資院學士班）