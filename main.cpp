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

void Queue_demo(Queue::Queue<long long int> &nums)
{
    // first in, first out
    int size = 11;
    for (int i = 0; i < size; i++)
    {
        nums.enqueue(fibsequence(i));
    }
    for (int i = 0; i < size - 1; i++)
    {
        std::cout << "Dequeueing: " << nums.dequeue() << std::endl;
    }
}

void Stack_demo(Stack::Stack<long long int> &nums)
{
    // last in, first out
    int size = 11;
    for (int i = 0; i < size; i++)
    {
        nums.push(fibsequence(i));
    }
    for (int i = 0; i < size - 1; i++)
    {
        std::cout << "Popping from the stack: " << nums.pop() << std::endl;
    }
}
int main()
{
   // Queue::Queue<long long int> nums_queue;
    Stack::Stack<long long int> nums_stack;
    //Queue_demo(nums_queue);
    Stack_demo(nums_stack);
    std::cout << "terminating process" << std::endl;
    return 0;
}