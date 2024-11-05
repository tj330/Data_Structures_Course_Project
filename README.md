# Basic TodoList application

Functionalities: 
            
    Add new tasks: Users can input a task description and assign it a priority. The task is then added to a priority queue, where tasks with higher priority are processed first.
    View tasks: Users can view a list of incomplete tasks, displayed in order of priority.
    Complete tasks: The highest-priority task is removed from the queue and marked as completed. The task's description and completion time are stored in a stack.
    View completed tasks history: Users can view a list of completed tasks, along with their completion times.
    Delete completed tasks history: Users can clear the completed tasks history from the stack.

Data Structures used:

    Priority Queue: Implemented as an array-based queue, where elements are inserted in priority order.
    Stack: Implemented as an array-based stack to store completed tasks and their completion times.
    
Key Functions:

    enqueue: Adds a new task to the priority queue.
    dequeue: Removes the highest-priority task from the queue and pushes it onto the stack.
    display: Prints the current list of incomplete tasks.
    sDisplay: Prints the history of completed tasks.
    push: Pushes a completed task onto the stack.
    pop: Removes all completed tasks from the stack.
    getDate: Gets the current date and time.









