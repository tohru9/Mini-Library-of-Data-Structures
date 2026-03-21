#include <iostream>
#include <cstddef>
#include<string>
#include "../src/arrayStack.h"
#include <chrono>
using namespace std::chrono;
using namespace std;

const int N = 1000000;

int main() {

    ArrayStack<int> stack;
    //=== Functional Test ===
    stack.push(10);
    stack.push(20);
    stack.push(30);
    std::cout << "Top: " << stack.top() << std::endl;    // 30
    std::cout << "Pop: " << stack.pop() << std::endl;    // 30
    std::cout << "Top: " << stack.top() << std::endl;    // 20
    std::cout << "Size: " << stack.size() << std::endl;  // 2

    std::cout << "Pop: " << stack.pop() << std::endl;    // 20
    std::cout << "Size: " << stack.size() << std::endl;  // 1
    std::cout << "Top: " << stack.top() << std::endl;    // 10

    std::cout << "Pop: " << stack.pop() << std::endl;    // 10
    std::cout << "Size: " << stack.size() << std::endl;  // 0

    stack.push(60);
    std::cout << "Top: " << stack.top() << std::endl;    // 60
    std::cout << "Size: " << stack.size() << std::endl;  // 1
    std::cout << "Pop: " << stack.pop() << std::endl;    // 60
    std::cout << "Size: " << stack.size() << std::endl;  // 0

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    std::cout << "Size: " << stack.size() << std::endl;  // 5
    std::cout << "Pop: " << stack.pop() << std::endl;    // 5
    std::cout << "Pop: " << stack.pop() << std::endl;    // 4
    std::cout << "Pop: " << stack.pop() << std::endl;    // 3
    std::cout << "Pop: " << stack.pop() << std::endl;    // 2
    std::cout << "Pop: " << stack.pop() << std::endl;    // 1
    std::cout << "Size: " << stack.size() << std::endl;  // 0

    stack.push(-5);
    stack.push(0);
    stack.push(-1);
    std::cout << "Top: " << stack.top() << std::endl;    // -1
    std::cout << "Pop: " << stack.pop() << std::endl;    // -1
    std::cout << "Pop: " << stack.pop() << std::endl;    // 0
    std::cout << "Pop: " << stack.pop() << std::endl;    // -5
    std::cout << "Size: " << stack.size() << std::endl;  // 0

    stack.push(7);
    stack.push(7);
    stack.push(7);
    std::cout << "Size: " << stack.size() << std::endl;  // 3
    std::cout << "Pop: " << stack.pop() << std::endl;    // 7
    std::cout << "Pop: " << stack.pop() << std::endl;    // 7
    std::cout << "Pop: " << stack.pop() << std::endl;    // 7
    std::cout << "Size: " << stack.size() << std::endl;  // 0

    stack.push(42);
    std::cout << "Top: " << stack.top() << std::endl;    // 42
    std::cout << "Top: " << stack.top() << std::endl;    // 42 (still there)
    std::cout << "Size: " << stack.size() << std::endl;  // 1
    std::cout << "Pop: " << stack.pop() << std::endl;    // 42
    std::cout << "Size: " << stack.size() << std::endl;  // 0

    // Benchmark 1: N pushes
    cout << "\n=== Benchmark (" << N << " operations) ===" << endl;
 
    ArrayStack<int> bench;
 
    auto start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        bench.push(i);
    }
    auto stop = high_resolution_clock::now();
    duration<double> dur = stop - start;
    cout << "Push " << N << " elements:         " << dur.count() << " seconds" << endl;

    // Benchmark 2: N tops (peek) 
    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        bench.top();
    }
    stop = high_resolution_clock::now();
    dur = stop - start;
    cout << "Top " << N << " times:         " << dur.count() << " seconds" << endl;

    // Benchmark 3: N pops 
    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        bench.pop();
    }
    stop = high_resolution_clock::now();
    dur = stop - start;
    cout << "Pop " << N << " elements:         " << dur.count() << " seconds" << endl;

    // Benchmark 3: Alternate push and pop 
    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        bench.push(i);
        bench.pop();
    }
    stop = high_resolution_clock::now();
    dur = stop - start;
    cout << "Push and Pop " << N << " elements:         " << dur.count() << " seconds" << endl;

}

