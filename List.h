#ifndef LINK_LIST_H_
#define LINK_LIST_H_

#include "Nodebase.h"

namespace List
{ // todo finish this
    /*
    operations:
    - peak
    - isempty
    - append
    - insert
    - pop
    - remove
    - reverse
    */
    template <class H>
    class List
    {
        Node<H> *Head;
        int Size;
        // functions
    public:
        int getSize() { return this->Size; }
        const bool isEmpty() { return this->Size == 0; }

    private:
        Node<H> *getHead() { return this->Head; }
        Node<H> *getEnd()
        {
            Node<H> *current = this->getHead();
            if (!isEmpty())
            {
                while (current->getNext())
                {
                    current = current->getNext();
                }
            }
            return current;
        }
        const bool isnotwithinRange(const int index) { return index < 0 || index >= this->getSize(); }
        void setIndex()
        {
            if (!isEmpty())
            {
                Node<H> *current = this->getHead();
                int new_index = 0;
                while (current->getNext())
                {
                    current->setIndex(new_index);
                    current = current->getNext();
                }
            }
        }

    public:
        void append(H Data)
        {
            if (this->isEmpty())
            {
                // overwrite the head pointer
                this->Head = new Node<H>(nullptr, Data, nullptr);
            }
            else
            { // create a new head
                Node<H> *new_head = new Node<H>(nullptr, Data, this->Head);
                this->Head->setPrev(nullptr);
                this->Head = new_head;
                // set the index values of the new Node
            }
            this->setIndex();
            this->Size += 1;
        }
        void insert(H Data, const int Index)
        { // TODO FINISH
            if (this->isnotwithinRange(Index))
            {
                std::cout << "IS NOT WITHIN RANGE" << std::endl;
            }
            else if (Index == this->getSize() - 1)
            {
                this->append(Data);
            }
            else if (!this->isnotwithinRange(Index) && this->isEmpty())
            {
                this->append(Data);
            }
            else
            {
                Node<H> *current = this->getHead();
                while (current->getIndex() != Index)
                {
                    current = current->getNext();
                }
                // insert new node below node with the selected index
                Node<H> *previous_of_new = current->getPrev();
                Node<H> *new_node = new Node<H>(previous_of_new, Data, current);
                previous_of_new->setNext(new_node);
                current->setPrev(new_node);
                // set the index
                this->setIndex();
                this->Size += 1;
            }
        }
        void remove(const int Index)
        {
            // TODO FINISH
        }
        void reverse()
        {
            // TODO FINISH
        }
        H pop()
        {
            H old_head_value = this->getHead()->getData();
            if (!this->isEmpty())
            {
                Node<H> *old_head = this->getHead();
                Node<H> *new_head = old_head->getNext();
                this->Head = new_head;
                old_head->setNext(nullptr);
            }
            this->Size -= 1;
            return old_head_value;
        }

        H peak()
        {
            return this->getHead()->getData();
        }
        explicit List()
        {
            this->Head = nullptr;
            this->Size = 0;
        }
    };
}
#endif // !LINK_LIST_H_