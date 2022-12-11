#include <iostream>

namespace Solution
{
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
                //delete Head;
                this->Size = 0;
                std::cout << "Destroyed Queue object at " << this << std::endl;
            }
        };
    }

    namespace Queue
    {
        template <class A>
        class Queue // TODO FINISH
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

    namespace List
    {

    }
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

int main()
{

    using namespace Solution;
    /*
    Stack::Stack<int> stack_nums;
    for (int i = 0; i < 10; i++)
    {
        stack_nums.push(fibsequence(i));
    }
    // std::cout << "destroying " << stack_nums.pop() << std::endl; // dequeues 55
    */

    Queue::Queue<int> nums_queue;
    Stack::Stack<int> nums_stack;
    int size = 10;
    for (int i = 0; i < size; i++)
    {
        int input_number = i * i;
        nums_queue.enqueue(input_number);
        nums_stack.push(input_number);
    }
    for (int i = 0; i < size; i++)
    {
        std::cout << "Dequeueing: " << nums_queue.dequeue() << std::endl
                  << "Popping from the Stack " << nums_stack.pop() << std::endl;
    }

    std::cout << "terminating process" << std::endl;
    return 0;
}