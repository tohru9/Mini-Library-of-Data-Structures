#include <iostream>
#include "../src/MeldableHeap.h"
#include <chrono>
using namespace std::chrono;
using namespace std;

const int N = 1000000;
int main()
{
    MeldableHeap<int> heap;

    std::cout << "=== Functional Test ===" << std::endl;

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

    // Benchmark
    cout << "\n=== Benchmark (" << N << " operations) ===" << endl;
    MeldableHeap <int> bench;

    high_resolution_clock::time_point start, stop;
    duration<double> dur;

    //benchmark 1: N insertions (add)
    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        bench.add(i);
    }
    stop = high_resolution_clock::now();
    dur = stop - start;
    cout << "Add    " << N << " elements:              " << dur.count() << " seconds" << endl;

    //benchmark 2: N peeks
    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        bench.peek();
    }
    stop = high_resolution_clock::now();
    dur = stop - start;
    cout << "Peek   " << N << " times:                 " << dur.count() << " seconds" << endl;

     // Benchmark 3: N removals 
    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        bench.remove();
    }
    stop = high_resolution_clock::now();
    dur = stop - start;
    cout << "Remove " << N << " elements:              " << dur.count() << " seconds" << endl;
 
    // Benchmark 4: alternating add and remove
    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        bench.add(i);
        bench.remove();
    }
    stop = high_resolution_clock::now();
    dur = stop - start;
    cout << "Alternating add/remove " << N << " times: " << dur.count() << " seconds" << endl;
    return 0;


}