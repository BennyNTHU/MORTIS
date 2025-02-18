#ifndef MINHEAP
#define MINHEAP

#include "../MaxHeap/MaxHeap.hpp"

template <class T>
class MinHeap : public MaxHeap<T> 
{
public:
    // Constructor and destructor.
    MinHeap(const T& rootData);
    ~MinHeap();

protected:
    // Override heapify methods for a min-heap.
    void heapify_up(int index) override;
    void heapify_down(int index) override;
};

#endif
