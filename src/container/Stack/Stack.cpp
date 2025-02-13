#include "Stack.hpp"
#include <stdexcept>

// Constructor: Initializes the stack with a given capacity using Bag's constructor
Stack::Stack(int initial_capacity) : Bag(initial_capacity) {}

// Push an element onto the stack (calls Bag's Push)
void Stack::Push(const MORTISInvariant& x) {
    Bag::Push(x);
}

// Pop the top element from the stack
void Stack::Pop() {
    if (IsEmpty()) {
        throw std::out_of_range("Stack is empty. Cannot pop.");
    }
    Bag::Pop();
}

// Get the top element of the stack without removing it
MORTISInvariant Stack::Top() const {
    if (IsEmpty()) {
        throw std::out_of_range("Stack is empty. Cannot retrieve top element.");
    }
    return arr[Element() - 1]; // Last inserted element
}

// Print the stack (from top to bottom)
void Stack::PrintStack() const {
    if (IsEmpty()) {
        std::cout << "Stack is empty." << std::endl;
        return;
    }

    std::cout << "Stack (Top to Bottom):" << std::endl;
    for (int i = Element() - 1; i >= 0; --i) {
        std::cout << i + 1 << ". ";
        std::visit([](auto&& arg) { std::cout << arg; }, arr[i]);
        if (i == Element() - 1) {
            std::cout << " <- top";
        }
        std::cout << std::endl;
    }
}
