#pragma once
#include <iostream>
#include "../interface/queue.h" // Fixed from graph.h
#include <cstdlib>
#include <algorithm>
#include <stdexcept> // Added so we can throw errors if peeking/removing when empty

template <typename T>
class MeldableHeap : public Queue<T>
{
private:
    struct Node
    {
        T data;
        Node *left = nullptr;
        Node *right = nullptr;

        Node(T val) : data(val) {}
    };

    size_t n;
    Node *root;

    Node *merge(Node *h1, Node *h2)
    {
        if (h1 == nullptr)
            return h2;
        if (h2 == nullptr)
            return h1;

        if (h1->data > h2->data)
            return merge(h2, h1);

        if (std::rand() % 2 == 0)
        {
            h1->left = merge(h1->left, h2);
        }
        else
        {
            h1->right = merge(h1->right, h2);
        }
        return h1;
    }

    void clear(Node *node)
    {
        if (node != nullptr)
        {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

public:
    MeldableHeap() : n(0), root(nullptr)
    {
    }

    ~MeldableHeap()
    {
        clear(root);
    }

    void add(const T &x) override
    {
        Node *newNode = new Node(x);
        root = merge(root, newNode);
        n++;
    }

    T remove() override
    {
        if (isEmpty())
        {
            throw std::out_of_range("Cannot remove from an empty heap.");
        }

        T removedItem = root->data;
        Node *oldRoot = root;
        root = merge(root->left, root->right);
        delete oldRoot;
        n--;
        return removedItem;
    }

    T peek() const override
    {
        if (isEmpty())
        {
            throw std::out_of_range("Cannot peek at an empty heap.");
        }
        return root->data;
    }

    bool isEmpty() const override
    {
        return (n == 0);
    }

    size_t size() const override
    {
        return n;
    }
};