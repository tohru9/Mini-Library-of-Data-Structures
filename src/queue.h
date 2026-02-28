#pragma once

template <typename T>
struct Queue
{
	// Adds x to the back of the queue.
    virtual void add(const T& x) = 0;
    
    // Removes the item at the front of the queue.
	virtual T remove() = 0;

    // Returns (without removing) the item at the front of the queue.
	virtual bool empty() const = 0;
};
