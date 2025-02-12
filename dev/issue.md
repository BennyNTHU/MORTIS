# Issues

## 1. 需要實做的資料結構以及資料型別的限制：

### array
- (O) GeneralArray: 需要能夠放入C++內建的資料型別
- (O) Polynomial: 係數限定為浮點數或整數，次數限定為整數
- (O) SparseMatrix: 元素限定為浮點數或整數
- (O) String: cstring加上各種功能的字串
以上四者與C++各種資料型別和稱MortisInvariant

### container
- Bag (multisets) 需要能夠放入MortisInvariant
- Stack (inherits from a bag) 需要能夠放入MortisInvariant
- Queue 需要能夠放入MortisInvariant
- CirQue 需要能夠放入MortisInvariant
- DeQue 需要能夠放入MortisInvariant

### chain
- singly linked list
- circular list
- linked stack
- linked queue
- linked polynomial
- linked sparse matrix
- doubly linked lists

### tree
所有tree的結構，都只能夠放入相同的資料類別，比如要馬全部放int，要馬全部放double或char
- tree
- binarytree
- threaded binary tree
- max priority queue
- max heap
- dictionary
- binary search tree
- forest

### graph
所有graph都用linked structure來實做，減少工作量。node的命名方式一律使用unsigned int
- undirected, unweighted
- undirected, weighted
- directed, unweighted
- directed, weighted


