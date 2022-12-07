//
// Created by halor on 12/5/2022.
//

#ifndef MYCUSTOMSTRUCTURES_CONTAINERS_H_H
#define MYCUSTOMSTRUCTURES_CONTAINERS_H_H

#include <iostream>
class Queue
{
    class Node
    {
        int index;
        Node *next;
        Node *previous;
        std::string data;
        static int instances;

    public:
        // setters
        void setIndex(int new_index);
        void setNext(Node *new_next);
        void setPrevious(Node *new_previous);
        void setData(std::string new_data);
        // getters
        int getIndex();
        Node *getNext();
        Node *getPrevious();
        std::string getData();
        // functions
        void test_echo(const std::string &echo);
        Node *getEnd();
        // constructor
        explicit Node(Node *Next, std::string Data, Node *Previous);
        // destructor
        ~Node();
    };
    Node *front{}; //? what is the point of including curly brackets before the semicolon?
    int size{};
    static int instances;
    // setters
    void setFront(Node *front_node);
    void setSize();
    // getters
    Node *getFront();
    Node *getEnd();

public:
    int getSize();
    // functions
    bool isEmpty();
    Node *enqueue(std::string data);
    std::string dequeue();
    // constructor
    explicit Queue();
    // destructor
    ~Queue();
};
#endif // MYCUSTOMSTRUCTURES_CONTAINERS_H_H
