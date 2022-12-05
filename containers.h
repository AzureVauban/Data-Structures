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
    //! let the class this node is composed within handle its indexing
    int index;
    std::string Data;

public:
    // setters

    void setNext(Node *next, const bool first_step = true)
    {
        this->next = next;
        // if the next pointer is not null
        if (this->next && first_step)
        {
            // set the previous pointer of next to this
            this->next->setPrevious(this), false;
            // set the index of this node based on the index of the previous node
            //! this->setIndex(this->getNext()->getIndex() - 1);
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
            // set the index of this node based on the index of the next node
            //! this->setIndex(this->getPrevious()->getIndex() + 1);
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
    const int getIndex() const { return this->index; }
    const std::string &getData() const { return this->Data; }

public:
    // constructor

    explicit Node(Node *previous, std::string Data, Node *next)
    {
        this->setIndex(0);
        this->setNext(next);
        this->setPrevious(previous);
        this->setData(std::move(Data));
    }

    // destructors
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
