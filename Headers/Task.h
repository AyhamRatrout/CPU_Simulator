#ifndef TASK_H
#define TASK_H
#include <stdlib.h>

static int s_startingPID = -1;

class Task
{
    public:
        Task(int taskPriority, int taskBurst) :
            m_priority(rand() % taskPriority), m_PID(s_startingPID++), m_burst(1 + rand() % taskBurst) {}
        ~Task() {}
        int const getPriority() {return this->m_priority;}
        int const getPID() {return this->m_PID;}
        int const getBurst() {return this->m_burst;}
        void decrementBurst() {this->m_burst--;}

    protected:

    private:
        const int m_priority;
        const int m_PID;
        int m_burst;
};

#endif // TASK_H
