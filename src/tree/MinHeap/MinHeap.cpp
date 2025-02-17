#include <vector>
#include "MinHeap.hpp"

template <class T>
MinHeap<T>::MinHeap(int theCapacity = 10): MaxHeap<T>(theCapacity) {}

template <class T>
void MinHeap<T>::heapify_up(int index)
{
    while (index > 0 && this->heap[index] < this->heap[(index - 1) / 2]) 
    {
        swap(this->heap[index], this->heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

template <class T>
void MinHeap<T>::heapify_down(int index)
{
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;
    int smallest = index;

    if (left_child < this->get_size() && heap[left_child] < heap[smallest]) 
    {
        smallest = left_child;
    }

    if (right_child < this->get_size() && heap[right_child] < heap[smallest]) 
    {
        smallest = right_child;
    }

    if (smallest != index) {
        swap(heap[index], heap[smallest]);
        heapify_down(smallest);
    }
}

// --------------------
// Explicit Template Instantiation & Friend Operators
// --------------------

template class MinHeap<int>;
template class MinHeap<char>;
template class MinHeap<float>;
template class MinHeap<bool>;
template class MinHeap<double>;
template class MinHeap<std::string>;
