#ifndef QUEUE_H_
#define QUEUE_H_

#include "Nodebase.h"

namespace Queue
{
    //? use the first in, first out paradigm
    //* insert below head
    template <class T>
    class Queue // TODO FINISH
    {

        Node<T> *Head;
        int Size;

        // functions
        int getSize() { return this->Size; }
        const bool isEmpty() { return this->Size == 0; }

    private:
        Node<T> *getHead() { return this->Head; }
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
        void setIndex()
        {
            int new_index = 0;
            Node<T> *current = this->getHead();
            while (current->getNext())
            {
                current->setIndex(new_index);
                current = current->getNext();
                new_index += 1;
            }
        }

    public:
        void enqueue(T Data)
        {
            if (this->isEmpty())
            {
                // overwrite the head pointer
                this->Head = new Node<T>(nullptr, Data, nullptr);
            }
            else
            {
                // append the node to the end
                Node<T> *new_endpoint = new Node<T>(nullptr, Data, nullptr);
                this->getEnd()->setNext(new_endpoint);
                // set the index values of the new Node
                this->setIndex();
            }
            this->Size += 1;
        }
        T peak()
        {
            return this->getHead()->getData();
        }
        T dequeue()
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