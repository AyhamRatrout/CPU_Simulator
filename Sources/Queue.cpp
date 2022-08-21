#include <iostream>
#include "Queue.h"

Queue::Queue (int capacity) :
    m_capacity(capacity),
    m_size(0),
    m_front(0),
    m_rear(-1)
{

}

void Queue::enqueue(Task task) {
    if (this->isFull()) {
        std::cerr << "Invalid operation! Cannot queue an already full queue." << std::endl;
        return;
    }
    this->m_size++;
    this->m_rear++;
    if (this->m_rear == this->m_capacity) {
        this->m_rear = 0;
    }
    this->m_tasks.push_back(&task);
    return;
}

void Queue::dequeue() {
    if (this->isEmpty()) {
        std::cerr << "Invalid operation! Cannot dequeue an empty queue." << std::endl;
        return;
    }
    Task *task = this->m_tasks[this->m_front];
    this->m_tasks.erase(this->m_tasks.begin() + this->m_front);
    delete task;
    this->m_size--;
    this->m_front++;
    if (this->m_front == this->m_capacity) {
        this->m_front = 0;
    }
    return;

}
