#pragma once
#include <cstddef>
#include "../interface/list.h"
#include "../backing/array.h"  

template <typename T>
class ArrayStack : public List<T>
{
    private:
    array<T> data;
    
    public:
    
    ArrayStack() {}
    
    void push(T x) {
        data.add(data.size(), x);
    }

    T pop() {
        return data.remove(data.size() - 1);
    }

    T top() {
        return data.get(data.size() - 1);
    }
    
    size_t size() const override {
        return data.size();
    }

    T get(const size_t i) const override {
        return data.get(i);
    }

    T set(const size_t i, const T& x) override {
        return data.set(i, x);
    }

    void add(const size_t i, const T& x) override {
        data.add(i, x);
    }

    T remove(const size_t i) override {
        return data.remove(i);
    }
};