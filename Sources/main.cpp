#include <iostream>
#include "Queue.h"
#include "Task.h"
#include "CPU.h"

int main()
{
    Task *t1 = nullptr;
    std::cout << t1->getBurst() << std::endl;
    std::cout << t1->getPID() << std::endl;
    std::cout << t1->getPriority() << std::endl;
    t1 = new Task(5, 10);
    std::cout << t1->getBurst() << std::endl;
    std::cout << t1->getPID() << std::endl;
    std::cout << t1->getPriority() << std::endl;
    t1->decrementBurst();
    std::cout << t1->getBurst() << std::endl;
    std::cout << t1->getPID() << std::endl;
    std::cout << t1->getPriority() << std::endl;
    Task *t2 = new Task(5, 10);
    std::cout << t2->getBurst() << std::endl;
    std::cout << t2->getPID() << std::endl;
    std::cout << t2->getPriority() << std::endl;
}
