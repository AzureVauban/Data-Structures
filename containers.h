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

        void setNext(Node *next, const bool first_step = true);
        void setPrevious(Node *previous, const bool first_step = true);

    private:
        void setData(std::string Data)
        {
            this->Data = std::move(Data);
        }

    public:
        void setIndex(const int index);

        // getters

        Node *getNext();
        Node *getPrevious();
        const int getIndex();
        const std::string &getData() ;

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

    // determine if the Queue is empty or not
    bool isEmpty() const { return this->Front == nullptr; }

    // append a Node to the end of the queue
    void enqueue(const std::string Data)
    {
        if (this->isEmpty())
        {
            // overwrite the head-most node
            this->setFront(new Node(nullptr, std::move(Data), nullptr));
        }
        else
        {
            Node *endpoint = this->getEnd();
            // create a new endpoint
            endpoint->setNext(new Node(endpoint, std::move(Data), nullptr));
        }
    }

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
        delete Front;
    }
};
// end of containers.h
