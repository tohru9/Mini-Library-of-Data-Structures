#include <iostream>
#include <cassert>
#include <cstddef>
#include "../interface/list.h"

template <typename T>
struct array {
    private:
    T* data;
    int length;
    int capacity;

    void resize(int newCapacity){
        if (newCapacity < length) {
            newCapacity = length;
        }
        // Handle the case where newCapacity becomes 0 after shrinking
        if (newCapacity == 0) {
            newCapacity = 1;
        }
        
        T* newData = new T[newCapacity];
        for(int i = 0; i < length; i++){
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

    public:
    array(const array& other) {
        length = other.length;
        capacity = other.capacity;
        data = new T[capacity];
        for (int i = 0; i < length; i++)
            data[i] = other.data[i];
    }

    array& operator=(const array& other) {
        if (this == &other) return *this;
        delete[] data;
        length = other.length;
        capacity = other.capacity;
        data = new T[capacity];
        for (int i = 0; i < length; i++)
            data[i] = other.data[i];
        return *this;
    }
    array(){
        data = nullptr;
        length = 0;
        capacity = 0;
    }

    ~array(){
        delete[] data;
    }

    size_t size() const{
        return length;
    }

    T get(size_t i) const {  
        assert(i < length);
        return data[i];  
    }

    T set(int i, T x) { 
        assert(i >= 0 && i < length);
        T temp = data[i];
        data[i] = x;
        return temp;
    }

    void add(int i, T x) {
        assert(i >= 0 && i <= length);
        if(length == capacity){
            if (capacity == 0) {
                resize(1); // Set initial capacity to 1
            } else {
                resize(2 * capacity); // Double capacity
            }
        }
        for(int j = length; j > i; j--){
            data[j] = data[j - 1];
        }
        data[i] = x;
        length++;
    }

    T remove(int i) {
        assert(i >= 0 && i < length);
        T temp = data[i];
        for(int j = i; j < length - 1; j++){
            data[j] = data[j+1];
        }
        length--;
        if(length <= capacity / 4){
            if (capacity > 1) { // Avoid shrinking to 0
                resize(capacity / 2);
            }
        }
        return temp;
    }
};