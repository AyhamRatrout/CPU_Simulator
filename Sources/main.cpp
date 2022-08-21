#include <iostream>
#include "Queue.h"
#include "Task.h"

using namespace std;

int main()
{
    Queue q(10);
    Task t1(1, 1);
    Task t2(2, 2);
    q.enqueue(t1);
    q.enqueue(t2);

    std::cout << q.m_tasks[0]->getPID() << std::endl;
        std::cout << q.getSize() << std::endl;

    q.dequeue();
        std::cout << q.m_tasks[0]->getPID() << std::endl;
            std::cout << q.getSize() << std::endl;



}
