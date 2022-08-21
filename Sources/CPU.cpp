#include "CPU.h"

CPU::CPU(unsigned int maximumPriority, unsigned int maximumBurst, size_t maximumCapacity) :
    m_maximumPriority(maximumPriority),
    m_maximumBurst(maximumBurst),
    m_cycleTimePassed(0),
    m_cycleIsDone(false),
    m_runQueue()
{
    this->m_runQueue[maximumCapacity] = {};
    for (size_t index = 0; index < maximumPriority; index++) {
        this->m_runQueue[index] = new Queue(maximumCapacity);
    }
}

