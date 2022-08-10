# CPU Simulator

For the purpose of this project, I decided to write a C/C++ program to simulate the functionality of a simple CPU, which utilizes one worker thread, with 256 levels of priority in a run queue. Particularly, this program simulates the arrival of new tasks, the recirculation of tasks getting preempted by time slice expiration, as well as the returning of tasks to the back of the FIFO queue at each priority level once preempted off the CPU. It is important to note that the CPU structure (a queue in this case) was constructed using static arrays as the base data structure.  
