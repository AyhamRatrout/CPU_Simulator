#include "CPU.h"

// Forward declaration of virtual private member function.
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
    this->m_runQueue[maximumPriority] = {};
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
        this->m_cycleTimePassed++;
        if (this->m_currentTask == nullptr) {
            for (unsigned int priority = 0; priority < this->m_maximumPriority; priority++) {
                if (!this->m_runQueue[priority]->isEmpty()) {
                    this->m_currentTask = this->m_runQueue[priority]->getFront();
                    this->m_runQueue[priority]->dequeue();
                    break;
                }
            }
            printf("\nTask with PID %d and priority %d was just moved to the CPU. Remaining time to complete this task is: %d\n\n", this->m_currentTask->getPID(), this->m_currentTask->getPriority(), this->m_currentTask->getBurst());
        } else {
            this->m_currentTask->decrementBurst();
            printf("\nTask with PID %d and priority %d is currently running on the CPU. Remaining time to complete this task is: %d\n\n", this->m_currentTask->getPID(), this->m_currentTask->getPriority(), this->m_currentTask->getBurst());
            if (this->m_currentTask->getBurst() == 0) {
                printf("\nTask with PID %d and priority %d is done executing! A new task will be added to the CPU in the next cycle.\n\n", this->m_currentTask->getPID(), this->m_currentTask->getPriority());
                this->m_cycleTimePassed = 0;
                this->m_currentTask = nullptr;
            } else if (this->m_cycleIsDone) {
                this->m_runQueue[this->m_currentTask->getPriority()]->enqueue(this->m_currentTask);
                printf("\nTask with PID %d and priority %d has used up a full CPU cycle and is yet to be completed! This task will be kicked off the CPU and a new task will take its place in the next cycle.\n\n", this->m_currentTask->getPID(), this->m_currentTask->getPriority());
                this->m_cycleTimePassed = 0;
                this->m_currentTask = nullptr;
            }
        }
    }
    return;
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
