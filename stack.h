#ifndef STACK_H_
#define STACK_H_

#include "nodebase.h"

namespace Stack
{
    template <class A>
    class Stack
    {
        Node<A> *Head;
        int Size;

        Node<A> *getHead() { return this->Head; }

    public:
        const int getSize() { return this->Size; }

    private:
        Node<A> *getEnd()
        {
            Node<A> *current = this->getHead();
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

        void push(A Data)
        {
            this->Size += 1;
            if (this->isEmpty())
            {
                // overwrite the head pointer
                this->Head = new Node<A>(nullptr, Data, nullptr);
            }
            else
            {
                // Node<T> *new_node = new Node(PREV PTR, NEW DATA, NEXT PTR);
                // get the endpoint
                Node<A> *endpoint = this->getEnd();
                endpoint->setNext(new Node<A>(endpoint, Data, nullptr));
                // this->getEnd()->setIndex(this->getEnd()->getIndex() + 1);
            }
            // set the next index
            this->getEnd()->setIndex(this->getSize() - 1);
        }

        A peak() { return this->getHead()->getData(); }

        A pop()
        {
            Node<A> *endpoint = this->getEnd();
            A return_value = endpoint->getData();
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