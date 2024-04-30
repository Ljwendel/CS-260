Leland Wendel
CS 260 - Assignment 2 (Design)


Based on what we know about linked lists, stacks, and queues, design a queue data structure:

What functions are we likely to need for a queue to function like the one discussed in class?
-queue::empty() - Returns true if the queue is empty and false otherwise
-queue::size() - Returns the size
-queue::swap() - Swap the contents of two queues if they are of the same data type
-queue::emplace() - Add a new element to the end of the queue
-queue::front() - Returns a reference to the first element of the queue
-queue::back() - returns a reference to the last element of the queue
-queue::push(2) - Adds the integer 2 to the end of the queue
-queue::pop() - Deletes the first element of the queue
-queue::peek() - Returns the element at the front of the queue without removing it

What values will we need to know about the structure for our queue to function properly?
-front pointer - indicates the first element of the queue
-rear pointer - indicates the last element of the queue
-count - keeps track of the number of elements in the queue
-size - sets a max size for the queue



Based on what we know about linked lists, design a list data structure that allows us to add (insert) or remove (delete) values at a given location in the list (instead of the top of a stack or the front or back of a queue):

What functions are we likely to need for a list to function like this?
-insert(int, pos) - inserts a node containing the given int at the given position in the list
-remove(pos) - removes the node at the specified position
-get(pos) - returns the value of the node at the given position
-size() - returns the number of nodes in the list

What values will we need to know about the structure for our list to function properly?
-head pointer - points to the first node of the list
-tail pointer - points to the last node of the list
-length - returns the number of nodes in the list
-nodes - each node has a value and pointers to the adjacent nodes