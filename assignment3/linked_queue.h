#include <iostream>
#include "node.h"

using std::cout;
using std::endl;


// Define the LinkedQueue class
class LinkedQueue {

    private:
        Node* head; // Points to the head of the queue
        Node* tail;  // Points to the tail of the queue

    public:
        LinkedQueue() : head(nullptr), tail(nullptr) {}

        // Function to add an element to the tail of the queue
        void enqueue(int value) {
            Node* new_node = new Node(value);
            if (isEmpty()) {
                head = tail = new_node;
            } else {
                tail->next = new_node;
                tail = new_node;
            }
        }

        // Function to remove and return the element at the head of the queue
        int dequeue() {
            if (isEmpty()) {
                cout << "Queue is empty!" << endl;
                exit(EXIT_FAILURE);
            }
            int value = head->data;
            Node* temp = head;
            head = head->next;
            delete temp;
            if (head == nullptr) {
                tail = nullptr;
            }
            return value;
        }

        // Function to check if the queue is empty
        bool isEmpty() {
            return head == nullptr;
        }

        // Function to return the element at the head of the queue without removing it
        int peek() {
            if (isEmpty()) {
                cout << "Queue is empty!" << endl;
                exit(EXIT_FAILURE);
            }
            return head->data;
        }
    };
