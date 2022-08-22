#ifndef CPU_H_INCLUDED
#define CPU_H_INCLUDED

#include <cstdio>
#include "Queue.h"

class CPU
{
    public:
        CPU(unsigned int maximumPriority,
            unsigned int maximumBurst,
            unsigned int cycleTime,
            size_t maximumCapacity);
        ~CPU() {};
        virtual void runSimulator(unsigned int simulationDuration);

    protected:

    private:
        const unsigned int m_maximumPriority;
        const unsigned int m_maximumBurst;
        const unsigned int m_cycleTime;
        unsigned int m_cycleTimePassed;
        bool m_cycleIsDone;
        Task *m_currentTask;
        Queue *m_runQueue[];
        virtual void createNewTasks();
};

#endif // CPU_H_INCLUDED
