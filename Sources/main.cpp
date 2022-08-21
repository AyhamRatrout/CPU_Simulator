#include <iostream>
#include "Queue.h"
#include "Task.h"

using namespace std;

int main()
{
    Queue q(10);
    std::cout << q.isEmpty() << std::endl;
    std::cout << q.getSize() << std::endl;
    std::cout << q.isFull() << std::endl;

}
