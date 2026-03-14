#include<iostream>
#include "../interface/list.h"
#include "../backing/array.h"
#include <cassert>
using namespace std;

template <typename T>
class ArrayDeque : public List<T>
{
private:
    array<T> backingArray;

public:

    ArrayDeque() {}

    // Adds x to the list at index i.
    void add(const size_t i, const T& x) override {
        assert(i <= backingArray.size());
        backingArray.add(i, x);
    }

    // Removes the item at index i from the list.
    // Returns the removed item.
    T remove(const size_t i) override {
        assert(i < backingArray.size());
        return backingArray.remove(i);
    }

    // Returns (without removing) the item at index i from the list.
    T get(const size_t i) const override {
        assert(i < backingArray.size());
        return backingArray.get(i);
    }

    // Replaces the item at index i with x.
    // Returns the item previously at index i.
    T set(const size_t i, const T& x) override {
        assert(i < backingArray.size());
        return backingArray.set(i, x);
    }

    // Returns the number of items in the list.
    size_t size() const override {
        return backingArray.size();
    }

    void printList(){
        for (size_t i = 0; i < backingArray.size(); i++) {
            cout << backingArray.get(i) << " ";
        }
    }
};