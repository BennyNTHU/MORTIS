# Issues

## 1. 需要實做的資料結構以及資料型別的限制：

### array
- (O) `GeneralArray`: 需要能夠放入`C++`內建的資料型別
- (O) `Polynomial`: 係數限定為浮點數或整數，次數限定為整數
- (O) `SparseMatrix`: 元素限定為浮點數或整數
- (O) `String`: `cstring`加上各種功能的字串
以上四者與`C++`各種資料型別和稱`MortisInvariant`

### container
- (O) `Bag`: 即multisets
- (O) `DeQue`（繼承自`Bag`）
- (O) `Dictionary`: 為multimap，支援map-reduce功能
- (O) `Stack`（繼承自`Bag`）
- (O) `Queue`（繼承自`Stack`）
- (O) `CirQue`（繼承自`DeQue`）
- (O) `Dictionary`
這裡的資料結構除了`Dictionary`以外都要能夠放入`MortisInvariant`

### chain
- (O) `Node`, `ChainIterator`, `LinkedList`
- (O) `CircularList`（繼承自`LinkedList`）
- (O) `DoubleNode`（繼承自`Node`）, `DLIterator`（繼承自`ChainIterator`）, `DoublyLinkedList`
- (O) `CircularDoubleList`（繼承自`DoublyLinkedList`）
- (O) `LinkedPolynomial`
- (O) `LinkedSparseMatrix`
所有chain的結構，都只能夠放入相同的資料類別，比如要馬全部放`int`，`double`, `char`或`string`

### hash table
- (O) `HashTable`
- (O) `BloomFilter`
- 所有hash table的結構，都只能夠放入相同的資料類別，比如要馬全部放`int`，`double`, `char`或`string`

### tree
- (O) `BinarySearchTree`（繼承自`BinaryTree`）
- (O) `BinaryTree`
- (O) `BinaryTreeNode`
- (O) `MaxHeap`（繼承自`BinaryTree`）
- (O) `MinHeap`（繼承自`MaxHeap`）
- (O) `Set`
所有tree的結構，都只能夠放入相同的資料類別，比如要馬全部放`int`，`double`, `char`或`string`

### graph
- `Graph`: 不支援multiple edge
- `GeneralGraph`: 支援multiple edge
由支援multiple edge的存在與否來分類。directed/undirected, weighted/unweighted視為屬性。資料使用adjacency list儲存並提供轉換為`SparseMatrix`類別的函式

## 2. 其他issue
1. `Dictionary`放入`MortisInvariant`
2. `MortisInvariant`放入`LinkedPolynomial`與`LinkedSparseMatrix`
3. 確保container和array的動態性，可以不斷放入元素而不受初始容量限制
4. `Bag`新增`Unify()`用來消除重複元素