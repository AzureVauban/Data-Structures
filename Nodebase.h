#ifndef NODEBASE_H_
#define NODEBASE_H_

#include <iostream>

template <class N>
class Node
{
    int index;
    Node *next;
    Node *prev;
    N data;

public:
    // setters

    void setIndex(const int index) { this->index = index; }
    void setNext(Node *next) { this->next = next; }
    void setPrev(Node *prev) { this->prev = prev; }
    void setData(N data) { this->data = data; }

    // getters

    const int &getIndex() { return this->index; }
    Node *getNext() { return this->next; }
    Node *getPrev() { return this->prev; }
    const N &getData() { return this->data; }

    // functions

    void printinfo()
    {
        std::cout << "Next*: " << this->getNext() << std::endl
                  << "Data: " << this->getData() << std::endl
                  << "Prev*: " << this->getPrev() << std::endl
                  << "Index: " << this->getIndex() << std::endl;
    }

    explicit Node(Node *prev, N Data, Node *next)
    {
        setIndex(0);
        setPrev(prev);
        setData(Data);
        setNext(next);
    }
};
#endif // !NODEBASE_H_