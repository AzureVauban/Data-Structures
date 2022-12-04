#pragma once
#include <iostream>
/*
- Queue "Uses the FIFO (first-in, first-out) ordering principle"
- Stack "Uses the LIFO (last-in, first-out) ordering principle"
- Linked List "A data structure that contains a group of nodes which together represent a sequence"
*/
namespace List
{
    class List
    {
        class Node
        {
            int Index;
            Node *Next;
            Node *Previous;
//setters            
            void setIndex(int Index) { this->Index = Index; }
            void setNext(Node *Next) { this->Next = Next; }
            void setPrevious(Node *Previous) { this->Previous = Previous; }
//getters
            int getIndex() const { return this->Index; }
            Node *getNext() const { return this->Next; }
            Node *getPrevious() const { return this->Previous; }
            //const std::string &getData() const { return this->Data; }
//constructor
            explicit (Node* Next, Node* Previous) {
                
            }
        };
        Node *head;
    };
}
// end of containers.h
