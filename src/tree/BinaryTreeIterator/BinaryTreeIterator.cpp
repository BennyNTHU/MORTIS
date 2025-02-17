#include "../BinaryTreeIterator/BinaryTreeIterator.hpp"
#include <stdexcept>

// Helper function to push left nodes for in‑order traversal.
template <class T>
void BinaryTreeIterator<T>::pushLeft(BinaryTreeNode<T>* node) {
    while (node) {
        s.Push(node);
        // If a thread pointer exists, we stop going left.
        if (node->getLeftThread())
            break;
        node = node->getLeftChild();
    }
}

// Helper function to push right nodes for reverse (or post‑order) traversal.
template <class T>
void BinaryTreeIterator<T>::pushRight(BinaryTreeNode<T>* node) {
    while (node) {
        s.Push(node);
        // Stop if we hit a thread.
        if (node->getRightThread())
            break;
        node = node->getRightChild();
    }
}

// Constructor – initializes the iterator with a root and traversal mode.
template <class T>
BinaryTreeIterator<T>::BinaryTreeIterator(BinaryTreeNode<T>* root, char traversalMode)
    : current(root), mode(traversalMode)
{
    reset(root, traversalMode);
}

// Destructor – clears internal containers.
template <class T>
BinaryTreeIterator<T>::~BinaryTreeIterator() {
    while (!s.IsEmpty())
        s.Pop();
    while (!q.IsEmpty())
        q.PopFront();
}

// Return the current node.
template <class T>
BinaryTreeNode<T>* BinaryTreeIterator<T>::getCurrent() const {
    return current;
}

// Dereference operators.
template <class T>
const T& BinaryTreeIterator<T>::operator*() const {
    return current->getData();
}

template <class T>
const T* BinaryTreeIterator<T>::operator->() const {
    return &(current->getData());
}

// Reset the iterator for a new traversal mode.
template <class T>
void BinaryTreeIterator<T>::reset(BinaryTreeNode<T>* root, char traversalMode) {
    // Clear any previous state.
    while (!s.IsEmpty()) s.Pop();
    while (!q.IsEmpty()) q.PopFront();

    current = root;
    mode = traversalMode;

    switch (mode) {
        case 'I': // In‑order traversal.
            pushLeft(root);
            break;
        case 'P': // Pre‑order traversal.
            if (root)
                s.Push(root);
            break;
        case 'O': // Post‑order traversal.
            // For post‑order, we use pushRight to mimic a reverse process.
            if (root)
                pushRight(root);
            break;
        case 'L': // Level‑order traversal.
            if (root)
                q.PushBack(root);
            break;
        default:
            throw std::invalid_argument("Unknown traversal mode.");
    }
}

// Check if more nodes remain.
template <class T>
bool BinaryTreeIterator<T>::hasNext() {
    return !s.IsEmpty() || !q.IsEmpty();
}

// Pre‑increment operator.
template <class T>
BinaryTreeIterator<T>& BinaryTreeIterator<T>::operator++() {
    switch (mode) {
        case 'I': {  // In‑order traversal.
            if (!s.IsEmpty()) {
                current = s.Top();
                s.Pop();
                pushLeft(current->getRightChild());
            } else {
                current = nullptr;
            }
            break;
        }
        case 'P': {  // Pre‑order traversal.
            if (!s.IsEmpty()) {
                current = s.Top();
                s.Pop();
                // Push right child first (if exists) then left.
                if (current->getRightChild())
                    s.Push(current->getRightChild());
                if (current->getLeftChild())
                    s.Push(current->getLeftChild());
            } else {
                current = nullptr;
            }
            break;
        }
        case 'O': {  // Post‑order traversal.
            if (!s.IsEmpty()) {
                current = s.Top();
                s.Pop();
            } else {
                current = nullptr;
            }
            break;
        }
        case 'L': {  // Level‑order traversal.
            if (!q.IsEmpty()) {
                current = q.Front();
                q.PopFront();
                if (current->getLeftChild())
                    q.PushBack(current->getLeftChild());
                if (current->getRightChild())
                    q.PushBack(current->getRightChild());
            } else {
                current = nullptr;
            }
            break;
        }
        default:
            throw std::invalid_argument("Unknown traversal mode.");
    }
    return *this;
}

// Post‑increment operator.
template <class T>
BinaryTreeIterator<T> BinaryTreeIterator<T>::operator++(int) {
    BinaryTreeIterator<T> temp = *this;
    ++(*this);
    return temp;
}

// Pre‑decrement operator for reverse iteration.
template <class T>
BinaryTreeIterator<T>& BinaryTreeIterator<T>::operator--() {
    switch (mode) {
        case 'I': {  // Reverse in‑order traversal.
            pushRight(current->getLeftChild());
            if (!s.IsEmpty()) {
                current = s.Top();
                s.Pop();
            } else {
                current = nullptr;
            }
            break;
        }
        case 'P': {  // Reverse pre‑order is not supported.
            throw std::logic_error("Reverse traversal is not supported for Pre-order iteration.");
        }
        case 'O': {  // Reverse post‑order traversal.
            // Use pushLeft here for a reverse effect.
            pushLeft(current->getRightChild());
            if (!s.IsEmpty()) {
                current = s.Top();
                s.Pop();
            } else {
                current = nullptr;
            }
            break;
        }
        case 'L': {  // Reverse level‑order traversal.
            if (!q.IsEmpty()) {
                current = q.Back();
                q.PopBack();
                if (current->getRightChild())
                    q.PushFront(current->getRightChild());
                if (current->getLeftChild())
                    q.PushFront(current->getLeftChild());
            } else {
                current = nullptr;
            }
            break;
        }
        default:
            throw std::invalid_argument("Unknown traversal mode.");
    }
    return *this;
}

// Additional next() function – returns the current node then advances the iterator.
template <class T>
BinaryTreeNode<T>* BinaryTreeIterator<T>::next() {
    BinaryTreeNode<T>* temp = current;
    ++(*this);
    return temp;
}

// Explicit template instantiation.
template class BinaryTreeIterator<int>;
template class BinaryTreeIterator<bool>;
template class BinaryTreeIterator<char>;
template class BinaryTreeIterator<float>;
template class BinaryTreeIterator<double>;
template class BinaryTreeIterator<std::string>;
