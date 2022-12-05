#include "containers.h"

int main()
{
    // test out the Node class first
    // Node(/*PREVIOUS*/,/*DATA*/,/*DATA*/)
    //Node purple(nullptr, "one", nullptr);
    Queue waitlist;
    waitlist.enqueue("Bob");
    waitlist.enqueue("Michael");
    waitlist.enqueue("Jenny");
    std::cout << "terminating process" << std::endl;
    return 0;
}