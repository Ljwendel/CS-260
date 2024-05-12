#include <iostream>
#include "assignment4_wendel.h"

using std::cout;
using std::endl;

int main() {
    LinkedList<int> myList;

    // Add elements to the list
    myList.add(1, 0);
    myList.add(2, 1);
    myList.add(3, 2);
    myList.add(4, 3);

    // Display the list
    cout << "List after adding elements: ";
    for (int i = 0; i < myList.getSize(); ++i) {
        cout << myList.get(i) << " ";
    }
    cout << endl;

    // Test the get function
    int positionToGet = 1;
    cout << "Value at position " << positionToGet << ": " << myList.get(positionToGet) << endl;

    // Remove an element from the list
    int removedValue = myList.remove(2);
    cout << "Removed value: " << removedValue << endl;

    // Display the list after removal
    cout << "List after removing element: ";
    for (int i = 0; i < myList.getSize(); ++i) {
        cout << myList.get(i) << " ";
    }
    cout << endl;

    return 0;
}
