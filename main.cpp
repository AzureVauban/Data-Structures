#include <iostream>
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
    template <class L>
    class List
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
        Node<L> *Head;
        int Size;
        // functions
    public:
        int getSize() { return this->Size; }
        const bool isEmpty() { return this->Size == 0; }

    private:
        Node<L> *getHead() { return this->Head; }
        Node<L> *getEnd()
        {
            Node<L> *current = this->getHead();
            if (!isEmpty())
            {
                while (current->getNext())
                {
                    current = current->getNext();
                }
            }
            return current;
        }
        const bool isnotwithinRange(const int index) { return index < 0 || index >= this->getSize(); }
        void setIndex()
        {
            if (!isEmpty())
            {
                Node<L> *current = this->getHead();
                int new_index = 0;
                while (current->getNext())
                {
                    current->setIndex(new_index);
                    current = current->getNext();
                }
            }
        }

    public:
        void append(L Data)
        {
            if (this->isEmpty())
            {
                // overwrite the head pointer
                this->Head = new Node<L>(nullptr, Data, nullptr);
            }
            else
            { // create a new head
                Node<L> *new_head = new Node<L>(nullptr, Data, this->Head);
                this->Head->setPrev(nullptr);
                this->Head = new_head;
                // set the index values of the new Node
            }
            this->setIndex();
            this->Size += 1;
        }
        void insert(L Data, const int Index)
        { // TODO FINISH
            if (this->isnotwithinRange(Index))
            {
                std::cout << "IS NOT WITHIN RANGE" << std::endl;
            }
            else if (Index == this->getSize() - 1)
            {
                this->append(Data);
            }
            else if (!this->isnotwithinRange(Index) && this->isEmpty())
            {
                this->append(Data);
            }
            else
            {
                Node<L> *current = this->getHead();
                while (current->getIndex() != Index)
                {
                    current = current->getNext();
                }
                // insert new node below node with the selected index
                Node<L> *previous_of_new = current->getPrev();
                Node<L> *new_node = new Node<L>(previous_of_new, Data, current);
                previous_of_new->setNext(new_node);
                current->setPrev(new_node);
                // set the index
                this->setIndex();
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
        L pop()
        {
            L old_head_value = this->getHead()->getData();
            if (!this->isEmpty())
            {
                Node<L> *old_head = this->getHead();
                Node<L> *new_head = old_head->getNext();
                this->Head = new_head;
                old_head->setNext(nullptr);
            }
            this->Size -= 1;
            return old_head_value;
        }

        L peak()
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
namespace Stack
{

    //? use the first in, last out paradigm

    //? how are elements added to the Stack?
    //* insert at above head
    template <class S>
    class Stack
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
        Node<S> *Head;
        int Size;

        Node<S> *getHead() { return this->Head; }

    public:
        const int getSize() { return this->Size; }

    private:
        Node<S> *getEnd()
        {
            Node<S> *current = this->getHead();
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

        void push(S Data)
        {
            if (this->isEmpty())
            {
                // overwrite the head pointer
                this->Head = new Node<S>(nullptr, Data, nullptr);
            }
            else
            {
                // create a new head
                Node<S> *new_head = new Node<S>(nullptr, Data, this->Head);
                this->Head->setPrev(nullptr);
                this->Head = new_head;
                // set the index values of the new Node
                // this->setIndex();
            }
            this->Size += 1;
        }
        S peak() { return this->getHead()->getData(); }

        S pop()
        {
            S old_head_value = this->getHead()->getData();
            if (!this->isEmpty())
            {
                Node<S> *old_head = this->getHead();
                Node<S> *new_head = old_head->getNext();
                this->Head = new_head;
                old_head->setNext(nullptr);
            }
            this->Size -= 1;
            return old_head_value;
        }

    public:
        explicit Stack()
        {
            this->Head = nullptr;
            this->Size = 0;
        }
        ~Stack()
        {
            while (this->getSize() != 0)
            {
                this->pop();
            }
            delete this->Head;
            // delete Head;
            this->Size = 0;
            std::cout << "Destroyed Stack object at " << this << std::endl;
        }
    };
}

long long int fibsequence(const long long int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return fibsequence(n - 1) + fibsequence(n - 2);
    }
}

void Queue_demo(Queue::Queue<long long int> &nums)
{
    // first in, first out
    int size = 11;
    for (int i = 0; i < size; i++)
    {
        nums.enqueue(fibsequence(i));
    }
    for (int i = 0; i < size - 1; i++)
    {
        std::cout << "Dequeueing: " << nums.dequeue() << std::endl;
    }
}

void Stack_demo(Stack::Stack<long long int> &nums)
{
    // last in, first out
    int size = 11;
    for (int i = 0; i < size; i++)
    {
        nums.push(fibsequence(i));
    }
    for (int i = 0; i < size - 1; i++)
    {
        std::cout << "Popping from the stack: " << nums.pop() << std::endl;
    }
}
void comparison_demo(Queue::Queue<long long int> &Queue, Stack::Stack<long long int> &Stack, List::List<long long int> &List)
{
    for (int i = 1; i <= 10; i++)
    {
        int term = fibsequence(i + 1);
        Queue.enqueue(term);
        Stack.push(term);
        if (i % 2 == 0)
        {
            List.append(term);
        }
        else
        {
            List.append(term * -2);
        }
    }
    std::cout << "Peaking Queue: " << Queue.peak() << std::endl
              << "Peaking Stack: " << Stack.peak() << std::endl
              << "Peaking List: " << List.peak() << std::endl;
    for (int i = 0; i < 9; i++)
    {
        if (i < 4)
        {
            std::cout << "Dequeuing (From Queue): " << Queue.dequeue() << "  | "
                      << "Popping (From Stack): " << Stack.pop() << std::endl;
        }
        else
        {
            std::cout << "Dequeuing (From Queue): " << Queue.dequeue() << " | "
                      << "Popping (From Stack): " << Stack.pop() << std::endl;
        }
    }
    std::cout << "Peaking Queue: " << Queue.peak() << std::endl
              << "Peaking Stack: " << Stack.peak() << std::endl
              << "Peaking List: " << List.peak() << std::endl;
}
int main()
{
    Queue::Queue<long long int> nums_queue;
    Stack::Stack<long long int> nums_stack;
    List::List<long long int> nums_list;
    // nums_list.
    // comparison_demo(nums_queue, nums_stack, nums_list);
    for (int i = 0; i < 10; i++)
    {
        nums_list.append(i);
    }
    std::cout << nums_list.peak() << std::endl;
    for (int i = -1; i < nums_list.getSize() + 1; i++)
    {
        nums_list.insert(i, i);
    }

    std::cout << "terminating process" << std::endl;
    return 0;
}