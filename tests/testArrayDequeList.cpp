#include <iostream>
#include "../src/arrayDequeList.h"
#include <chrono>

using namespace std::chrono;
using namespace std;

const int N = 100000;

int main() {

    ArrayDeque<int> ListOfNums;

    // Functional test (original)
    cout << "=== Functional Test ===" << endl;

    cout << "Adding elements..." << endl;
    ListOfNums.add(0, 10);
    ListOfNums.add(1, 20);
    ListOfNums.add(2, 30);
    ListOfNums.add(1, 15);
    ListOfNums.add(3, 100);
    ListOfNums.add(0, 30);
    ListOfNums.add(1, 8);

    cout << "Current ListOfNums:" << endl;
    ListOfNums.printList();
    cout << endl;

    cout << "\nSetting index 2 to 99..." << endl;
    ListOfNums.set(2, 99);

    cout << "ListOfNums after set:" << endl;
    ListOfNums.printList();
    cout << endl;

    cout << "\nRemoving index 1..." << endl;
    int removed = ListOfNums.remove(1);
    cout << "Removed value: " << removed << endl;

    cout << "Final ListOfNums:" << endl;
    ListOfNums.printList();
    cout << endl;

    cout << "Final size: " << ListOfNums.size() << endl;

    // Benchmark 1: for N insertions at the back
    cout << "\n=== Benchmark (" << N << " operations) ===" << endl;

    ArrayDeque<int> bench;

    auto start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        bench.add(bench.size(), i);
    }
    auto stop = high_resolution_clock::now();
    duration<double> dur = stop - start;
    cout << "Insert " << N << " elements at back:       " << dur.count() << " seconds" << endl;

    // Benchmark 2: for N insertions at the front
    ArrayDeque<int> bench2;

    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        bench2.add(0, i);
    }
    stop = high_resolution_clock::now();
    dur = stop - start;
    cout << "Insert " << N << " elements at front:      " << dur.count() << " seconds" << endl;

    // Benchmark 3: for N random access gets
    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        bench.get(i % bench.size());
    }
    stop = high_resolution_clock::now();
    dur = stop - start;
    cout << "Get " << N << " elements (random index): " << dur.count() << " seconds" << endl;

    // Benchmark 4: for N removes from the back
    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        bench.remove(bench.size() - 1);
    }
    stop = high_resolution_clock::now();
    dur = stop - start;
    cout << "Remove " << N << " elements from back:    " << dur.count() << " seconds" << endl;

    // Benchmark 5: N removes from the front
    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        bench2.remove(0);
    }
    stop = high_resolution_clock::now();
    dur = stop - start;
    cout << "Remove " << N << " elements from front:   " << dur.count() << " seconds" << endl;

    return 0;
}