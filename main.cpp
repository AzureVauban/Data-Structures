#include "queue.h"
#include "stack.h"

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

    /*
    Stack::Stack<int> stack_nums;
    for (int i = 0; i < 10; i++)
    {
        stack_nums.push(fibsequence(i));
    }
    // std::cout << "destroying " << stack_nums.pop() << std::endl; // dequeues 55
    */

    Queue::Queue<long long int> nums_queue;
    //Stack::Stack<int> nums_stack;
    int size = 100;
    for (int i = 0; i < size; i++)
    {
        nums_queue.enqueue(fibsequence(i));
      //  nums_stack.push(input_number);
    }
    for (int i = 0; i < size; i++)
    {
        std::cout << "Dequeueing: " << nums_queue.dequeue() << std::endl;
                 // << "Popping from the Stack " << nums_stack.pop() << std::endl;
    }

    std::cout << "terminating process" << std::endl;
    return 0;
}