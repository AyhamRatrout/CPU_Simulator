#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include "Task.h"

class Queue {

    public:
        Queue();
        ~Queue();
        bool isEmpty() {return this->m_size == 0;}
        bool isFull() {return this->m_size == this->m_capacity;}
        virtual void dequeue();
        virtual void enqueue();

    protected:

    private:
        const int m_capacity;
        int m_size;
        int m_front;
        int m_rear;
};

#endif // QUEUE_H_INCLUDED
