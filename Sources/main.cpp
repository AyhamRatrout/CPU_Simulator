#include <iostream>
#include "Queue.h"
#include "Task.h"

using namespace std;

int main()
{
    Task *t = new Task(1, 1);
    Task *t1 = new Task(2, 2);
    std::cout << t->getBurst() << std::endl;
    std::cout << t->getPID() << std::endl;
    std::cout << t->getPriority() << std::endl;
    std::cout << t1->getBurst() << std::endl;
    std::cout << t1->getPID() << std::endl;
    std::cout << t1->getPriority() << std::endl;
}
