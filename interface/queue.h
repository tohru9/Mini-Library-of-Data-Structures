#pragma once

template <typename T>
struct Queue
{
    // Adds x to the back of the queue.
    virtual void add(const T &x) = 0;

    // Removes the item at the front of the queue.
    virtual T remove() = 0;

    // Returns (without removing) the item at the front of the queue.
    virtual T peek() const = 0;

    // Check if queue is empty
    virtual bool isEmpty() const = 0;

    // Returns size of queue
    virtual size_t size() const = 0;
};
