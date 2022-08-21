#ifndef TASK_H
#define TASK_H
#include <stdlib.h>

static int s_startingPID = -1;

class Task
{
    public:
        Task(unsigned int taskPriority, unsigned int taskBurst) :
            m_priority(rand() % taskPriority),
            m_PID(++s_startingPID),
            m_burst(1 + rand() % taskBurst) {}
        ~Task() {}
        int getPriority() {return (nullptr != this) ? this->m_priority : -1;}
        int getPID() {return (nullptr != this) ? this->m_PID : -1;}
        int getBurst() {return (nullptr != this) ? this->m_burst : -1;}
        void decrementBurst() {if(this != nullptr) this->m_burst--;}

    protected:

    private:
        const unsigned int m_priority;
        unsigned const int m_PID;
        unsigned int m_burst;
};

#endif // TASK_H
