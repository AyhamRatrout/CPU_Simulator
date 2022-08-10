#ifndef TASK_H
#define TASK_H
#include <stdlib.h>

static int s_startingPID = -1;

class Task
{
    public:
        Task() :
            m_priority(rand() % 256), m_PID(s_startingPID++), m_burst(1 + rand() % 100) {}
        ~Task() {}


    protected:

    private:
        const int m_priority;
        const int m_PID;
        int m_burst;
};

#endif // TASK_H
