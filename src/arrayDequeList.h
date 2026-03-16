#pragma once // Add this to prevent redefinition errors
#include <iostream>
#include "../interface/list.h"
#include "../backing/array.h"
#include <cassert>

// REMOVED: using namespace std;

template <typename T>
class ArrayDeque : public List<T>
{
private:
    ::array<T> backingArray; // iostream library has an std:array which is why it must be specified if the struct array is being used  instead of that
public:
    ArrayDeque() {}

    void add(const size_t i, const T &x) override
    {
        assert(i <= backingArray.size());
        backingArray.add(i, x);
    }

    T remove(const size_t i) override
    {
        assert(i < backingArray.size());
        return backingArray.remove(i);
    }

    T get(const size_t i) const override
    {
        assert(i < backingArray.size());
        return backingArray.get(i);
    }

    T set(const size_t i, const T &x) override
    {
        assert(i < backingArray.size());
        return backingArray.set(i, x);
    }

    size_t size() const override
    {
        return backingArray.size();
    }

    void printList()
    {
        for (size_t i = 0; i < backingArray.size(); i++)
        {
            std::cout << backingArray.get(i) << " ";
        }
    }
};