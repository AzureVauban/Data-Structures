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
                this->Size += 1;
                // overwrite the head pointer
                this->Head = new Node<T>(nullptr, Data, nullptr);
            } else {

            }

            // set the next index
            //this->getEnd()->setIndex(this->getSize() - 1);
        }

        T peak() { return this->getHead()->getData(); }

        T pop()
        { /* ADD NEW CODE HERE*/
    
        }

    public:
        explicit Stack()
        {
            this->Head = nullptr;
            this->Size = 0;
        }
        ~Stack()
        {
            while (this->Head)
            {
                delete this->getEnd();
            }
            // delete Head;
            this->Size = 0;
            std::cout << "Destroyed Queue object at " << this << std::endl;
        }
    };
}

#endif // !STACK_H_