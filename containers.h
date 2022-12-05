#pragma once
#include <iostream>
/*
- Queue "Uses the FIFO (first-in, first-out) ordering principle"
- Stack "Uses the LIFO (last-in, first-out) ordering principle"
- Linked List "A data structure that contains a group of nodes which together represent a sequence"
*/

class Node
{
    Node *next;
    Node *previous;
    int index;
    std::string Data;

    //setters
    void setNext(Node* next) {
        this->next = next;
        //if the next pointer is not null
        if (this->next){
            //set the previous pointer of next to this
            this->next->setPrevious(this);
        }
    }
    void setPrevious(Node* previous){
        this->previous = previous;
    }
    //getters
    Node* getNext() const  { return this->next; }
    Node* getPrevious() const { return this->previous; }
public:
    explicit Node(Node *previous, std::string Data, Node *next)
    {
        this->next = nullptr;
        this->previous = nullptr;
    }
    ~Node()
    {
        
        //if next or previous is not nullptr set it to nullptr
        if (this->next){
            this->next = nullptr;
        }
        if (this->previous){
            this->previous = nullptr;
        }
        delete next;
        delete previous;
        // set index to -1
        //std::cout << "Destroyed Node located at " << this << std::endl;
    }
};
// end of containers.h
