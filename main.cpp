#include "containers.h"

int main()
{
    // test out the Node class first
    // Node(/*PREVIOUS*/,/*DATA*/,/*DATA*/)
    Node node_one(nullptr, "one", nullptr);
    Node node_two(&node_one, "two", nullptr);
    Node nodesufhhgf(&node_two,"hfg",nullptr);
    std::cout << "terminating process" << std::endl;
    return 0;
}