#include <iostream>
#include "../src/MeldableHeap.h"

int main()
{
    MeldableHeap<int> heap;

    std::cout << "--- Testing MeldableHeap ---" << std::endl;

    std::cout << "\nAdding elements: 42, 17, 8, 99, 23" << std::endl;
    heap.add(42);
    heap.add(17);
    heap.add(8);
    heap.add(99);
    heap.add(23);

    std::cout << "Current size: " << heap.size() << " (Expected: 5)" << std::endl;
    std::cout << "Top element: " << heap.peek() << " (Expected: 8)" << std::endl;

    std::cout << "\nRemoving top element (" << heap.remove() << ")..." << std::endl;
    std::cout << "New size: " << heap.size() << " (Expected: 4)" << std::endl;
    std::cout << "New top element: " << heap.peek() << " (Expected: 17)" << std::endl;

    std::cout << "\nDraining the rest of the heap:" << std::endl;
    std::cout << "Output: ";
    while (!heap.isEmpty())
    {
        std::cout << heap.remove() << " ";
    }
    std::cout << "\n(Expected Output: 17 23 42 99)" << std::endl;

    std::cout << "\nFinal size: " << heap.size() << " (Expected: 0)" << std::endl;

    return 0;
}