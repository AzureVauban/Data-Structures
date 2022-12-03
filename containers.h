#pragma once
#include <iostream>

class Node
{
    // Base for Stack, Queue, and Linked List
    Node *Next;
    Node *Prev;
    int Index;
    std::string Data;

public:
    // setters
    void setNext(Node *next) { this->Next = next; }
    void setPrev(Node *prev) { this->Prev = prev; }
    void setIndex(const int index) { this->Index = index; }
    void setData(std::string Data) { this->Data = std::move(Data); }
    // getters
    Node *getNext() const { return this->Next; }
    Node *getPrev() const { return this->Prev; }
    int getIndex() const { return this->Index; }
    std::string getData() const { return this->Data; }
    // constructor
    explicit Node(Node *prev = nullptr, std::string Data = "0x0", Node *next = nullptr)
    {
        this->setPrev(prev);
        this->setData(std::move(Data));
        this->setNext(next);
        if (this->getPrev())
        {
            // if there is a Prev pointer
            this->setIndex(this->getPrev()->getIndex() + 1);
        }
        else if (this->getNext())
        {
            // if there is a Next pointer
            this->setIndex(this->getNext()->getIndex() - 1);
        }
        else
        {
            // if the Next and the Prev is null, set the index to 0
            this->setIndex(0);
        }
    }
    // destructor
    ~Node()
    {
        // std::cout << "Destroyed Node with index " << this->getIndex() << " located at " << this << std::endl;*/
        if (this->getNext())
        {
            this->setNext(nullptr);
            delete this->getNext();
        }
        if (this->getPrev())
        {
            this->setPrev(nullptr);
            delete this->getPrev();
        }
    }
};

/*
namespace Stack
{ //?NEEDS TO BE REDONE
    class Stack
    {
        // uses the "first in , last out" approach
        Node *Top; // prev should always be Null
        int Size;

    public:
        // setters
        void setTop(Node *Top) { this->Top = Top; }
        void setSize()
        {
            int new_size = 0;
            Node *current = this->getTop();
            // traverse to the end of the structure until current is null
            while (current)
            {
                new_size += 1;
                current = current->getNext();
            }
            // set the new size value
            this->Size = new_size;
        }
        // getters
        Node *getTop() const { return this->Top; }
        int getSize() const { return this->Size; }
        Node *getBottom()
        {
            if (this->isEmpty())
            { // if empty, return the top of the stack
                return getTop();
            }
            // traverse to the end of the Stack
            Node *current = this->getTop();
            while (current->getNext())
            {
                current = current->getNext();
            }
            return current;
        }
        // functions
        bool isEmpty() const { return Top == nullptr; }
        void push(const std::string new_data)
        {
            if (this->isEmpty())
            {
                this->setTop(new Node(nullptr, std::move(new_data), nullptr));
            }
            else
            {
                // get the current endpoint Node
                Node *endpoint = this->getBottom();
                // create a new Node with the endpoint as its prev ptr
                //? New Node links back to the endpoint within the "new" constructor
                endpoint->setNext(new Node(endpoint, std::move(new_data), nullptr));
            }
            // set the new Size
            this->setSize();
            std::cout << "Added " << new_data << " to the Stack located at " << this << "..." << std::endl;
        }
        void pop()
        {
            if (this->isEmpty())
            {
                std::string warning = "\x1B[31m";
                warning += "STACK IS EMPTY";
                warning += "\x1B[0m";
                std::cout << warning << std::endl;
                // this->Size = 0;
                // this->setSize();
            }
            else if (this->getSize() == 1)
            {
                this->setTop(nullptr);
                // this->Size = 0;
                this->setSize();
            }
            else if (this->getBottom() && this->getTop())
            {
                // traverse to the end
                Node *endpoint = this->getBottom();
                // set the next ptr of the prev node to null
                endpoint->getPrev()->setNext(nullptr);
                // set the prev ptr of endpoint to null
                endpoint->setPrev(nullptr);
                // delete endpoint
                delete endpoint;
                // std::cout << "Poppped Element" << std::endl;
                if (this->getTop())
                {
                    this->setSize();
                }
            }
        }
        // constructor
        explicit Stack()
        {
            setTop(nullptr);
            // temporary
            this->setSize();
            std::cout << "Creating Stack instance located at " << this << "..." << std::endl;
        }
        // destructor
        ~Stack()
        {
            while (true)
            {
                Node *endpoint = this->getBottom();
                if (endpoint->getIndex() == 0)
                {
                    break;
                }
                else
                {
                    this->pop();
                }
            }
            delete getTop();
            this->Size = 0;
            std::cout << "Destroying Stack instance located at " << this << "..." << std::endl;
        }
    };
}
*/
namespace Queue
{
    // use for "first in, first out" approach to handling data
    class Queue // TODO ADD INTIALIZATION (inital size, inital data)
    {

        Node *Front; // next should always be Null
        int Size;

    private:
        // setters
        void setFront(Node *Front) { this->Front = Front; }
        void setSize()
        {
            /// set the size of the Queue

            int new_size = 0;
            Node *current = getFront();
            while (current)
            {
                // traverse to the back of the Queue
                new_size += 1;
                current = current->getPrev();
            }
            this->Size = new_size;
        }
        // getters
        Node *getFront() const
        {
            return this->Front;
        }

    public:
        // return the current size of the Queue
        int getSize() const
        {
            return this->Size;
        }
        // functions
    private:
        Node *getBack() const
        {
            Node *current = this->getFront();

            while (current->getPrev())
            {
                current = current->getPrev();
            }
            return current;
        }
        void checkIndex()
        {
            // use this function to set the Index to the correct int when enqueuing or dequeue
            Node *current = this->getFront();
            int new_index = 0;
            while (current)
            {
                current->setIndex(new_index);
                current = current->getPrev();
                new_index += 1;
            }
        }

    public:
        std::string getData() const { return this->Front->getData(); }
        bool isEmpty() const { return this->getFront() == nullptr; }
        void enqueue(const std::string Data)
        {
            // PREV,DATA,NEXT
            if (this->isEmpty())
            {
                Node *front = this->getFront();
                this->setFront(new Node(nullptr, std::move(Data), nullptr));
                /*
                OLD STATE: FRONT = 0
                NEW STATE: FRONT = (NO PREV, 0, NO NEXT)
                */
            }
            else
            {
                /*
                OLD STATE: FRONT = (NO PREV, 0, NO NEXT)
                NEW STATE: FRONT = (NO PREV, 0, NEXT)
                           NEXT = (FRONT, 1, NO NEXT)
                */
                // get the end pointer
                Node *endpoint = this->getBack();
                // make a new Node with the endpoint as the next address
                // make the new Node the previous address of the endpoint
                endpoint->setPrev(new Node(nullptr, std::move(Data), endpoint));
            }
            this->checkIndex();
            //  set size
            this->setSize();
        }
        void dequeue()
        {
            /*
            old_front, new_front
            the new_front is the previous pointer of the old_front
            old_front's previous becomes nullptr
            new_front's next becomes nullptr
            deallocate the old_front pointer
            set front to the new front pointer
            */
            if (this->isEmpty())
            {
                std::cout << "\x1B[31mTHERE ARE NO OBJECTS TO DEQUEUE\x1B[0m" << std::endl;
            }
            else if (this->getFront() == this->getBack())
            {
                this->setFront(nullptr);
            }
            else
            {
                Node *old_front = this->getFront();
                Node *new_front = old_front->getPrev();
                old_front->setPrev(nullptr);
                // old_front
                new_front->setNext(nullptr);
                delete old_front;
                this->setFront(new_front);
            }
            this->checkIndex();
            //  set size
            this->setSize();
        }
        void empty()
        {
            while (this->getFront())
            {
                this->dequeue();
            }
            delete this->getFront();
        }
        // constructor
        Queue()
        {
            this->setFront(nullptr);
            this->setSize();
        }
        ~Queue()
        {
            empty();
        }
    };
}
namespace List
{
    // Linked List class
    class List
    {
        // custom class Node class for Linked List
        class Node
        {
            int Index;
            Node *Next;
            std::string Data;
            Node *Previous;
            // setters
            void setIndex(int Index) { this->Index = Index; }

        public:
            void setNext(Node *Next) { this->Next = Next; }
            void setPrevious(Node *Previous) { this->Previous = Previous; }

        private:
            void setData(std::string Data) { this->Data = std::move(Data); }

        public: // getters
            int getIndex() const { return this->Index; }
            Node *getNext() const { return this->Next; }
            Node *getPrevious() const { return this->Previous; }
            std::string getData() const { return this->Data; }

        private: // functions
            void initalize_Index()
            {
                int indicies[2] = {0, 0};
                if (this->getPrevious())
                {
                    indicies[0] = Previous->getIndex() - 1;
                }
                if (this->getNext())
                {
                    indicies[1] = Next->getIndex() + 1;
                }
                // set index to the greatest number
                if (indicies[1] > indicies[0])
                {
                    this->setIndex(indicies[1]);
                }
                else
                {
                    this->setIndex(indicies[0]);
                }
            }

        public: // constructor
            Node(Node *Previous, std::string Data, Node *Next)
            {
                this->setNext(Next);
                // if the next pointer is not null
                if (Next)
                {
                    // go to the next pointer and set the previous to this
                    this->getNext()->setPrevious(this);
                }
                this->setPrevious(Previous);
                // if the previous pointer is not null
                if (Previous)
                {
                    // go to the previous pointer and set the next to this
                    this->getPrevious()->setNext(this);
                }
                this->setData(std::move(Data));
                // set the Index of the Node
                this->initalize_Index();
            }
        };

        // private class members

        List::Node *head;
        int Size;
        // setters

        void setHead(List::Node *Head) { this->head = Head; }

        // getters

        List::Node *getHead() const { return this->head; }
        List::Node *getEnd() const
        {
            List::Node *current = this->getHead();
            // traverse to the end of the list
            while (current->getNext())
            {
                current = current->getNext();
            }
            return current;
        }

    public: // functions
        // returns true if the head pointer is null
        bool isEmpty() const { return this->head == nullptr; }
        // append to the end of the linked list
        void append(std::string Data)
        {
            // PREVIOUS, DATA, NEXT
            if (this->isEmpty())
            {
                this->setHead(new List::Node(nullptr, std::move(Data), nullptr));
            }
            else
            {
                // List::Node *endpoint = this->getEnd();
                //  make a new node with the endpoint as the previous pointer
                List::Node *new_Node = new List::Node(this->getEnd(), std::move(Data), nullptr);
                // endpoint->setNext(new_Node);
            }
            // peak for debug purposes only
            this->getEnd()->getData();
            // update the size accordingly
            setSize();
        }
        // destroy a node at the end of the list
        void pop()
        {
            if (this->isEmpty())
            {
                std::cout << "\x1B[31mTHE LINKED LIST IS EMPTY\x1B[0m" << std::endl;
            }
            else
            {
            }
            // update the size accordingly
            setSize();
        }

    private:
        void setSize()
        {
            int new_size = 0;
            if (!isEmpty())
            {
                // traverse to the end while incrementing
                List::Node *current = this->getHead();
                while (current->getNext())
                {
                    current = current->getNext();
                    new_size += 1;
                }
            }
            this->Size = new_size+1;
        }

    public:
        // constructor

        explicit List()
        {
            this->setHead(nullptr);
            this->setSize();
        }

        // destructor
        ~List() { delete this->getHead(); }
    };
}

// end of containers.h