#include <iostream>
// Adjust this include path to match whatever you named your header file
#include "../src/BinaryHeap.h"

int main()
{
    // Instantiate a BinaryHeap of integers
    BinaryHeap<int> heap;

    std::cout << "--- Testing BinaryHeap ---" << std::endl;

    // 1. Test adding elements
    std::cout << "\nAdding elements: 10, 5, 20, 3, 15" << std::endl;
    heap.add(10);
    heap.add(5);
    heap.add(20);
    heap.add(3);
    heap.add(15);

    std::cout << "Current size: " << heap.size() << " (Expected: 5)" << std::endl;

    // 2. Test peeking
    // Note: The expected output depends on whether you intend this to be a Min-Heap or Max-Heap.
    std::cout << "Top element: " << heap.peek() << std::endl;

    // 3. Test removing elements
    std::cout << "\nRemoving top element..." << std::endl;
    heap.remove();

    std::cout << "New size: " << heap.size() << " (Expected: 4)" << std::endl;
    std::cout << "New top element: " << heap.peek() << std::endl;

    // 4. Drain the rest of the heap
    std::cout << "\nDraining the rest of the heap:" << std::endl;
    while (heap.size() > 0)
    {
        std::cout << heap.peek() << " ";
        heap.remove();
    }
    std::cout << "\n\nFinal size: " << heap.size() << " (Expected: 0)" << std::endl;

    return 0;
}