#pragma once
#include <cstddef>
#include <vector>
#include <list>
#include <functional>
#include <random>
#include <stdexcept>
#include "../interface/uSet.h"

template <typename T>
class ChainedHashTable : public USet<T>
{
private:
    std::vector<std::list<T>> t;
    size_t n;
    int d;
    unsigned z;
    static const int w = 32;

    unsigned generate_random_odd()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<unsigned> dis;
        return dis(gen) | 1;
    }

    int hash(T x) const
    {
        unsigned hash_code = std::hash<T>{}(x);
        return (z * hash_code) >> (w - d);
    }

    void resize()
    {
        d++;
        std::vector<std::list<T>> old_t = std::move(t);
        t.assign(1 << d, std::list<T>());
        n = 0;
        for (const auto &bucket : old_t)
        {
            for (const T &x : bucket)
            {
                t[hash(x)].push_back(x);
                n++;
            }
        }
    }

public:
    ChainedHashTable() : n(0), d(1)
    {
        z = generate_random_odd();
        t.resize(1 << d);
    }

    size_t size() const override
    {
        return n;
    }

    bool add(T x) override
    {
        int h = hash(x);
        for (const T &item : t[h])
        {
            if (item == x)
            {
                return false;
            }
        }

        if (n + 1 > t.size())
        {
            resize();
            h = hash(x);
        }

        t[h].push_back(x);
        n++;
        return true;
    }

    T remove(T x) override
    {
        int h = hash(x);
        for (auto it = t[h].begin(); it != t[h].end(); ++it)
        {
            if (*it == x)
            {
                T removed_item = *it;
                t[h].erase(it);
                n--;
                return removed_item;
            }
        }
        throw std::invalid_argument("Item not found");
    }

    T find(T x) override
    {
        int h = hash(x);
        for (const T &item : t[h])
        {
            if (item == x)
            {
                return item;
            }
        }
        return T{};
    }
};