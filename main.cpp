#include "containers.h"

int main()
{
    // test out the Node class first
    Node node_one(nullptr, "one", nullptr);
    Node node_two(node_one, "two", nullptr);

    std::cout << "terminating process" << std::endl;
    return 0;
}