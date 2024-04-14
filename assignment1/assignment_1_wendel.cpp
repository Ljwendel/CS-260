/*
Leland Wendel
CS 260
Assignment 1

See README.txt in the assignment 1 folder for program description.
*/

#include <iostream>
#include <unordered_map>

using namespace std;

// Class to represent a bag of marbles.
class MarbleBag {
private:
    unordered_map<string, int> marbles; // Using unordered_map to store marbles and their counts.

public:
    // Function to add marbles to the bag.
    void addMarbles(const string& color, int count) {
        marbles[color] += count;
    }

    // Function to remove marbles from the bag.
    void removeMarbles(const string& color, int count) {
        if (marbles.find(color) != marbles.end()) {
            marbles[color] -= count;
            if (marbles[color] <= 0)
                marbles.erase(color);
        } else {
            cout << "Marble color '" << color << "' not found in the bag." << endl;
        }
    }

    // Function to display the contents of the bag.
    void displayContents() {
        if (marbles.empty()) {
            cout << "The bag is empty." << endl;
        } else {
            cout << "Marble Bag Contents:" << endl;
            for (const auto& pair : marbles) {
                cout << pair.first << ": " << pair.second << endl;
            }
        }
    }
};

// This is the main function.
int main() {
    MarbleBag bag;
    int choice;
    string color;
    int count;

    // Attempt to remove a marble from an empty bag.
    cout << "Trying to remove a marble from an empty bag..." << endl;
    bag.removeMarbles("blue", 1);

    // Display contents of the bag (should show that it's empty).
    cout << "\nContents of the bag after attempting to remove from an empty bag:" << endl;
    bag.displayContents();

    // Display menu
    do {
        cout << "Choose an option:" << endl;
        cout << "1. Add marbles to the bag" << endl;
        cout << "2. Remove marbles from the bag" << endl;
        cout << "3. Display contents of the bag" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter the color of the marble to add: ";
                cin >> color;
                cout << "Enter the number of marbles to add: ";
                cin >> count;
                bag.addMarbles(color, count);
                break;
            case 2:
                cout << "Enter the color of the marble to remove: ";
                cin >> color;
                cout << "Enter the number of marbles to remove: ";
                cin >> count;
                bag.removeMarbles(color, count);
                break;
            case 3:
                bag.displayContents();
                break;
            case 4:
                cout << "Exiting Program" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while(choice != 4);

    return 0;
}
