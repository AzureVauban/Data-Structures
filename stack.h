#ifndef STACK_H_
#define STACK_H_

#include "nodebase.h"

namespace Stack
{

    //? use the first in, last out paradigm

    //? how are elements added to the Stack?
    //* insert at above head
    template <class T>
    class Stack
    {
        Node<T> *Head;
        int Size;

        Node<T> *getHead() { return this->Head; }

    public:
        const int getSize() { return this->Size; }

    private:
        Node<T> *getEnd()
        {
            Node<T> *current = this->getHead();
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

        void push(T Data)
        {
            if (this->isEmpty())
            {
                // overwrite the head pointer
                this->Head = new Node<T>(nullptr, Data, nullptr);
            }
            else
            {
                // create a new head
                Node<T> *new_head = new Node<T>(nullptr, Data, this->Head);
                this->Head->setPrev(nullptr);
                this->Head = new_head;
                // set the index values of the new Node
                this->setIndex();
            }
            this->Size += 1;
        }
        T peak() { return this->getHead()->getData(); }

        T pop()
        {
            T old_head_value = this->getHead()->getData();
            if (!this->isEmpty())
            {
                Node<T> *old_head = this->getHead();
                Node<T> *new_head = old_head->getNext();
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
            std::cout << "Destroyed Queue object at " << this << std::endl;
        }
    };
}

#endif // !STACK_H_