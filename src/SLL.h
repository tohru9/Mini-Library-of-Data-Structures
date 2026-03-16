#pragma once
#include "../interface/queue.h"
#include <stdexcept> // for errors (throw)

template <typename T>
class SLL : public Queue<T> {
private:
    // general node struct
    struct Node {
        T data;
        Node* next;
        // creates a node each time we call the struct
        Node(T val){
            data = val;
            next = nullptr;
        }
    };

    Node* head; // first or front of the list
    Node* tail; // last or back of the list

public:
    // constructor for empty queue
    SLL() {
        head = nullptr;
        tail = nullptr;
    }

    // deconstructor
    ~SLL() {
        while (!empty()) {
            remove();
        }
    }

    // adds the element to the back of the list
    void add(const T& x) override {
        Node* newNode = new Node(x);
        
        if (empty()) {
            // if list was empty then the added element is both head and tail
            head =  newNode;
            tail = newNode;
        } else {
            // else the added element is at the back or tail
            tail->next = newNode;
            tail = newNode;
        }
    }

    // removes and display the head of the list
    T remove() override {
        if (empty()) {
            throw std::out_of_range("Invalid, the queue is empty.");
        }
        
        Node* temp = head;          // create a temporary node to store data
        T removedData = temp->data; // store data in temporary node
        head = head->next;          //move pointer to next in line
        
        // if no one is next then set everything to null
        if (head == nullptr) {
            tail = nullptr;
        }
        //free
        delete temp;            
        //display what element was popped or removed   
        return removedData;
    }

    // isEmpty
    bool empty() const override {
        return head == nullptr;
    }

//NEW ADDITIONS / TWISTS sabi kc ni sir pwede
void letSenior(const T& cane){
    Node* senior = new Node(cane);
     if (empty()) {
            // if list was empty then the senior is both head and tail
            head =  senior;
            tail = senior;
        } else {
            // else the senior will now be at the front
            senior->next = head;
            head = senior;
        }
    }
T whoYou() const {
    if(empty()){
        throw std::out_of_range("Ghost??");
    }
    else {
        return head->data; //returns the element at the front of the line
    }
}

T whoNext() const {
    if(empty()){
        throw std::out_of_range("Who you calling???");
    }
    else if(head->next != nullptr){
        return head->next->data; //returns the second element at the line
    }
    else {
        throw std::out_of_range("Who you calling??? again brotato");
    }
}

T whoLast() const {
    if(empty()){
        throw std::out_of_range("blud???");
    }
    else {
        return tail->data; //returns the last element at the line
    }
}

};

