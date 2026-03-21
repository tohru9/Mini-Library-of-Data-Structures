#pragma once

template <typename T>
struct SSet{
    
    // Returns the number of items in the set.
    virtual size_t size() const = 0;

    // Adds x to the set.
    virtual void add(const T& x) const = 0;
    
    // Removes x from the set.
    virtual T remove(const T& x) const = 0;
    
    // Returns whether x is in the set or not.
    virtual T find(const T& x) const = 0;
};
