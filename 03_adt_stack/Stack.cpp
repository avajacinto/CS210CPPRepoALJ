// TASK 03 -- The Stack ADT's implementation
//
// This is where "how" lives. We chose std::vector as the backing
// storage: push_back is our push, back() is our top, pop_back() is our
// pop. A student could rewrite this whole file to use a raw fixed-size
// array instead, and as long as push/pop/top/isEmpty/size still behave
// the same way, nothing calling this class would ever notice.

#include "Stack.h"
#include <iostream>

Stack::Stack() {
    topIndex = -1;
}

void Stack::push(int value) {
    // TODO: add value to the top of data_ (vector has a method for this)
    if (isFull()) {
        std::cout << "Cannot push, stack is full" << std::endl;
        return;
    }

    topIndex++;
    data[topIndex] = value;
}

int Stack::pop() {
    // TODO: if data_ isn't empty, remove the top element
    if (isEmpty()) {
        std::cout << "Cannot pop, stack is empty" << std::endl;
        return -1;
    }

    int topValue = data[topIndex];
    topIndex--;

    return topValue;
}

int Stack::peek() const {
    if (isEmpty()) {
        std::cout << "Cannot peek, stack is empty" << std::endl;
        return -1;
    }
    return data[topIndex];
}

bool Stack::isEmpty() const {
    // TODO: return whether data_ has zero elements
    return topIndex == -1;
}

bool Stack::isFull() const {
    return topIndex == 99;
}

int Stack::size() const {
    // TODO: return how many elements are in data_ (cast to int)
    return topIndex + 1;
}
