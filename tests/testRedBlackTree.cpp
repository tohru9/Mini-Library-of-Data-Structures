#include <iostream>
#include "../src/RedBlackTree.h"
#include <chrono> 
using namespace std::chrono;
using namespace std;

const int N = 1000000;

int main() {

    RedBlackTree<int> tree;

    // === Functional Test ===
    // ADD
    cout << "Adding elements: 5, 9, 2, 1, 6, 10, 3, 4" << endl;
    tree.add(5);
    tree.add(9);
    tree.add(2);
    tree.add(1);
    tree.add(6);
    tree.add(10);
    tree.add(3);
    tree.add(4);

    cout << "Tree after adding all elements:" << endl;
    tree.printTree();
    cout << endl;

    cout << "Size: " << tree.size() << endl;

    // FIND
    cout << "\nFinding elements..." << endl;

    cout << "find(6)  = " << tree.find(6)  << endl;
    cout << "find(1)  = " << tree.find(1)  << endl;
    cout << "find(10) = " << tree.find(10) << endl;
    cout << "find(99) = " << tree.find(99) << " (not in tree, expect 0)" << endl;

    // DUPLICATE
    cout << "\nAdding duplicate 5 (should be ignored)..." << endl;
    tree.add(5);
    cout << "Size after duplicate add: " << tree.size() << " (expect 8)" << endl;

    // REMOVE
    cout << "\nRemoving 5..." << endl;
    int removed = tree.remove(5);
    cout << "Removed value: " << removed << endl;
    cout << "Tree after remove(5):" << endl;
    tree.printTree();
    cout << endl;

    cout << "\nRemoving 9..." << endl;
    removed = tree.remove(9);
    cout << "Removed value: " << removed << endl;
    cout << "Tree after remove(9):" << endl;
    tree.printTree();
    cout << endl;

    cout << "\nRemoving 10..." << endl;
    removed = tree.remove(10);
    cout << "Removed value: " << removed << endl;
    cout << "Tree after remove(10):" << endl;
    tree.printTree();
    cout << endl;

    cout << "\nRemoving non-existent element 99..." << endl;
    removed = tree.remove(99);
    cout << "Removed value: " << removed << " (not found, expect 0)" << endl;

    // REMOVE REMAINING
    cout << "\nRemoving remaining elements: 1, 2, 3, 4, 6..." << endl;
    tree.remove(1);
    tree.remove(2);
    tree.remove(3);
    tree.remove(4);
    tree.remove(6);

    cout << "Tree after removing all elements:" << endl;
    tree.printTree();
    cout << endl;

    cout << "Final size: " << tree.size() << " (expect 0)" << endl;

    // Benchmark
    cout << "\n=== Benchmark (" << N << " operations) ===" << endl;

    RedBlackTree<int> bench;
    high_resolution_clock::time_point start, stop;
    duration<double> dur;

    // Benchmark 1: N in-order insertions (add) -- worst case
    start = high_resolution_clock::now();
    for(int i = 0; i < N; i++){
        bench.add(i);
    }
    stop = high_resolution_clock::now();
    dur = stop - start;
    cout << "Insert " << N << " elements (sorted order): " << dur.count() << " seconds" << endl;

    //Benchmark 2: N successful finds
    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        bench.find(i);
    }
    stop = high_resolution_clock::now();
    dur = stop - start;
    cout << "Find   " << N << " elements (all present):  " << dur.count() << " seconds" << endl;

    // Benchmark 3: N unsuccessful finds
    start = high_resolution_clock::now();
    for (int i = N; i < 2 * N; i++) {
        bench.find(i);
    }
    stop = high_resolution_clock::now();
    dur = stop - start;
    cout << "Find   " << N << " elements (none present): " << dur.count() << " seconds" << endl;
 
    // Benchmark 4: N removals
    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        bench.remove(i);
    }
    stop = high_resolution_clock::now();
    dur = stop - start;
    cout << "Remove " << N << " elements:                " << dur.count() << " seconds" << endl;
 
    return 0;
}
