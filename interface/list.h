#pragma once
#include <cstddef>

template <typename T>
struct List
{
	// Adds x to the list at index i.
    virtual void add(const size_t i, const T& x) = 0;
	
    // Removes the item at index i from the list.
    // Returns the removed item.
    virtual T remove(const size_t i) = 0;

    // Returns (without removing) the item at index i from the list.
	virtual T get(const size_t i) const = 0;
    
    // Replaces the item at index i with x.
    // Returns the item previously at index i.
	virtual T set(const size_t i, const T& x) = 0;

    // Returns the number of items in the list.
	virtual size_t size() const = 0;
};