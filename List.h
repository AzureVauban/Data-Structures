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
        Node<T>* Head;
        int Size;
//functions
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
        explicit List()
        {
            this->Head = nullptr;
            this->Size = 0;
        }
    };
}
#endif // !LINK_LIST_H_