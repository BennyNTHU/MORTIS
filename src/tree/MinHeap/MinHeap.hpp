#ifndef MINHEAP
#define MINHEAP

#include "../MaxHeap/MaxHeap.hpp"

template <class T>
class MinHeap : public MaxHeap<T> 
{
    protected:
        // Override heapify methods
        void heapify_up(int index) override;
        void heapify_down(int index) override;

    public:
        // Constructor and destructor
        MinHeap(const T& rootData);
        ~MinHeap();
};

#endif
