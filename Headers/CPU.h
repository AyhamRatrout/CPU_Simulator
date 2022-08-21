#ifndef CPU_H_INCLUDED
#define CPU_H_INCLUDED

#include "Queue.h"

class CPU
{
    public:
        CPU(unsigned int maximumPriority,
            unsigned int maximumBurst,
            size_t maximumCapacity);
        ~CPU() {};

    protected:

    private:
        const unsigned int m_maximumPriority;
        const unsigned int m_maximumBurst;
        unsigned int m_cycleTimePassed;
        bool m_cycleIsDone;
        Queue *m_runQueue[];
};

#endif // CPU_H_INCLUDED
