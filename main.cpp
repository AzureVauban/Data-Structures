#include "containers.h"

int main()
{
    List::List myList;
    if (myList.isEmpty())
    {
        std::cout << "my list is empty" << std::endl;
    }
    else
    {
        // output the size of the list
        int size = 0;
        std::cout << "my list has " << size << " elements!" << std::endl;
    }
    std::cout << "terminating process..." << std::endl;
    return 0;
}