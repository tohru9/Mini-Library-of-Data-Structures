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

## Demo Application

A **Browser Tab Manager** is included as a practical demo of the Array Deque, simulating how a browser manages open tabs using front/back insertions, reordering, and a closed-tab history.

```bash
g++ testBrowserTabManager.cpp -o testBrowserTabManager
./testBrowserTabManager
```

---

## TODO

- [ ] Add iterator support across all structures
- [ ] Add more edge case tests
- [ ] Add time complexity annotations directly in source files

---

## Contact

**Hyacinth Agustin** — UP Cebu, CMSC 123, 2025–2026
**Sean Mayol** — UP Cebu, CMSC 123, 2025–2026
**Russell Beduya** — UP Cebu, CMSC 123, 2025–2026
