#include <iostream>
#include "../interface/queue.h"
#include "../backing/array.h"
#include <algorithm>

template <typename T>
class BinaryHeap : public Queue<T>
{
protected:
    ::array<T> backingArray;

public:
    BinaryHeap() {}

    // Add function that respects heap property
    void add(const T &x) override
    {
        backingArray.add(backingArray.size(), x);
        bubbleUp(backingArray.size() - 1);
    }

    // Remove function that complies with the heap property after removing
    T remove() override
    {
        T temp = backingArray.get(0);
        backingArray.set(0, backingArray[backingArray.size() - 1]);
        backingArray.set(backingArray.size() - 1, temp);
        backingArray.remove(backingArray.size() - 1);
        trickleDown(0);
        return temp;
    }

    T peek() const override
    {
        return backingArray[0];
    }

    bool isEmpty() const override
    {
        return backingArray.size() == 0;
    }

    size_t size() const override
    {
        return backingArray.size();
    }

    int left(int i)
    {
        return 2 * i + 1;
    }
    int right(int i)
    {
        return 2 * i + 2;
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }

    // Function for maintaining heap property if ever the child node is less than it's parent
    void bubbleUp(size_t i)
    {
        int p = parent(i);
        while (i > 0 && backingArray[i] < backingArray[parent(i)])
        {
            T temp = backingArray[i];
            backingArray[i] = backingArray[parent(i)];
            backingArray[parent(i)] = temp;

            i = p;
            p = parent(i);
        }
    }
    size_t getSmallest(const size_t i) // helper function to get smallest between two children
    {
        size_t left = (left(i) < backingArray.size()) ? left(i) : 0;
        size_t right = (right(i) < backingArray.size()) ? right(i) : 0;
        if (left > 0 && right > 0)
        {
            return (backingArray[left(i)] < backingArray[right(i)]) ? left(i) : right(i);
        }
        else
        {

            return left;
        }
    }
    void trickleDown(size_t i)
    {

        size_t smallest = getSmallest(i);

        while (smallest > 0 && backingArray[i] > backingArray[smallest])
        {
            T temp = backingArray[i];
            backingArray[i] = backingArray[smallest];
            backingArray[smallest] = temp;

            i = smallest;
            smallest = getSmallest(i);
        }
    }
};
