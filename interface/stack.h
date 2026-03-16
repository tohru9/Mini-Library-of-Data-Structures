#pragma once

template <typename T>
class Stack {
public:
    
    // Adds x to the top of the stack.
    virtual void push(T x) = 0;
    
    // Removes an element from the top of the stack and returns it.
    virtual T pop() = 0;
    
    // Returns (without removing) the element at the top of the stack.
    virtual T top() = 0;

    // Returns the number of items in the stack.
    virtual int size() = 0;

    // Returns whether the stack is empty or not.
    virtual bool isEmpty() = 0;
};
