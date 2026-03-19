#pragma once
#include "../interface/list.h" 
#include <stdexcept>

template <typename T>
class DLL : public List<T> {
private:
    
    struct Node {
        T data;
        Node* personAheadOfMe;  //prev node
        Node* personBehindMe;   //next node
        
        Node(T val) : data(val), personAheadOfMe(nullptr), personBehindMe(nullptr) {}
    };

    Node* frontOfList; // head
    Node* backOfList;  // tail
    size_t currentSize;

    // where to start searching
    Node* findStudentAt(size_t index) const {
        if (index >= currentSize) {
            throw std::out_of_range("No one is here lagi");
        }

        Node* searcher;
        // if person is at first half of index then start at front
        if (index < currentSize / 2) {
            searcher = frontOfList;
            for (size_t i = 0; i < index; i++) {
                searcher = searcher->personBehindMe;
            }
        } 
        // else start at back 
        else {
            searcher = backOfList;
            for (size_t i = currentSize - 1; i > index; i--) {
                searcher = searcher->personAheadOfMe;
            }
        }
        return searcher;
    }

public:
    DLL() {
        frontOfList = nullptr;
        backOfList = nullptr;
        currentSize = 0;
    }

    ~DLL() {
        while (currentSize > 0) {
            remove(0); // remove one by one
        }
    }


    void add(const size_t i, const T& x) override {
        if (i > currentSize) {
            throw std::out_of_range("Index out of bounds.");
        }

        Node* newcomer = new Node(x);

        // adding at front
        if (i == 0) {
            if (currentSize == 0) {
                frontOfList = newcomer;
                backOfList = newcomer;
            } else {
                newcomer->personBehindMe = frontOfList;
                frontOfList->personAheadOfMe = newcomer;
                frontOfList = newcomer;
            }
        }
        // adding at back
        else if (i == currentSize) {
            newcomer->personAheadOfMe = backOfList;
            backOfList->personBehindMe = newcomer;
            backOfList = newcomer;
        }
        // adding between, gotta find the student 
        else {
            Node* personAtCurrentSpot = findStudentAt(i);
            Node* personBeforeThem = personAtCurrentSpot->personAheadOfMe;

            // tell the person around the student to know they are there
            newcomer->personAheadOfMe = personBeforeThem;
            newcomer->personBehindMe = personAtCurrentSpot;

            // node pointing bruh
            personBeforeThem->personBehindMe = newcomer;
            personAtCurrentSpot->personAheadOfMe = newcomer;
        }
        currentSize++;
    }

    T remove(const size_t i) override {
        if (currentSize == 0) {
            throw std::out_of_range("No one to remove breh");
        }
        
        Node* target = findStudentAt(i);
        T savedData = target->data;

        // if removing front
        if (target == frontOfList) {
            frontOfList = target->personBehindMe;
            if (frontOfList != nullptr) {
                frontOfList->personAheadOfMe = nullptr;
            } else {
                backOfList = nullptr; // empty list
            }
        }
        // removing back
        else if (target == backOfList) {
            backOfList = target->personAheadOfMe;
            backOfList->personBehindMe = nullptr;
        }
        // removing in middle
        else {
            Node* personBefore = target->personAheadOfMe;
            Node* personAfter = target->personBehindMe;

            // let them forget the student who was there lmao
            personBefore->personBehindMe = personAfter;
            personAfter->personAheadOfMe = personBefore;
        }

        delete target;
        currentSize--;
        return savedData;
    }

    T get(const size_t i) const override {
        return findStudentAt(i)->data; // found this online hekhok
    }

    T set(const size_t i, const T& x) override {
        Node* target = findStudentAt(i);
        T oldData = target->data;
        target->data = x; // student got repalced
        return oldData;
    }

    size_t size() const override {
        return currentSize;
    }
};