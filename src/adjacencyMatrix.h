#include <iostream>
#include "../interface/graph.h"
#include <memory>
#include "arrayDequeList.h"

template <typename T>
class AdjacencyMatrix : public Graph<T>
{
    size_t n; // number of vertices

    bool **matrix; // adjacency matrix

public:
    AdjacencyMatrix(size_t n) : n(n)
    {
        matrix = new bool *[n];
        for (size_t i = 0; i < n; i++)
        {
            matrix[i] = new bool[n]();
        }
    }
    ~AdjacencyMatrix()
    {
        for (size_t i = 0; i < n; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void addEdge(const size_t i, const size_t j) override
    {
        matrix[i][j] = true;
    }

    void removeEdge(const size_t i, const size_t j) override
    {
        matrix[i][j] = false;
    }

    bool hasEdge(const size_t i, const size_t j) const override
    {
        return matrix[i][j];
    }

    List<size_t> *outEdges(const size_t i) override
    {
        auto *out = new ArrayDeque<size_t>();
        for (size_t j = 0; j < n; j++)
        {
            if (matrix[i][j])
            {
                out->add(out->size(), j);
            }
        }

        return out;
    }

    List<size_t> *inEdges(const size_t i) override
    {
        auto *in = new ArrayDeque<size_t>();
        for (size_t j = 0; j < n; j++)
        {
            if (matrix[j][i])
            {
                in->add(in->size(), j);
            }
        }

        return in;
    }
    void display()
    {
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};
