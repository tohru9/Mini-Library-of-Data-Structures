#pragma once
#include "../interface/queue.h"
#include <stdexcept>

template <typename T>
class SLL : public Queue<T> {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) {
            data = val;
            next = nullptr;
        }
    };
    Node* head;
    Node* tail;

public:
    SLL() {
        head = nullptr;
        tail = nullptr;
    }

    ~SLL() {
        while (!isEmpty()) {
            remove();
        }
    }

    // adds the element to the back of the list
    void add(const T& x) override {
        Node* newNode = new Node(x);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // removes and returns the head of the list
    T remove() override {
        if (isEmpty()) {
            throw std::out_of_range("Invalid, the queue is empty.");
        }
        Node* temp = head;
        T removedData = temp->data;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
        return removedData;
    }

    // peek — returns front without removing (required by queue.h)
    T peek() const override {
        if (isEmpty()) {
            throw std::out_of_range("Ghost??");
        }
        return head->data;
    }

    // isEmpty — matches queue.h interface
    bool isEmpty() const override {
        return head == nullptr;
    }

    // empty — kept as alias so existing code still works
    bool empty() const {
        return head == nullptr;
    }

    // size — required by queue.h
    size_t size() const override {
        size_t count = 0;
        Node* curr = head;
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }
        return count;
    }

    // NEW ADDITIONS
    void letSenior(const T& cane) {
        Node* senior = new Node(cane);
        if (isEmpty()) {
            head = senior;
            tail = senior;
        } else {
            senior->next = head;
            head = senior;
        }
    }

    T whoYou() const {
        if (isEmpty()) {
            throw std::out_of_range("Ghost??");
        }
        return head->data;
    }

    T whoNext() const {
        if (isEmpty()) {
            throw std::out_of_range("Who you calling???");
        } else if (head->next != nullptr) {
            return head->next->data;
        } else {
            throw std::out_of_range("Who you calling??? again brotato");
        }
    }

    T whoLast() const {
        if (isEmpty()) {
            throw std::out_of_range("blud???");
        }
        return tail->data;
    }
};