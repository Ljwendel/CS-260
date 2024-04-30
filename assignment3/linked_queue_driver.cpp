#include <iostream>
#include "linked_queue.h"

using std::cout;
using std::endl;


int main() {
    LinkedQueue test;

    // Test enqueue
    test.enqueue(1);
    test.enqueue(2);
    test.enqueue(3);

    // Test peek
    cout << "head element: " << test.peek() << endl;

    // Test dequeue
    cout << "Dequeued elements: ";
    while (!test.isEmpty()) {
        cout << test.dequeue() << " ";
    }
    cout << endl;

    // Test isEmpty after dequeue
    cout << "Is queue empty? " << (test.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}