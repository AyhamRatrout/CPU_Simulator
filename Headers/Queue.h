#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include <vector>
#include "Task.h"

class Queue {

    public:
        Queue(int capacity);
        ~Queue() {}
        virtual void enqueue(Task task);
        virtual void dequeue();
        bool isEmpty() {return this->m_size == 0;}
        bool isFull() {return this->m_size == this->m_capacity;}
        int getSize() {return this->m_size;}
std::vector < Task *> m_tasks;

    protected:

    private:
        const size_t m_capacity;
        size_t m_size;
        unsigned int m_front;
        int m_rear;

};

#endif // QUEUE_H_INCLUDED
