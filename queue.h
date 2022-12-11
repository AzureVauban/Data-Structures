#ifndef QUEUE_H_
#define QUEUE_H_

#include "Nodebase.h"

namespace Queue
{
    template <class A>
    class Queue // TODO FINISH
    {
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

        Node<A> *Head;
        int Size;

        // functions
        int getSize() { return this->Size; }
        const bool isEmpty() { return this->Size == 0; }

    private:
        Node<A> *getHead() { return this->Head; }
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
        void setIndex()
        {
            int new_index = 0;
            Node<A> *current = this->getHead();
            while (current->getNext())
            {
                current->setIndex(new_index);
                current = current->getNext();
                new_index += 1;
            }
        }

    public:
        void enqueue(A Data)
        {
            if (this->isEmpty())
            {
                // overwrite the head pointer
                this->Head = new Node<A>(nullptr, Data, nullptr);
            }
            else
            {
                // create a new head
                Node<A> *new_head = new Node<A>(nullptr, Data, this->Head);
                this->Head->setPrev(nullptr);
                this->Head = new_head;
                // set the index values of the new Node
                this->setIndex();
            }
            this->Size += 1;
        }
        A peak()
        {
            return this->getHead()->getData();
        }
        A dequeue()
        {
            A old_head_value = this->getHead()->getData();
            if (!this->isEmpty())
            {
                Node<A> *old_head = this->getHead();
                Node<A> *new_head = old_head->getNext();
                this->Head = new_head;
                old_head->setNext(nullptr);
            }
            this->Size -= 1;
            return old_head_value;
        }
        // constructor
        explicit Queue()
        {
            this->Head = nullptr;
            this->Size = 0;
        }
        // destructor
        ~Queue()
        {
            while (this->getSize() != 0)
            {
                this->dequeue();
            }
            delete this->Head;
            // std::cout << "destroyed queue" << std::endl;
        }
    };
}
#endif // !QUEUE_H_