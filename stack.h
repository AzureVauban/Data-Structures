#ifndef STACK_H_
#define STACK_H_

#include "Nodebase.h"

namespace Stack
{

    //? use the first in, last out paradigm

    //? how are elements added to the Stack?
    //* insert at above head
    template <class H>
    class Stack
    {
        Node<H> *Head;
        int Size;

        Node<H> *getHead() { return this->Head; }

    public:
        const int getSize() { return this->Size; }

    private:
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
        // functions
    public:
        const bool isEmpty() { return this->Head == nullptr; }

        void push(H Data)
        {
            if (this->isEmpty())
            {
                // overwrite the head pointer
                this->Head = new Node<H>(nullptr, Data, nullptr);
            }
            else
            {
                // create a new head
                Node<H> *new_head = new Node<H>(nullptr, Data, this->Head);
                this->Head->setPrev(nullptr);
                this->Head = new_head;
                // set the index values of the new Node
                // this->setIndex();
            }
            this->Size += 1;
        }
        H peak() { return this->getHead()->getData(); }

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

    public:
        explicit Stack()
        {
            this->Head = nullptr;
            this->Size = 0;
        }
        ~Stack()
        {
            while (this->getSize() != 0)
            {
                this->pop();
            }
            delete this->Head;
            // delete Head;
            this->Size = 0;
            std::cout << "Destroyed Stack object at " << this << std::endl;
        }
    };
}

#endif // !STACK_H_