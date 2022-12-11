#ifndef QUEUE_H_
#define QUEUE_H_

// #include "Nodebase.h"

namespace Queue
{
    //? use the first in, first out paradigm
    //* insert below head
    template <class Q>
    class Queue // TODO FINISH
    {
        template <class N>
        class Node
        {
            int index;
            Node *next;
            Node *prev;
            N data;

        public:
            // setters

            void setIndex(const int index) { this->index = index; }
            void setNext(Node *next) { this->next = next; }
            void setPrev(Node *prev) { this->prev = prev; }
            void setData(N data) { this->data = data; }

            // getters

            const int &getIndex() { return this->index; }
            Node *getNext() { return this->next; }
            Node *getPrev() { return this->prev; }
            const N &getData() { return this->data; }

            // functions

            void printinfo()
            {
                std::cout << "Next*: " << this->getNext() << std::endl
                          << "Data: " << this->getData() << std::endl
                          << "Prev*: " << this->getPrev() << std::endl
                          << "Index: " << this->getIndex() << std::endl;
            }

            explicit Node(Node *prev, N Data, Node *next)
            {
                setIndex(0);
                setPrev(prev);
                setData(Data);
                setNext(next);
            }
        };
        Node<Q> *Head;
        int Size;

        // functions
        int getSize() { return this->Size; }
        const bool isEmpty() { return this->Size == 0; }

    private:
        Node<Q> *getHead() { return this->Head; }
        Node<Q> *getEnd()
        {
            Node<Q> *current = this->getHead();
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
            Node<Q> *current = this->getHead();
            while (current->getNext())
            {
                current->setIndex(new_index);
                current = current->getNext();
                new_index += 1;
            }
        }

    public:
        void enqueue(Q Data)
        {
            if (this->isEmpty())
            {
                // overwrite the head pointer
                this->Head = new Node<Q>(nullptr, Data, nullptr);
            }
            else
            {
                // append the node to the end
                Node<Q> *new_endpoint = new Node<Q>(nullptr, Data, nullptr);
                this->getEnd()->setNext(new_endpoint);
                // set the index values of the new Node
                this->setIndex();
            }
            this->Size += 1;
        }
        Q peak()
        {
            return this->getHead()->getData();
        }
        Q dequeue()
        {
            Q old_head_value = this->getHead()->getData();
            if (!this->isEmpty())
            {
                Node<Q> *old_head = this->getHead();
                Node<Q> *new_head = old_head->getNext();
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
            std::cout << "Destroyed Queue object at " << this << std::endl;
        }
    };
}
#endif // !QUEUE_H_