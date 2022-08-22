#include "CPU.h"

// Forward declaration of virtual private member function.
void createNewTasks();

CPU::CPU(unsigned int maximumPriority, unsigned int maximumBurst, unsigned int cycleTime, size_t maximumCapacity) :
    m_maximumPriority(maximumPriority),
    m_maximumBurst(maximumBurst),
    m_cycleTime(cycleTime),
    m_cycleTimePassed(0),
    m_cycleIsDone(false),
    m_runQueue()
{
    this->m_runQueue[maximumCapacity] = {};
    for (size_t index = 0; index < maximumPriority; index++) {
        this->m_runQueue[index] = new Queue(maximumCapacity);
    }
}

void CPU::runSimulator(unsigned int simulationDuration) {
    for (size_t index = 0; index < simulationDuration; index++) {
        if ((this->m_cycleTimePassed != 0) &&
            (this->m_cycleTimePassed % this->m_cycleTime) == 0) {
            this->m_cycleIsDone = true;
        } else {
            this->m_cycleIsDone = false;
        }
        this->createNewTasks();
    }
}

void CPU::createNewTasks() {
    // Creates a maximum of 25 new tasks with each call.
    int numOfNewTasks = (1 + std::rand()) % 25;
    for (int index = 0; index < numOfNewTasks; index++) {
        Task *T = new Task(this->m_maximumPriority, this->m_maximumBurst);
        printf("New task created! Priority = %d \t Burst Time = %d \t PID = %d\n", T->getPriority(), T->getBurst(), T->getPID());
        printf("%d\n", T->getPriority());
        this->m_runQueue[T->getPriority()]->enqueue(T);
        printf("\nTask with PID %d and priority %d was successfully added to the run queue.", T->getPID(), T->getPriority());
    }
}
