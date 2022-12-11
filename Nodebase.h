#ifndef NODEBASE_H_
#define NODEBASE_H_

#include <iostream>

template <class T>
class Node
{
    int index;
    Node *next;
    Node *prev;
    T data;

public:
    // setters

    void setIndex(const int index) { this->index = index; }
    void setNext(Node *next) { this->next = next; }
    void setPrev(Node *prev) { this->prev = prev; }
    void setData(T data) { this->data = data; }

    // getters

    const int &getIndex() { return this->index; }
    Node *getNext() { return this->next; }
    Node *getPrev() { return this->prev; }
    const T &getData() { return this->data; }

    // functions

    void printinfo()
    {
        std::cout << "Next*: " << this->getNext() << std::endl
                  << "Data: " << this->getData() << std::endl
                  << "Prev*: " << this->getPrev() << std::endl
                  << "Index: " << this->getIndex() << std::endl;
    }

    explicit Node(Node *prev, T Data, Node *next)
    {
        setIndex(0);
        setPrev(prev);
        setData(Data);
        setNext(next);
    }
};
#endif // !NODEBASE_H_