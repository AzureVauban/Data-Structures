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
    template <class T>
    class List
    {
        Node<T> *Head;
        int Size;
        // functions
    public:
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

    public:
        const bool isnotwithinRange(const int index) { return index < 0 || index >= this->getSize(); }

    public:
        void append(T Data)
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
                // this->setIndex();
            }
            this->Size += 1;
        }
        void insert(T Data, const int Index)
        { // TODO FINISH
            if (this->isnotwithinRange(Index))
            {
                std::cout << "IS NOT WITHIN RANGE" << std::endl;
            } else if (Index == this->getSize()-1)
            {
                this->append(Data);
            } 
            else {
                Node<T>* current = this->getHead();
                while (current->getIndex() != Index) {
                    current = current->getNext();
                }
                //insert new node below
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

        T peak()
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