#include <iostream>
#include "Queue.h"

Queue::Queue (int capacity) :
    m_capacity(capacity),
    m_size(0),
    m_front(0),
    m_rear(-1)
{

}
