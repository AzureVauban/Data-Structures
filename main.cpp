#include "containers.h"

int main()
{
    // test out the Node class first
    Node node_one(new Node(nullptr,"negative one",nullptr), "one", nullptr);
//    Node node_two(&node_one, "two", nullptr);
    // call the destructor
    node_one.~Node();
    // print out the data
    //node_two.~Node();
    std::cout << "terminating process" << std::endl;
    return 0;
}