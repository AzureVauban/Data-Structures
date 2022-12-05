#pragma once
#include <iostream>
/*
- Queue "Uses the FIFO (first-in, first-out) ordering principle"
- Stack "Uses the LIFO (last-in, first-out) ordering principle"
- Linked List "A data structure that contains a group of nodes which together represent a sequence"
*/

// Uses the FIFO (first-in, first-out) ordering principle
class Queue
{
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

    private:
        void setData(std::string Data)
        {
            this->Data = std::move(Data);
        }

    public:
        void setIndex(const int index) { this->index = index; }

        // getters

        Node *getNext() const { return this->next; }
        Node *getPrevious() const { return this->previous; }
        const int getIndex() const { return this->index; }
        const std::string &getData() const { return this->Data; }

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
    // end of Node class definition for Queue

    Node *Front;
    int Size;

    // setters

    void setFront(Node *Front) { this->Front = Front; }

    void setSize()
    {
        int new_size = 0;
        if (!this->isEmpty())
        {
            // traverse forward through the data structure
            Node *current = this->getFront();
            while (current)
            {
                current = current->getNext();
                new_size += 1;
            }
        }
        this->Size = new_size;
    }
    // getters

    Node *getFront() const { return this->Front; }

    Node *getEnd() const
    {
        Node *current = this->getFront();
        if (!this->isEmpty())
        {
            while (current)
            {
                current = current->getNext();
            }
        }
        return current;
    }

public:
    // functions

    const bool isEmpty() const { return this->Front == nullptr; }

public:
    // constructor

    explicit Queue()
    {
        this->setFront(nullptr);
        this->setSize();
    }
    // destructor

    ~Queue()
    {
    }
};
// end of containers.h
