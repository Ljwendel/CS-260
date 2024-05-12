#include <iostream>

using std::cout;
using std::endl;

// Define a template class LinkedList that can be parameterized with any data type.
template <typename T>
class LinkedList {
private:
    // Defines a Node struct.
    struct Node {
        // 'data' contains value of the node
        T data;
        // 'next' points to the next node in the list
        Node* next;
        // initialized 'data' with the input value and sets 'next' pointer to nullptr
        Node(const T& value) : data(value), next(nullptr) {}
    };
    // 'head' is a pointer to the first node of the list
    Node* head;
    // size holds the number of elements in the list
    int size;

public:
    // constructor of the LinkedList class, sets head pointer and size of the list
    LinkedList() : head(nullptr), size(0) {}

    // add(value to be added, insertion point)
    void add(const T& value, int position) {
        // if the input position exists (is a natural number and is less than list size)
        if (position < 0 || position > size) {
            cout << "Invalid position." << endl;
            return;
        }

        // allocates memory for the new node and initializes it with the input value
        Node* newNode = new Node(value);

        // if input position is 0, newNode is now the head
        if (position == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            // else, locate 'position-1', update pointers, and insert value
            Node* temp = head;
            for (int i = 0; i < position - 1; ++i) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        // increment the size of the list after adding the new node
        size++;
    }

    // remove(input integer position)
    T remove(int position) {
        // check if the input position is valid
        if (position < 0 || position >= size) {
            cout << "Invalid position." << endl;
            // quit if not valid
            exit(EXIT_FAILURE);
        }
        // temporary pointer 'temp' initialized to the head of the list
        Node* temp = head;
        // if the input position is zero, update 'head' pointer
        if (position == 0) {
            head = head->next;
        // else, loop over list until 'temp' points to the node at "position-1"
        } else {
            for (int i = 0; i < position - 1; ++i) {
                temp = temp->next;
            }
            // updates 'next' pointer to "position-1", skipping (removing) input node
            Node* toDelete = temp->next;
            // stores pointer to the node to be deleted
            temp->next = toDelete->next;
            // delete the removed node from the list
            delete toDelete;
        }
        // update list size
        size--;
        // return the value stored in the removed node if needed
        T value = temp->data;
        return value;
    }

    // get(input integer position)
    T get(int position) {
        // check if the input position is valid
        if (position < 0 || position >= size) {
            cout << "Invalid position." << endl;
            // exit if not
            exit(EXIT_FAILURE);
        }
        // temporary pointer 'temp' initialized to the head of the list
        Node* temp = head;
        // loop through the list until 'temp' points to the input position
        // iterates "position" times to move temp to the proper node
        for (int i = 0; i < position; ++i) {
            temp = temp->next;
        }
        // returns the value stored in the node that 'temp' is pointing to.
        return temp->data;
    }

    // returns the number of elements currently stored in the linked list
    int getSize() const {
        return size;
    }

    // deallocate memory that was allocated for the nodes of the list
    ~LinkedList() {
        // while head is not pointing to nullptr
        while (head != nullptr) {
            // creates a 'temp' pointer and initializes it to the current head of the list
            Node* temp = head;
            // updates the head pointer to point at the next node in the list, moving the head
            head = head->next;
            // delete the node that 'temp' is pointing to
            delete temp;
        }
    }
};
