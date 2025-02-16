#include "../BinaryTreeIterator/BinaryTreeIterator.hpp"

// Helper function to push left nodes for inorder traversal
template <class T>
void BinaryTreeIterator<T>::pushLeft(BinaryTreeNode<T>* node) 
{
    while (node) 
    {
        s.Push(node);
        if (node->getLeftThread()) break; // Stop if we reach a thread
        node = node->getLeftChild();
    }
}

// Helper function to push right nodes for postorder traversal
template <class T>
void BinaryTreeIterator<T>::pushRight(BinaryTreeNode<T>* node) 
{
    while (node) 
    {
        s.Push(node);
        if (node->getRightThread()) break; // Stop if we reach a thread
        node = node->getRightChild();
    }
}

// Constructor
template <class T>
BinaryTreeIterator<T>::BinaryTreeIterator(BinaryTreeNode<T>* root, char traversalMode): current(root), mode(traversalMode) 
{
    reset(root, traversalMode);
}

// Destructor
template <class T>
BinaryTreeIterator<T>::~BinaryTreeIterator() {}

// Get current node
template <class T>
BinaryTreeNode<T>* BinaryTreeIterator<T>::getCurrent() const 
{
    return current;
}

// Dereferencing operators
template <class T>
const T& BinaryTreeIterator<T>::operator*() const 
{
    return current->getData();
}

template <class T>
const T* BinaryTreeIterator<T>::operator->() const 
{
    return &(current->getData());
}

// Reset iterator to a new traversal mode
template <class T>
void BinaryTreeIterator<T>::reset(BinaryTreeNode<T>* root, char traversalMode) 
{
    while (!s.IsEmpty()) s.Pop();
    while (!q.IsEmpty()) q.PopFront();

    current = root;
    mode = traversalMode;

    switch (mode) 
    {
        case 'I': pushLeft(root);             break;    // In-order traversal
        case 'P': if (root) s.Push(root);     break;    // Pre-order traversal
        case 'O': if (root) pushRight(root);  break;    // Post-order traversal
        case 'L': if (root) q.PushBack(root); break;    // Level-order traversal
        default: throw std::invalid_argument("Unknown traversal mode.");
    }
}

// Check if the iterator has more elements
template <class T>
bool BinaryTreeIterator<T>::hasNext() 
{
    return !s.IsEmpty() || !q.IsEmpty();
}

// Pre-increment operator
template <class T>
BinaryTreeIterator<T>& BinaryTreeIterator<T>::operator++() 
{
    switch (mode) 
    {
        case 'I':   // In-order traversal 
        { 
            if (!s.IsEmpty()) 
            {
                current = s.Top();
                s.Pop();
                pushLeft(current->getRightChild());
            } 
            else 
            {
                current = nullptr;
            }
            break;
        }
        case 'P':   // Pre-order traversal
        { 
            if (!s.IsEmpty()) 
            {
                current = s.Top();
                s.Pop();
                if (current->getRightChild()) s.Push(current->getRightChild());
                if (current->getLeftChild()) s.Push(current->getLeftChild());
            } 
            else 
            {
                current = nullptr;
            }
            break;
        }
        case 'O':   // Post-order traversal
        { 
            if (!s.IsEmpty()) 
            {
                current = s.Top();
                s.Pop();
            } 
            else 
            {
                current = nullptr;
            }
            break;
        }
        case 'L':   // Level-order traversal
        { 
            if (!q.IsEmpty()) 
            {
                current = q.Front();
                q.PopFront();
                if (current->getLeftChild()) q.PushBack(current->getLeftChild());
                if (current->getRightChild()) q.PushBack(current->getRightChild());
            } 
            else 
            {
                current = nullptr;
            }
            break;
        }
        default:
            throw std::invalid_argument("Unknown traversal mode.");
    }
    return *this;
}

// Post-increment operator
template <class T>
BinaryTreeIterator<T> BinaryTreeIterator<T>::operator++(int) 
{
    BinaryTreeIterator<T> temp = *this;
    ++(*this);
    return temp;
}

// Pre-decrement operator (for reverse iteration)
template <class T>
BinaryTreeIterator<T>& BinaryTreeIterator<T>::operator--() 
{
    switch (mode) 
    {
        case 'I':   // Reverse In-order traversal 
        { 
            pushRight(current->getLeftChild());
            if (!s.IsEmpty()) 
            {
                current = s.Top();
                s.Pop();
            } 
            else 
            {
                current = nullptr;
            }
            break;
        }
        case 'P':   // Pre-order reverse traversal is not supported 
        { 
            throw std::logic_error("Reverse traversal is not supported for Pre-order iteration.");
        }
        case 'O':   // Reverse Post-order traversal
        { 
            pushLeft(current->getRightChild());
            if (!s.IsEmpty()) 
            {
                current = s.Top();
                s.Pop();
            } 
            else 
            {
                current = nullptr;
            }
            break;
        }
        case 'L':   // Reverse Level-order traversal 
        { 
            if (!q.IsEmpty()) 
            {
                current = q.Back();
                q.PopBack();
                if (current->getRightChild()) q.PushFront(current->getRightChild());
                if (current->getLeftChild()) q.PushFront(current->getLeftChild());
            } 
            else 
            {
                current = nullptr;
            }
            break;
        }
        default:
            throw std::invalid_argument("Unknown traversal mode.");
    }
    return *this;
}
