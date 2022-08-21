#include <iostream>
#include "Queue.h"
#include "Task.h"

using namespace std;

int main()
{
    Queue *q = new Queue(10);
    Task *t1 = new Task(1,1);
    Task *t2 = new Task(2,2);
    q->enqueue(t1);
    q->enqueue(t2);
    Task *t3 = new Task(3, 3);

    std::cout << q->getFront()->getPID() << std::endl;
    std::cout << q->getSize() << std::endl;

    q->dequeue();
    std::cout << q->getFront()->getPID() << std::endl;
    std::cout << q->getSize() << std::endl;

    q->dequeue();
    std::cout << q->getFront()->getPID() << std::endl;
    std::cout << q->getSize() << std::endl;

    q->enqueue(t3);
    std::cout << q->getFront()->getPID() << std::endl;
    std::cout << q->getSize() << std::endl;
}
