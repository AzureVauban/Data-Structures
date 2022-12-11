#ifndef STACK_H_
#define STACK_H_

#include <iostream>

namespace Stack
{
    template <class A>
    class Stack
    {
        template <class B>
        class Node
        {
            int index;
            Node *next;
            Node *prev;
            B data;

        public:
            // setters

            void setIndex(const int index) { this->index = index; }
            void setNext(Node *next) { this->next = next; }
            void setPrev(Node *prev) { this->prev = prev; }
            void setData(B data) { this->data = data; }

            // getters

            const int &getIndex() { return this->index; }
            Node *getNext() { return this->next; }
            Node *getPrev() { return this->prev; }
            const B &getData() { return this->data; }

            // functions

            void printinfo()
            {
                std::cout << "Next*: " << this->getNext() << std::endl
                          << "Data: " << this->getData() << std::endl
                          << "Prev*: " << this->getPrev() << std::endl
                          << "Index: " << this->getIndex() << std::endl;
            }

            explicit Node(Node *prev, B Data, Node *next)
            {
                setIndex(0);
                setPrev(prev);
                setData(Data);
                setNext(next);
            }
        };

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