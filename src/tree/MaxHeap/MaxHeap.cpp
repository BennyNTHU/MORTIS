template <class T>
MaxHeap<T>::MaxHeap(int theCapacity) // constructor
{
    if (theCapacity < 1)
        throw "Capacity must be >= 1";
    capacity = theCapacity;
    heapSize = 0; 
    heap = new T [capacity + 1]; // heap[0] unused
}

template <class T>
MaxHeap<T>::~MaxHeap()
{
    delete(heap);
}

template <class T>
bool MaxHeap<T>::IsEmpty() const
{
    return heapSize==0;
}

template <class T>
const T& MaxHeap<T>::Top() const
{
    return heap[1];
}

template <class T>
T* MaxHeap<T>::get_heap()
{
    return heap;
}

template <class T>
int MaxHeap<T>::get_size()
{
    return heapSize;
}

template <class T>
int MaxHeap<T>::get_capacity()
{
    return capacity;
}

template <class T>
void MaxHeap<T>::Push(const T& e)   // add element e to max heap
{ 
    if (heapSize == capacity)   // double the capacity
    { 
        ChangeSize1D(heap, capacity, 2*capacity);
        capacity *= 2;
    }
    int currentNode = ++heapSize;
    while (currentNode != 1 && heap[currentNode/2] < e) // bubbling up
    { 
        heap[currentNode] = heap[currentNode/2];    //move parent down
        currentNode /= 2;
    }
    heap[currentNode] = e;
}

template <class T>
void MaxHeap<T>::Pop()  // Delete max element
{ 
    if (IsEmpty ()) 
        throw "Heap is empty. Cannot delete.";

    heap[1].~T(); // delete max element
    T lastE = heap[heapSize--];  // remove last element from heap

    // trickle down to find a position to place the last element
    int currentNode = 1; // root
    int child = 2;       //  a child of current node
    while (child <= heapSize)   // set child to larger child of currentNode
    {
        if (child < heapSize && heap[child] < heap[child + 1]) 
            child++;
        if (lastE >= heap[child]) 
            break; 
        heap[currentNode] = heap[child]; // move child up
        currentNode = child; 
        child *= 2; // move down a level
    }
    heap[currentNode] = lastE;
}

template <class T>
void ChangeSize1D (T*& a, const int oldSize, const int newSize)
{
	if (newSize < 0) 
        throw "New length must be >=0";
	
	T* temp = new T [newSize];    // new array
	int number = min(oldSize, newSize);     // number to copy
	copy (a, a+number, temp);
	delete [] a;      // deallocate old memory
	a = temp;
}

#endif