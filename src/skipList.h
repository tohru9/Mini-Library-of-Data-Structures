#pragma once
#include "../interface/uSet.h" 
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

using namespace std;

template <typename T>
class SkipList : public USet<T> {
private:
    struct Node {
        T data;
        vector<Node*> forwardLanes; // pointers for express lanes
        
        Node(T val, int level) : data(val), forwardLanes(level + 1, nullptr) {}
    };

    Node* frontDoor; // dummy head node
    int maxLevel;    
    int currentHighestLevel; 
    size_t currentSize;

    // coin flip for express lane
    int flipCoinForExpressLane() {
        int level = 0;
        while (rand() % 2 == 0 && level < maxLevel) {
            level++;
        }
        return level;
    }

public:
    SkipList(int maxLvl = 4) {
        maxLevel = maxLvl;
        currentHighestLevel = 0;
        currentSize = 0;
        srand(time(0)); 

        frontDoor = new Node(T(), maxLevel); 
    }

    ~SkipList() {
        Node* current = frontDoor;
        while (current != nullptr) {
            Node* nextNode = current->forwardLanes[0]; // level 0 walk
            delete current;
            current = nextNode;
        }
    }

    size_t size() const override {
        return currentSize;
    }

    bool add(T x) override {
        vector<Node*> update(maxLevel + 1, nullptr);
        Node* searcher = frontDoor;

        // find position
        for (int i = currentHighestLevel; i >= 0; i--) {
            while (searcher->forwardLanes[i] != nullptr && searcher->forwardLanes[i]->data < x) {
                searcher = searcher->forwardLanes[i];
            }
            update[i] = searcher; 
        }

        searcher = searcher->forwardLanes[0];

        // check for duplicates
        if (searcher != nullptr && searcher->data == x) {
            return false; 
        }

        int newLevel = flipCoinForExpressLane();
        
        // update max level if needed
        if (newLevel > currentHighestLevel) {
            for (int i = currentHighestLevel + 1; i <= newLevel; i++) {
                update[i] = frontDoor;
            }
            currentHighestLevel = newLevel;
        }

        // insert node and update links
        Node* newcomer = new Node(x, newLevel);
        for (int i = 0; i <= newLevel; i++) {
            newcomer->forwardLanes[i] = update[i]->forwardLanes[i];
            update[i]->forwardLanes[i] = newcomer;
        }
        
        currentSize++;
        return true; 
    }

    T remove(T x) override {
        vector<Node*> update(maxLevel + 1, nullptr);
        Node* searcher = frontDoor;

        for (int i = currentHighestLevel; i >= 0; i--) {
            while (searcher->forwardLanes[i] != nullptr && searcher->forwardLanes[i]->data < x) {
                searcher = searcher->forwardLanes[i];
            }
            update[i] = searcher;
        }

        searcher = searcher->forwardLanes[0];

        // remove node links
        if (searcher != nullptr && searcher->data == x) {
            for (int i = 0; i <= currentHighestLevel; i++) {
                if (update[i]->forwardLanes[i] != searcher) break;
                update[i]->forwardLanes[i] = searcher->forwardLanes[i];
            }
            
            // lower max level if needed
            while (currentHighestLevel > 0 && frontDoor->forwardLanes[currentHighestLevel] == nullptr) {
                currentHighestLevel--;
            }
            
            T savedData = searcher->data;
            delete searcher;
            currentSize--;
            return savedData;
        }
        
        throw out_of_range("Wala man siya diri! (Who are you trying to remove??)");
    }

    T find(T x) override {
        Node* searcher = frontDoor;
        
        // fast-forward search
        for (int i = currentHighestLevel; i >= 0; i--) {
            while (searcher->forwardLanes[i] != nullptr && searcher->forwardLanes[i]->data < x) {
                searcher = searcher->forwardLanes[i];
            }
        }
        
        searcher = searcher->forwardLanes[0];

        if (searcher != nullptr && searcher->data == x) {
            return searcher->data; 
        }

        throw out_of_range("Kinsa man na? Absent siya today ois!");
    }

    // display express lanes
    void displayLanes() const {
        cout << "\n Database Layout " << endl;
        for (int i = currentHighestLevel; i >= 0; i--) {
            cout << "Level " << i << " (Express): frontDoor -> ";
            Node* current = frontDoor->forwardLanes[i];
            while (current != nullptr) {
                cout << "[" << current->data << "] -> ";
                current = current->forwardLanes[i];
            }
            cout << "nullptr" << endl;
        }
    }
};