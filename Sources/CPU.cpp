#include "CPU.h"

// Forward declaration of private member functions.
void initializeRunQueue(unsigned int maximumPriority, unsigned int maximumCapacity);
void createNewTasks();

CPU::CPU(unsigned int maximumPriority, unsigned int maximumBurst, unsigned int cycleTime, size_t maximumCapacity) :
    m_maximumPriority(maximumPriority),
    m_maximumBurst(maximumBurst),
    m_cycleTime(cycleTime),
    m_cycleTimePassed(0),
    m_cycleIsDone(false),
    m_currentTask(nullptr),
    m_runQueue()
{
}

void CPU::initializeRunQueue(unsigned int maximumPriority, unsigned int maximumCapacity) {
    for (unsigned int priority = 0; priority < maximumPriority; priority++) {
        Queue *q = new Queue(maximumCapacity);
        this->m_runQueue[priority] = q;
    }
}

void CPU::createNewTasks() {
    // Creates a maximum of 25 new tasks with each call.
    int numOfNewTasks = 1 + (std::rand() % 25);
    for (int index = 0; index < numOfNewTasks; index++) {
        Task *T = new Task(2, this->m_maximumBurst);
        printf("New task created! Priority = %d \t Burst Time = %d \t PID = %d\n", T->getPriority(), T->getBurst(), T->getPID());
        this->m_runQueue[T->getPriority()]->enqueue(T);
        printf("\nTask with PID %d and priority %d was successfully added to the run queue.", T->getPID(), T->getPriority());
    }
}
