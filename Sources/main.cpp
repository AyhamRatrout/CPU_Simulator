#include <iostream>
#include "Queue.h"
#include "Task.h"
#include "CPU.h"

using namespace std;

int main()
{
    CPU *cpu = new CPU(3, 10, 10, 3);
    Task *t1 = new Task(1, 1);
    Task *t2 = new Task(2, 2);
    std::cout << t1->getPID() << std::endl;
    cpu->initializeRunQueue(10, 10);
    std::cout << cpu->m_runQueue[0]->getFront()->getPID() << std::endl;
    std::cout << cpu->m_runQueue[9]->isEmpty() << std::endl;
}
