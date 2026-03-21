#pragma once
#include <cstddef>

template <typename T>
struct USet
{

    // Returns the number of items in the set.
    virtual size_t size() const = 0;

    // Adds x to the set if it's not already present.
    // Returns true if added, false if it was already there.
    virtual bool add(T x) = 0;

    // Removes x from the set and returns it.
    // Usually returns a 'null' equivalent or throws if not found.
    virtual T remove(T x) = 0;

    // Returns x if it is in the set, or a null-like value if not.
    // In USet, this is a simple membership check.
    virtual T find(T x) = 0;
};