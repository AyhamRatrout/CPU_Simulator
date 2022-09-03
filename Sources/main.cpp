#include <iostream>
#include "Queue.h"
#include "Task.h"
#include "CPU.h"

int main()
{
    Task *t1 = new Task(10, 10);
    Task *t2 = new Task(9, 9);
    Task *t3 = new Task(8, 8);
    Task *t4 = new Task(7, 7);
    Task *t5 = new Task(6, 6);
    Task *t6 = new Task(5, 5);
    Task *t7 = new Task(4, 4);
    Queue *q = new Queue(7);
    std::cout << q->isEmpty() << std::endl;
    std::cout << q->isFull() << std::endl;
    std::cout << q->getSize() << std::endl;
    std::cout << q->getFront()->getBurst() << std::endl;
    std::cout << q->getFront()->getPID() << std::endl;
    std::cout << q->getFront()->getPriority() << std::endl;
    q->enqueue(t1);
    std::cout << q->getSize() << std::endl;
    std::cout << q->getFront()->getBurst() << std::endl;
    std::cout << q->getFront()->getPID() << std::endl;
    std::cout << q->getFront()->getPriority() << std::endl;
    q->enqueue(t2);
    std::cout << q->getSize() << std::endl;
    std::cout << q->getFront()->getBurst() << std::endl;
    std::cout << q->getFront()->getPID() << std::endl;
    std::cout << q->getFront()->getPriority() << std::endl;
    q->dequeue();
    std::cout << q->getSize() << std::endl;
    std::cout << q->getFront()->getBurst() << std::endl;
    std::cout << q->getFront()->getPID() << std::endl;
    std::cout << q->getFront()->getPriority() << std::endl;
    q->enqueue(t3);
    q->enqueue(t4);
    q->dequeue();
    q->dequeue();
    q->dequeue();
    std::cout << q->getSize() << std::endl;
    std::cout << q->getFront()->getBurst() << std::endl;
    std::cout << q->getFront()->getPID() << std::endl;
    std::cout << q->getFront()->getPriority() << std::endl;
}
