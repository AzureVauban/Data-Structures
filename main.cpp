#include "queue.h"
#include "List.h"
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
void comparison_demo(Queue::Queue<long long int> &Queue,
                     Stack::Stack<long long int> &Stack)
{
    for (int i = 1; i <= 10; i++)
    {
        int term = fibsequence(i + 1);
        Queue.enqueue(term);
        Stack.push(term);
    }
    std::cout << "Peaking Queue: " << Queue.peak() << std::endl
              << "Peaking Stack: " << Stack.peak() << std::endl;
    for (int i = 0; i < 9; i++)
    {
        if (i < 4)
        {
            std::cout << "Dequeuing (From Queue): " << Queue.dequeue() << "  | "
                      << "Popping (From Stack): " << Stack.pop() << std::endl;
        }
        else
        {
            std::cout << "Dequeuing (From Queue): " << Queue.dequeue() << " | "
                      << "Popping (From Stack): " << Stack.pop() << std::endl;
        }
    }
    std::cout << "Peaking Queue: " << Queue.peak() << std::endl
              << "Peaking Stack: " << Stack.peak() << std::endl;
}
int main()
{
    Queue::Queue<long long int> nums_queue;
    Stack::Stack<long long int> nums_stack;
    List::List<long long int> nums_list;
    comparison_demo(nums_queue, nums_stack);
    std::cout << "terminating process" << std::endl;
    return 0;
}