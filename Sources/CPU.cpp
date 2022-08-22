#include "CPU.h"

// Forward declaration of private member functions.
void initializeRunQueue(unsigned int maximumPriority, unsigned int maximumCapacity);

CPU::CPU(unsigned int maximumPriority, unsigned int maximumBurst, unsigned int cycleTime, size_t maximumCapacity) :
    m_maximumPriority(maximumPriority),
    m_maximumBurst(maximumBurst),
    m_cycleTime(cycleTime),
    m_cycleTimePassed(0),
    m_cycleIsDone(false),
    m_currentTask(nullptr),
    m_runQueue()
{
    this->m_runQueue[maximumPriority] = {};
}

void CPU::initializeRunQueue(unsigned int maximumPriority, unsigned int maximumCapacity) {
    for (unsigned int priority = 0; priority < maximumPriority; priority++) {
        Queue *q = new Queue(maximumCapacity);
        this->m_runQueue[priority] = q;
    }
}
