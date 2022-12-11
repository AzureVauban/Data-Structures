#ifndef STACK_H_
#define STACK_H_

#include "nodebase.h"

namespace Stack
{
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
            this->Size += 1;
            if (this->isEmpty())
            {
                // overwrite the head pointer
                this->Head = new Node<T>(nullptr, Data, nullptr);
            }
            else
            {
                // Node<T> *new_node = new Node(PREV PTR, NEW DATA, NEXT PTR);
                // get the endpoint
                Node<T> *endpoint = this->getEnd();
                endpoint->setNext(new Node<T>(endpoint, Data, nullptr));
                // this->getEnd()->setIndex(this->getEnd()->getIndex() + 1);
            }
            // set the next index
            this->getEnd()->setIndex(this->getSize() - 1);
        }

        T peak() { return this->getHead()->getData(); }

        T pop()
        {
            Node<T> *endpoint = this->getEnd();
            T return_value = endpoint->getData();
            endpoint->getPrev()->setNext(nullptr);
            delete endpoint;
            this->Size -= 1;
            return return_value;
        }

    public:
        explicit Stack()
        {
            this->Head = nullptr;
            this->Size = 0;
        }
        ~Stack()
        {
            while (this->Size != 1)
            {
                this->pop();
            }
            // delete Head;
            this->Size = 0;
            std::cout << "Destroyed Queue object at " << this << std::endl;
        }
    };
}

#endif // !STACK_H_