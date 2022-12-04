#pragma once
#include <iostream>
/*
- Queue "Uses the FIFO (first-in, first-out) ordering principle"
- Stack "Uses the LIFO (last-in, first-out) ordering principle"
- Linked List "A data structure that contains a group of nodes which together represent a sequence"
*/
namespace List
{
    class Node
    {

        /* functionality:
        - automatically link node instances to one another when instantiated
        - automatically set the index of all connected nodes instances when instantiated
        */
        Node *Next;
        Node *Previous;
        int Index;
        std::string Data;

    public:
        // setters
        void setNext(Node *next)
        {
            Next = next;
            // set the index of the next node
            Next->setIndex(Index + 1);
            // if the next pointer is not null, set the previous pointer of the next instance to this
            if (Next != nullptr)
            {
                Next->setPrevious(this);
            }
        }
        void setPrevious(Node *previous)
        {
            Previous = previous;
            // set the index of the previous node
            Previous->setIndex(Index - 1);
            // if the previous pointer is not null, set the next pointer of the previous instance to this
            if (Previous != nullptr)
            {
                Previous->setNext(this);
            }
        }
        void setIndex(const int index) { Index = index; }
        void setData(std::string data) { Data = data; }
        // getters
        Node *getNext() const { return Next; }
        Node *getPrevious() const { return Previous; }
        const int getIndex() const { return Index; }
        std::string getData() const { return Data; }
        // constructor
        explicit Node(Node *previous, std::string Data, Node *next)
        {
            setIndex(0);
            setPrevious(previous);
            setData(std::move(Data));
            setNext(next);
            // set the index of the current node
        }
        // destructor
        ~Node()
        {
            // delete the next & previous node
            delete Next;
            delete Previous;
            std::cout << "deleting node" << std::endl;
        }
    }; // TODO TEST OUT NODE CLASS FIRST
}
// end of containers.h
