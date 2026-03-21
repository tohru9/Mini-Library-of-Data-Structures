#include <iostream>
#include <cassert>
#include "../src/adjacencyMatrix.h"
#include <chrono> 
#include <chrono>
using namespace std::chrono;
using namespace std;
 
const int N = 1000;

void test_function()
{
    std::cout << "Testing basic edge operations... " << std::endl;
    AdjacencyMatrix<int> graph(5);

    std::cout << "Testing addEdge and hasEdge functions" << std::endl;
    std::cout << "Add edge (0,1)" << std::endl;
    graph.addEdge(0, 1);
    std::cout << "Add edge (0,4)" << std::endl;
    graph.addEdge(0, 4);
    std::cout << "Add edge (3,2)" << std::endl;
    graph.addEdge(3, 2);

    graph.display();

    std::cout << "Check if edge (0, 1) exists: " << graph.hasEdge(0, 1) << std::endl;
    std::cout << "Check if edge (0, 4) exists: " << graph.hasEdge(0, 4) << std::endl;
    std::cout << "Check if edge (3, 2) exists: " << graph.hasEdge(3, 2) << std::endl;
    std::cout << "Check if edge (1, 0) exists: " << graph.hasEdge(1, 0) << std::endl;

    std::cout << "Testing removeEdge function" << std::endl;
    std::cout << "Removing edge (0, 1)" << std::endl;
    graph.removeEdge(0, 1);
    std::cout << "Check if edge (0, 1) exists: " << graph.hasEdge(0, 1) << std::endl;

    List<size_t> *out0 = graph.outEdges(0);
    std::cout << "Connections of index 0: ";
    for (size_t i = 0; i < out0->size(); i++)
    {
        std::cout << out0->get(i) << " ";
    }
    std::cout << std::endl;
    std::cout << "Connections towards index 2: ";
    List<size_t> *in2 = graph.inEdges(2);

    for (size_t i = 0; i < in2->size(); i++)
    {
        std::cout << in2->get(i) << " ";
    }
    std::cout << std::endl;
    std::cout << "Connections towards index 0: ";
    List<size_t> *in0 = graph.inEdges(0);
    for (size_t i = 0; i < in0->size(); i++)
    {
        std::cout << in0->get(i) << " ";
    }
}

int main()
{
    try
    {
        test_function();
        std::cout << "\n--- All Graph Tests Passed! ---" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Test failed with exception: " << e.what() << std::endl;
        return 1;
    }

    //Benchmark
    cout << "\n=== Benchmark (" << N << " vertices) ===" << endl;
 
    AdjacencyMatrix<int> bench(N);
 
    high_resolution_clock::time_point start, stop;
    duration<double> dur;
 
    // Benchmark 1: add all edges (complete graph)
    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) bench.addEdge(i, j);
        }
    }
    stop = high_resolution_clock::now();
    dur = stop - start;
    cout << "addEdge   for all pairs:  " << dur.count() << " seconds" << endl;
 
    // Benchmark 2: hasEdge on all pairs
    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            bench.hasEdge(i, j);
        }
    }
    stop = high_resolution_clock::now();
    dur = stop - start;
    cout << "hasEdge   for all pairs:  " << dur.count() << " seconds" << endl;
 
    // Benchmark 3: outEdges for every vertex
    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        bench.outEdges(i);
    }
    stop = high_resolution_clock::now();
    dur = stop - start;
    cout << "outEdges  for all vertices:       " << dur.count() << " seconds" << endl;
 
    // Benchmark 4: remove all edges
    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) bench.removeEdge(i, j);
        }
    }
    stop = high_resolution_clock::now();
    dur = stop - start;
    cout << "removeEdge for all pairs: " << dur.count() << " seconds" << endl;
 
    return 0;
}