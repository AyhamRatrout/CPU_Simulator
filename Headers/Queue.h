#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include <vector>
#include "Task.h"

class Queue {

    public:
        Queue(int capacity);
        ~Queue() {}
        bool isEmpty() {return this->m_size == 0;}
        bool isFull() {return this->m_size == this->m_capacity;}
        int getSize() {return this->m_size;}

    protected:

    private:
        const int m_capacity;
        int m_size;
        int m_front;
        int m_rear;
};

#endif // QUEUE_H_INCLUDED
