#pragma once
#include "../interface/deque.h" 
#include <stdexcept>

template <typename T>
class ArrayDeque : public Deque<T> {
private:
    T* data;
    size_t capacity;
    size_t frontIndex; 
    size_t currentSize; 

    //resize when full
    void resize() {
        size_t newCapacity = capacity * 2;
        T* newData = new T[newCapacity];
        
        // wrap similar to circular array and so that the first person is always index 0
        for (size_t i = 0; i < currentSize; i++) {
            newData[i] = data[(frontIndex + i) % capacity];
        }
        
        delete[] data;
        data = newData;
        frontIndex = 0;
        capacity = newCapacity;
    }

public:
    //constuctor
    ArrayDeque(size_t cap = 10) {
        capacity = cap;
        data = new T[capacity];
        frontIndex = 0;
        currentSize = 0;
    }

    //deconstuctor
    ~ArrayDeque() {
        delete[] data;
    }

    void addFirst(const T& x) override {
        if (currentSize == capacity) {
            resize(); //increase capacity if full
        }
        // wrap back
        frontIndex = (frontIndex - 1 + capacity) % capacity;
        data[frontIndex] = x;
        currentSize++;
    }

    void addLast(const T& x) override {
        if (currentSize == capacity) {
            resize();
        }
        // wrap front
        size_t backIndex = (frontIndex + currentSize) % capacity;
        data[backIndex] = x;
        currentSize++;
    }

    T removeFirst() override {
        if (isEmpty()) {
            throw std::out_of_range("Ghost?? Nobody is at the front!");
        }
        T servedItem = data[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        currentSize--;
        return servedItem;
    }

    T removeLast() override {
        if (isEmpty()) {
            throw std::out_of_range("Ghost?? Nobody is at the back!");
        }
        size_t backIndex = (frontIndex + currentSize - 1) % capacity;
        T leavingItem = data[backIndex];
        currentSize--;
        return leavingItem;
    }

    const T peekFirst() const override {
        if (isEmpty()) {
            throw std::out_of_range("Who you calling??? (Front is empty)");
        }
        return data[frontIndex];
    }

    const T peekLast() const override {
        if (isEmpty()) {
            throw std::out_of_range("blud??? (Back is empty)");
        }
        size_t backIndex = (frontIndex + currentSize - 1) % capacity;
        return data[backIndex];
    }

    bool isEmpty() const override {
        return currentSize == 0;
    }

    void clear() override {
        // reset everything to 0, no deletion
        currentSize = 0;
        frontIndex = 0;
    }

    size_t size() const override {
        return currentSize;
    }

    // NEW ADDITIONS
    bool isWaiting(const T& person) const {
        for (size_t i = 0; i < currentSize; i++) {
            // check if someone is waiting
            if (data[(frontIndex + i) % capacity] == person) {
                return true; 
            }
        }
        return false; // guy not in line
    }

    
    void unoReverse() {
        if (currentSize <= 1) return; // if size is 1 or less then no need to reverse

        for (size_t i = 0; i < currentSize / 2; i++) {
            // which ones to swap
            size_t leftSpot = (frontIndex + i) % capacity;
            size_t rightSpot = (frontIndex + currentSize - 1 - i) % capacity;

            // swap using temp
            T temp = data[leftSpot];
            data[leftSpot] = data[rightSpot];
            data[rightSpot] = temp;
        }
    }

    // prints the line
    void displayLine() const {
        if (isEmpty()) {
            std::cout << "[The hallway is completely empty.]" << std::endl;
            return;
        }

        std::cout << "[Front of Line] ";
        for (size_t i = 0; i < currentSize; i++) {
            // which in line / how many? basta kana
            size_t targetIndex = (frontIndex + i) % capacity;
            
            std::cout << data[targetIndex];
            
            // print arrow
            if (i < currentSize - 1) {
                std::cout << " -> ";
            }
        }
        std::cout << " [Back of Line]" << std::endl;
    }
};