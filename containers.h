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
        void setNext(Node *next) { Next = next; }
        void setPrevious(Node *previous) { Previous = previous; }
        void setIndex(int index) { Index = index; }
        void setData(std::string data) { Data = data; }
        // getters
        Node *getNext() const { return Next; }
        Node *getPrevious() const { return Previous; }
        const int getIndex() const { return Index; }
        std::string getData() const { return Data; }
    }; // TODO TEST OUT NODE CLASS FIRST
}
// end of containers.h
