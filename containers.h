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

    // setters
    void setNext(Node *next, const bool first_step = true)
    {
        this->next = next;
        // if the next pointer is not null
        if (this->next && first_step)
        {
            // set the previous pointer of next to this
            this->next->setPrevious(this), false;
        }
    }
    void setPrevious(Node *previous, const bool first_step = true)
    {
        this->previous = previous;
        // if the previous is not null
        if (this->previous && first_step)
        {
            // set the next pointer of previous to this
            this->previous->setNext(this, false);
        }
    }
    void setData(std::string Data)
    {
        this->Data = std::move(Data);
    }
    void setIndex(const int index) { this->index = index; }
    // getters
    Node *getNext() const { return this->next; }
    Node *getPrevious() const { return this->previous; }

public:
    explicit Node(Node *previous, std::string Data, Node *next)
    {
        this->setNext(previous);
        this->setPrevious(next);
        this->setData(std::move(Data));
    }
    ~Node()
    {

        // if next or previous is not nullptr set it to nullptr
        if (this->next)
        {
            this->next = nullptr;
        }
        if (this->previous)
        {
            this->previous = nullptr;
        }
        delete next;
        delete previous;
        this->index = -1;
        // std::cout << "Destroyed Node located at " << this << std::endl;
    }
};
// end of containers.h
