# include "../MaxHeap/MaxHeap.hpp"

template <class T>
class MinHeap: public MaxHeap<T> 
{
    public:
        MinHeap(int theCapacity = 10);

    protected:
        void heapify_up(int index) override;    // Override heapify methods for Min-Heap
        void heapify_down(int index) override;
};
