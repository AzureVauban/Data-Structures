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

public:
    explicit Node(Node *previous, std::string Data, Node *next)
    {
        this->next = nullptr;
        this->previous = nullptr;
    }
    ~Node()
    {
        for (auto &character : Data)
        {
            Data.pop_back();
        }
        delete next;
        delete previous;
        // set index to -1
        std::cout << "Destroyed Node located at " << this << std::endl;
    }
};
// end of containers.h
