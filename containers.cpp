//
// Created by halor on 12/5/2022.
//

/*
- Queue "Uses the FIFO (first-in, first-out) ordering principle"
- Stack "Uses the LIFO (last-in, first-out) ordering principle"
- Linked List "A data structure that contains a group of nodes which together represent a sequence"
*/
#include "containers.h"
// Node(/*PREVIOUS*/,/*DATA*/,/*DATA*/)

// Node class setters
int Queue::Node::instances = 0;
void Queue::Node::setIndex(int new_index) { this->index = new_index; }
void Queue::Node::setNext(Node *new_next) { this->next = new_next; }
void Queue::Node::setPrevious(Node *new_previous) { this->previous = new_previous; }
void Queue::Node::setData(std::string new_data) { this->data = new_data; }
// Node class getters
int Queue::Node::getIndex() { return this->index; }
Queue::Node *Queue::Node::getNext() { return this->next; }
Queue::Node *Queue::Node::getPrevious() { return this->previous; }
std::string Queue::Node::getData() { return this->data; }
// Node class functions
void Queue::Node::test_echo(const std::string &echo) { std::cout << echo << std::endl; }
// Node class constructor
Queue::Node::Node(Queue::Node *Next, std::string Data, Queue::Node *Previous)
{
    instances += 1;
    this->next = Next;
    this->previous = Previous;
    this->index = 0;
    this->data = std::move(Data);
}
// Node class destructor
Queue::Node::~Node()
{
    this->index = -1;
    instances -= 1;
    std::cout << "destroyed node" << std::endl;
}
// Queue class setters
int Queue::instances = 0;
void Queue::setFront(Queue::Node *front_node) { this->front = front_node; }
void Queue::setSize()
{
    int new_size = 0;
    Node *current = this->getFront();
    while (current)
    {
        new_size += 1;
        current = current->getNext();
    }
    this->size = 0;
}
// Queue class getters
Queue::Node *Queue::getFront() { return this->front; }
Queue::Node *Queue::getEnd()
{
    Node *current = this->getFront();

    while (current->getNext() && isEmpty())
    {
        current = current->getNext();
    }
    return current;
}
int Queue::getSize() { return this->size; }
// Queue class functions
bool Queue::isEmpty() { return this->size == 0; }
Queue::Node *Queue::enqueue(std::string data)
{
    Node *new_node = new Node(nullptr, std::move(data), this->getEnd());
    if (this->isEmpty())
    {
        this->setFront(new_node);
    }
    else
    {
        this->getEnd()->setNext(new_node);
    }
    this->setSize();
    return new_node;
}
// Queue class constructor
Queue::Queue()
{
    this->setFront(nullptr);
    this->setSize();
    Queue::instances += 1;
}
// Queue class destructor
Queue::~Queue()
{
    //   this->front = nullptr;
    Queue::instances -= 1;
    this->size = -1;
    std::cout << "destroyed queue" << std::endl;
}