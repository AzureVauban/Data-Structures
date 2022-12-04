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
            void setIndex(int Index) { this->Index = Index; }
            void setNext(Node *Next) { this->Next = Next; }
            void setPrevious(Node *Previous) { this->Previous = Previous; }
        };
        Node *head;
    };
}
// end of containers.h
