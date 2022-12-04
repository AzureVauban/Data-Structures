#include "containers.h"

void evaluate_linked_list(List::List &linked_list){
    if (linked_list.isEmpty())
    {
        std::cout << "my list is empty" << std::endl;
        //append something to the list
        linked_list.append();
        evaluate_linked_list(linked_list);
    }
    else
    {
        // output the size of the list
        int size = linked_list.getSize();
        std::cout << "my list has " << size << " elements!" << std::endl;
    }
}
int main()
{
    List::List myList;
    evaluate_linked_list(myList)   ;
    int end_of_process_size = myList.getSize();
    std::cout << "terminating process..." << std::endl;
    return 0;
}