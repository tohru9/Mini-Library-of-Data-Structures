#pragma once
#include <cstddef>
#include <memory>
#include "list.h"

template <typename T>
struct Graph
{
    virtual void addEdge(const size_t i, const size_t j) = 0; // add edge (i,j) to the graph

    virtual void removeEdge(const size_t i, const size_t j) = 0; // remove edge (i,j) from the graph

    virtual bool hasEdge(const size_t i, const size_t j) const = 0; // returns true if edge (i,j) is in the graph

    virtual List<size_t> *outEdges(const size_t i) = 0; // returns a list of vertices that i is pointing to

    virtual List<size_t> *inEdges(const size_t i) = 0; // returns a list of vertices that are pointing to i
};