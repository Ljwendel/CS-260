Leland Wendel
CS 260 - Data Structures
Spring 2024
LBCC
_______________________________________________________________________________

Assignment 0: Basic System Access

Five Topics of Interest:
	1. Data Structures
	2. IOT
	3. Machine Learning
	4. Artificial Intelegence
	5. Computer Programming

Five Challenging Topics:
	1. Recursion 
	2. Testing 
	3. Algorithms 
	4. Coding
	5. New Language (c++)
________________________________________________________________________________

Assignment 1: Bag of Marbles

This program uses a class to represent a bag of marbles (MarbleBag{}). From
the menu, the user is prompted to add marbles, remove marbles, view the contents
of the marble bag, or exit the program.

- If the user chooses to add marbles, the program prompts for the number of
  marbles to add and for the color of those marbles.

- If the user chooses to remove marbles, the program prompts for the
  of color marble and the number of marbles to remove of that color.

- If the user chooses to view the contents of the bag, the program displays the
  current contents of the bag. If the bag is empty, the program will print the
  message: "the bag is empty".

- Included in the main function is a test to check what happens if marbles are
  removed from an empty bag.

A pdf will be included with my submission to provide screen clips of the code
to show how it meets the requirements for assignment 1.
________________________________________________________________________________

Assignment 2: Design

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



Based on what we know about linked lists, design a list data structure that allows us to 
add (insert) or remove (delete) values at a given location in the list (instead of the top 
of a stack or the front or back of a queue):

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
_______________________________________________________________________________

Assignment 3: Linked Queue

See README.pdf in assignment3 folder for details and screenshots of the program functioning.
_______________________________________________________________________________

Assignment 4: Arbitrary List Operations

See README.pdf in assignment4 folder for details and screenshots of the program functioning.
_______________________________________________________________________________





