#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <iostream>
#include "Task.h"

class Queue {

    public:
        Queue(size_t capacity);
        ~Queue() {}
        virtual void enqueue(Task *task);
        virtual void dequeue();
        virtual Task *getFront();
        bool isEmpty() {return this->m_size == 0;}
        bool isFull() {return this->m_size == this->m_capacity;}
        int getSize() {return this->m_size;}

    protected:

    private:
        const size_t m_capacity;
        size_t m_size;
        unsigned int m_front;
        int m_rear;
        Task *m_tasks[];
};

#endif // QUEUE_H_INCLUDED
