#include "CircularList.hpp"

template <typename T>
void CircularList<T>::SetFirst(Node<T>* node) {
    LinkedList<T>::SetFirst(node); // Use the protected function from LinkedList
}


// Constructor
template <typename T>
CircularList<T>::CircularList() : LinkedList<T>() {
    if (this->GetFirst()) {  // Ensure circular linkage if not empty
        Node<T>* lastNode = this->GetFirst();
        while (lastNode->getLink() != this->GetFirst()) {
            lastNode = lastNode->getLink();
        }
        lastNode->setLink(this->GetFirst());  // Complete circular linkage
    }
}

// Insert at back
template <typename T>
void CircularList<T>::InsertBack(const T& e) {
    Node<T>* newNode = new Node<T>(e, nullptr); // Create new node

    if (!this->GetFirst()) {  // If the list is empty
        this->SetFirst(newNode);
        newNode->setLink(newNode); // Properly point to itself to maintain circularity
        return; // Exit early
    }

    // Traverse to the last node
    Node<T>* current = this->GetFirst();
    while (current->getLink() != this->GetFirst()) {
        current = current->getLink();
    }

    // Insert new node at the end
    current->setLink(newNode);
    newNode->setLink(this->GetFirst()); // Ensure circular linkage
}


// Insert at front
template <typename T>
void CircularList<T>::InsertFront(const T& e) {
    Node<T>* newNode = new Node<T>(e, nullptr);

    if (!this->GetFirst()) {
        this->SetFirst(newNode);
        newNode->setLink(this->GetFirst()); // Point to itself
    } else {
        Node<T>* lastNode = this->GetFirst();
        while (lastNode->getLink() != this->GetFirst()) {
            lastNode = lastNode->getLink();
        }

        newNode->setLink(this->GetFirst());
        this->SetFirst(newNode);
        lastNode->setLink(this->GetFirst());
    }
}

// Delete from back
template <typename T>
void CircularList<T>::DeleteBack() {
    if (!this->GetFirst()) return; // Empty list

    Node<T>* current = this->GetFirst();
    Node<T>* prev = nullptr;

    while (current->getLink() != this->GetFirst()) {
        prev = current;
        current = current->getLink();
    }

    if (prev) {
        prev->setLink(this->GetFirst());
    } else {
        this->SetFirst(nullptr); // If only one element existed
    }

    delete current;
}

// Delete from front
template <typename T>
void CircularList<T>::DeleteFront() {
    if (!this->GetFirst()) return;

    Node<T>* lastNode = this->GetFirst();
    while (lastNode->getLink() != this->GetFirst()) {
        lastNode = lastNode->getLink();
    }

    Node<T>* temp = this->GetFirst();
    if (this->GetFirst() == lastNode) {
        this->SetFirst(nullptr);
    } else {
        this->SetFirst(this->GetFirst()->getLink());
        lastNode->setLink(this->GetFirst());
    }

    delete temp;
}

// Concatenate another circular linked list safely
template <typename T>
void CircularList<T>::Concatenate(CircularList<T>& b) {
    if (!b.GetFirst()) return;  // If `b` is empty, do nothing

    if (!this->GetFirst()) {  // If `this` list is empty, simply copy `b`
        this->SetFirst(b.GetFirst());

        // Find the last node of `b` to maintain circularity
        Node<T>* lastB = b.GetFirst();
        while (lastB->getLink() != b.GetFirst()) {
            lastB = lastB->getLink();
        }
        lastB->setLink(this->GetFirst());  // Maintain circularity
        return;
    }

    // Find the last node of `this` list safely
    Node<T>* lastA = this->GetFirst();
    while (lastA->getLink() != this->GetFirst()) {
        lastA = lastA->getLink();
    }

    // Find the last node of `b` safely
    Node<T>* lastB = b.GetFirst();
    while (lastB->getLink() != b.GetFirst()) {
        lastB = lastB->getLink();
    }

    // Correctly concatenate the two lists
    lastA->setLink(b.GetFirst());  // Link `this` last node to `b` first node
    lastB->setLink(this->GetFirst());  // Link `b` last node to `this` first node

    // Optional: Mark `b` as empty to prevent unintended operations
    b.SetFirst(nullptr);
}

// Destructor
template <typename T>
CircularList<T>::~CircularList() {
    if (!this->GetFirst()) return; // If list is empty, no need to delete

    Node<T>* current = this->GetFirst();
    Node<T>* nextNode = nullptr;

    // Traverse the circular list and delete each node
    while (current->getLink() != this->GetFirst()) {
        nextNode = current->getLink();
        delete current;
        current = nextNode;
    }

    delete current; // Delete the last node
    this->SetFirst(nullptr); // Prevent dangling pointer issues
}

// Overload the << operator to print CircularList
template <typename T>
std::ostream& operator<<(std::ostream& out, const CircularList<T>& list) {
    if (!list.GetFirst()) {
        out << "Empty Circular List";
        return out;
    }

    Node<T>* current = list.GetFirst();
    do {
        out << current->getData() << " -> ";
        current = current->getLink();
    } while (current != list.GetFirst()); // Stop when we return to the first node

    out << "(Back to first)";
    return out;
}

// Copy constructor
template <typename T>
CircularList<T>::CircularList(const CircularList<T>& other) {
    this->SetFirst(nullptr); // Start with an empty list
    CopyFrom(other);
}

// Assignment operator
template <typename T>
CircularList<T>& CircularList<T>::operator=(const CircularList<T>& other) {
    if (this != &other) {  // Avoid self-assignment
        this->Clear();      // Clear current list before copying
        CopyFrom(other);
    }
    return *this;
}

// Function to return the length of the circular linked list using ChainIterator
// Override Length function for CircularList
template <typename T>
int CircularList<T>::Length() {
    if (!this->GetFirst()) return 0; // If the list is empty, return 0

    int count = 0;
    ChainIterator<T> it = this->begin();

    do {
        count++;
        ++it;
    } while (it != this->begin()); // Ensure we stop when we return to the start

    return count;
}


// Utility function to copy elements from another CircularList
template <typename T>
void CircularList<T>::CopyFrom(const CircularList<T>& other) {
    if (!other.GetFirst()) return;  // If `other` is empty, do nothing

    // Create a copy of the first node
    this->SetFirst(new Node<T>(other.GetFirst()->getData(), nullptr));
    Node<T>* currentNew = this->GetFirst();
    Node<T>* currentOther = other.GetFirst()->getLink();

    // Copy remaining nodes
    while (currentOther != other.GetFirst()) {
        Node<T>* newNode = new Node<T>(currentOther->getData(), nullptr);
        currentNew->setLink(newNode);
        currentNew = newNode;
        currentOther = currentOther->getLink();
    }

    // Ensure circular linkage
    currentNew->setLink(this->GetFirst());
}

// Explicit instantiation
template std::ostream& operator<<(std::ostream&, const CircularList<int>&);
template std::ostream& operator<<(std::ostream&, const CircularList<bool>&);
template std::ostream& operator<<(std::ostream&, const CircularList<char>&);
template std::ostream& operator<<(std::ostream&, const CircularList<float>&);
template std::ostream& operator<<(std::ostream&, const CircularList<double>&);
template std::ostream& operator<<(std::ostream&, const CircularList<std::string>&);

// Explicit template instantiation
template class CircularList<int>;
template class CircularList<bool>;
template class CircularList<char>;
template class CircularList<float>;
template class CircularList<double>;
template class CircularList<std::string>;
