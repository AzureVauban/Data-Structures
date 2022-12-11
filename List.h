#ifndef LINK_LIST_H_
#define LINK_LIST_H_

#include "Nodebase.h"

namespace List
{
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
        Node<T> Head;
        int Size;
        public:
        explicit Queue()
        {
            this->Head = nullptr;
            this->Size = 0;
        }
    };
}
#endif // !LINK_LIST_H_