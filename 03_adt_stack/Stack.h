// TASK 03 -- An Abstract Data Type (ADT)
//
// An ADT is defined by WHAT operations it supports, not by HOW those
// operations are implemented. A stack is: push, pop, top, isEmpty, size.
// That's the whole contract. Whether it's backed by an array, a
// std::vector, or a linked list is an implementation detail the user of
// this class should never have to think about.
//
// This header is the ADT's public face: the operations, and nothing
// about how they're carried out.

#ifndef STACK_H
#define STACK_H

class Stack {
public:
    Stack();

    void push(int value);   // add to the top
    int pop();              // remove the top (does nothing if empty)
    int peek() const;         // look at the top without removing it
    bool isEmpty() const;
    bool isFull() const;
    int size() const;

private:
    // This is the REPRESENTATION. It's private on purpose: nothing
    // outside this class should touch data_ directly, or depend on it
    // being a vector specifically. If we swap this out for a linked
    // list next semester, every .cpp file that #includes this header
    // and only calls push/pop/top/isEmpty/size doesn't need to change
    // at all.
    int data[100];
    int topIndex;
};

#endif
