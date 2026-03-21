# Mini Library of Data Structures

A C++ library that implements common Abstract Data Types (ADTs) using different underlying data structures. Built as a final project for **CMSC 123 — Data Structures and Algorithms**.

Each implementation follows a shared interface, making it easy to compare how different data structures affect the performance and behavior of the same ADT operations.

---

## Core Technical Concepts

This project explores the relationship between **Abstract Data Types** and the data structures that implement them. The same ADT (e.g. a Sorted Set) can be implemented in multiple ways — a Skip List gives O(log n) *expected* time while a Red-Black Tree gives O(log n) *worst-case* guaranteed time. The goal is to understand those trade-offs hands-on.

Structures implemented:

| ADT | Underlying Structure | Time Complexity |
|---|---|---|
| FILO Queue | Array Stack | O(1) push/pop |
| FIFO Queue | Singly Linked List | O(1) enqueue/dequeue |
| Priority Queue | Meldable Heap | O(log n) add/remove |
| Deque / List | Array Deque | O(1) amortized ends |
| List | Doubly Linked List | O(n) get, O(1) add/remove at node |
| Sorted Set | Skip List | O(log n) expected |
| Sorted Set | Red-Black Tree | O(log n) worst-case |
| Unsorted Set | Chained Hash Table | O(1) expected |
| Graph | Adjacency Matrix | O(1) edge lookup |

---

## Getting Started

### Requirements
- `g++` with C++17 support
- Works on Windows, Linux, and macOS

### Project Structure

```
Mini-Library-of-Data-Structures/
├── interface/       # Abstract base classes (List, SSet, etc.)
├── backing/         # Backing structures (dynamic array, node, etc.)
├── src/             # ADT implementations
└── tests/           # Test file for each implementation
```

### Running a Test

Navigate to the `tests/` folder and compile the test file for whichever structure you want:

```bash
g++ testRedBlackTree.cpp -o testRedBlackTree
./testRedBlackTree
```

All test files follow the same pattern — just swap the filename.

---

## Benchmarking

Every test file includes a **crude benchmark** that measures the execution time of each data structure under 100,000 repeated operations. Benchmarks are timed using `std::chrono` and cover the most meaningful operations for each structure — inserts, removes, searches, and access patterns.

This makes it easy to observe real performance differences, such as why inserting at the front of an Array Deque is ~300x slower than inserting at the back, or why a Red-Black Tree guarantees O(log n) even in the worst case while a Skip List only promises it on average.

Sample benchmark output from the **Array Deque** (100,000 operations):

```
Insert 100,000 elements at back:       0.0013 seconds
Insert 100,000 elements at front:      0.4148 seconds
Get 100,000 elements (random index):   ~0.0000 seconds
Remove 100,000 elements from back:     0.0006 seconds
Remove 100,000 elements from front:    0.4154 seconds
```

To run the benchmarks, simply compile and run any test file — the benchmark output appears at the end of each run automatically.

---

## Contact

**Hyacinth Agustin** — UP CEBU, CMSC 123, 2025–2026
**Russell Beduya** — UP CEBU, CMSC 123, 2025–2026
**Sean Mayol** — UP CEBU, CMSC 123, 2025–2026
