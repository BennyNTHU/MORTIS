#include <iostream>
#include "DoublyLinkedList.hpp"

using namespace std;

// Constructor: Initializes an empty list
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : first(nullptr), last(nullptr) {}

// Copy Constructor: Deep copy another list
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& other) : first(nullptr), last(nullptr) {
    for (DLIterator<T> it = other.begin(); it != other.end(); ++it) {
        InsertBack(*it);
    }
}

// Destructor: Deletes all nodes in the list
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    while (!IsEmpty()) {
        DeleteFront();
    }
}

// Get an iterator pointing to the first element
template <typename T>
DLIterator<T> DoublyLinkedList<T>::begin() const {
    return DLIterator<T>(first);
}

// Get an iterator pointing to the end (nullptr)
template <typename T>
DLIterator<T> DoublyLinkedList<T>::end() const {
    return DLIterator<T>(nullptr);
}

// Insert an element at the front
template <typename T>
void DoublyLinkedList<T>::InsertFront(const T& e) {
    DoubleNode<T>* newNode = new DoubleNode<T>(e, first, nullptr); // 設定新節點的 next 為 first
    if (first) {
        first->setPrev(newNode); // 讓原本的 first 指向 newNode
    } else {
        last = newNode; // 若 first 為 nullptr，代表這是第一個節點，因此 last 也要指向它
    }
    first = newNode; // 更新 first 為新的節點
}

// Insert an element at the back
template <typename T>
void DoublyLinkedList<T>::InsertBack(const T& e) {
    DoubleNode<T>* newNode = new DoubleNode<T>(e, nullptr, last); // 設定新節點的 prev 為 last
    if (last) {
        last->setLink(newNode); // 讓原本的 last 指向新節點
    } else {
        first = newNode; // 若 last 為 nullptr，代表這是第一個節點，因此 first 也要指向它
    }
    last = newNode; // 更新 last 為新的節點
}

// Insert an element at a given position
template <typename T>
void DoublyLinkedList<T>::Insert(int pos, T e) {
    if (pos < 0) {
        throw std::out_of_range("Position must be non-negative.");
    }

    if (pos == 0) {
        InsertFront(e);
        return;
    }

    DoubleNode<T>* current = first;
    int index = 0;

    // 移動到 `pos-1` 的位置
    while (current && index < pos - 1) {
        current = static_cast<DoubleNode<T>*>(current->getLink());
        index++;
    }

    // 超出範圍時，拋出錯誤
    if (!current) {
        throw std::out_of_range("Position out of bounds.");
    }

    // 取得 `current->next`
    DoubleNode<T>* nextNode = static_cast<DoubleNode<T>*>(current->getLink());

    // 創建新節點
    DoubleNode<T>* newNode = new DoubleNode<T>(e, nextNode, current);

    // 連接新節點與 `nextNode`
    if (nextNode) {
        nextNode->setPrev(newNode);
    } else {
        last = newNode; // 若插入的是最後一個元素，更新 `last`
    }

    current->setLink(newNode);
}

// Delete the front element
template <typename T>
void DoublyLinkedList<T>::DeleteFront() {
    if (IsEmpty()) {
        throw std::runtime_error("List is empty. Cannot delete.");
    }
    
    DoubleNode<T>* temp = first;
    first = static_cast<DoubleNode<T>*>(first->getLink());
    
    if (first) {
        first->setPrev(nullptr);
    } else {
        last = nullptr;
    }
    
    delete temp;
}

// Delete the back element
template <typename T>
void DoublyLinkedList<T>::DeleteBack() {
    if (IsEmpty()) {
        throw runtime_error("List is empty. Cannot delete.");
    }
    DoubleNode<T>* temp = last;
    last = last->getPrev();
    if (last) {
        last->setLink(nullptr);
    } else {
        first = nullptr;
    }
    delete temp;
}

// Delete an element at a given position
template <typename T>
void DoublyLinkedList<T>::Delete(int pos) {
    if (pos < 0 || IsEmpty()) {
        throw std::out_of_range("Invalid position or empty list.");
    }

    if (pos == 0) {
        DeleteFront();
        return;
    }

    DoubleNode<T>* current = first;
    int index = 0;

    while (current && index < pos) {
        current = static_cast<DoubleNode<T>*>(current->getLink());
        index++;
    }

    if (!current) {
        throw std::out_of_range("Position out of bounds.");
    }

    if (current->getLink()) {
        static_cast<DoubleNode<T>*>(current->getLink())->setPrev(current->getPrev());
    } else {
        last = current->getPrev();
    }

    if (current->getPrev()) {
        current->getPrev()->setLink(current->getLink());
    } else {
        first = static_cast<DoubleNode<T>*>(current->getLink());
    }

    delete current;
}

// Get the length of the list
template <typename T>
int DoublyLinkedList<T>::Length() const {
    int count = 0;
    for (DLIterator<T> it = begin(); it != end(); ++it) {
        count++;
    }
    return count;
}

// Concatenate another doubly linked list to this list
template <typename T>
void DoublyLinkedList<T>::Concatenate(DoublyLinkedList<T>& other) {
    if (other.IsEmpty()) return;

    if (IsEmpty()) {
        first = other.first;
        last = other.last;
    } else {
        last->setLink(other.first);
        static_cast<DoubleNode<T>*>(other.first)->setPrev(last);
        last = other.last;
    }

    other.first = other.last = nullptr;
}

// Reverse the doubly linked list
template <typename T>
void DoublyLinkedList<T>::Reverse() {
    DoubleNode<T>* current = first;
    DoubleNode<T>* temp = nullptr;

    while (current) {
        temp = current->getPrev();
        current->setPrev(static_cast<DoubleNode<T>*>(current->getLink()));
        current->setLink(temp);
        current = current->getPrev();
    }

    if (temp) {
        first = temp->getPrev();
    }
}

// Check if the list is empty
template <typename T>
bool DoublyLinkedList<T>::IsEmpty() const {
    return first == nullptr;
}

// Overload the << operator to print the list
template <typename T>
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& list) {
    if (list.IsEmpty()) {
        out << "Empty List";
        return out;
    }

    for (DLIterator<T> it = list.begin(); it != list.end(); ++it) {
        out << *it << " <-> ";
    }
    out << "NULL";
    return out;
}

// Assignment Operator Overload: Deep copy another list
template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& other) {
    if (this == &other) return *this;

    while (!IsEmpty()) {
        DeleteFront();
    }

    for (DLIterator<T> it = other.begin(); it != other.end(); ++it) {
        InsertBack(*it);
    }

    return *this;
}

// Explicit instantiation
template std::ostream& operator<<(std::ostream&, const DoublyLinkedList<int>&);
template std::ostream& operator<<(std::ostream&, const DoublyLinkedList<bool>&);
template std::ostream& operator<<(std::ostream&, const DoublyLinkedList<char>&);
template std::ostream& operator<<(std::ostream&, const DoublyLinkedList<float>&);
template std::ostream& operator<<(std::ostream&, const DoublyLinkedList<double>&);
template std::ostream& operator<<(std::ostream&, const DoublyLinkedList<std::string>&);

// Explicit template instantiation
template class DoublyLinkedList<int>;
template class DoublyLinkedList<bool>;
template class DoublyLinkedList<char>;
template class DoublyLinkedList<float>;
template class DoublyLinkedList<double>;
template class DoublyLinkedList<std::string>;
