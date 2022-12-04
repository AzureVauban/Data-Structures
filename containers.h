#pragma once
#include <iostream>
/*
- Queue "Uses the FIFO (first-in, first-out) ordering principle"
- Stack "Uses the LIFO (last-in, first-out) ordering principle"
- Linked List "A data structure that contains a group of nodes which together represent a sequence"
*/
namespace List
{
    class List
    {
        class Node
        {
            int Index;
            Node *Next;
            Node *Previous;
//setters            
            //void setIndex(int Index) { this->Index = Index; }
            void setNext(Node *Next) { this->Next = Next; }
            void setPrevious(Node *Previous) { this->Previous = Previous; }
//getters
            const int &getIndex() const { return this->Index; }
        public:
            Node *getNext() const { return this->Next; }
            private:
            Node *getPrevious() const { return this->Previous; }
            //const std::string &getData() const { return this->Data; }
//constructor
            explicit Node(Node* Previous, Node* Next){
                this->setPrevious(Previous);
                this->setNext(Next);
            }
        };
// end of Node definition
        Node* head;
        int size;
//setters
    void setHead(Node* head) { this->head = head; }
    void setSize(){
        if (!this->getHead()){
            this->size = 0;
        } else if (this->getHead() == this->getEnd() && this->getHead())
        {
            this->size = 1;
        } else {
            Node* current = this->getHead();
            int new_size = 0;
            while (current)
            {
                current = current->getNext();
                new_size+=1;
            }
            this->size = new_size;
        }
    }
//getters

//returns the head Node if the linked list class
    Node* getHead() const { return this->head; }
//functions
private:
// returns the Node at the end of the list
     Node* getEnd() {
        Node * current = this->getHead();
        //traverse to the end of the current linked list
        while (current->getNext()) {
            current = current->getNext();
        }
        return current;
    }
public:
// returns true if the head node is null
    const bool isEmpty() { return this->head == nullptr; }
// appends an item do the end of the linked List
    
public:
//constructor
        explicit List(){
            this->setHead(nullptr);
        }
    };
// end of List definition
}
// end of containers.h
