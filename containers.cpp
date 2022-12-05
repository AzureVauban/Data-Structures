#include "containers.h"
// TODO: FIX FUNCTION DEFINITIONS
void Queue::Node::setNext(Node *next, const bool first_step = true)
{
    this->next = next;
    // if the next pointer is not null
    if (this->next && first_step && this)
    {
        // set the previous pointer of next to this
        this->next->setPrevious(this), false;
        // set the index of this node based on the index of the previous node
        //! this->setIndex(this->getNext()->getIndex() - 1);
    }
}
void Queue::Node::setPrevious(Node *previous, const bool first_step = true)
{
    this->previous = previous;
    // if the previous is not null
    if (this->previous && first_step)
    {
        // set the next pointer of previous to this
        this->previous->setNext(this, false);
        // set the index of this node based on the index of the next node
        //! this->setIndex(this->getPrevious()->getIndex() + 1);
    }
}
void Queue::Node::setIndex(const int index) { this->index = index; }
Queue::Node *Queue::Node::getNext() { return this->next; }
Queue::Node *Queue::Node::getPrevious() { return this->previous; }
const int Queue::Node::getIndex() { return this->index; }
const std::string &Queue::Node::getData() { return this->Data; }

/*
Node* Queue::Node::getNext() const { return this->next; }
Queue::Node *Queue::Node::getPrevious() const { return this->previous; }
const int Queue::Node::getIndex() const { return this->index; }
const std::string &Queue::Node::getData() const { return this->Data; }
*/
