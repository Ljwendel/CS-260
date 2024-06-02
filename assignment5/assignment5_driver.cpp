#include <iostream>
#include <string>
#include "get_data.h"
#include "bubble_sort.h"
#include "insertCity.h"
#include "searchremoveCity.h"

using std::cout;
using std::endl;
using namespace std;

// print function to reduce the length of main
void printArr(const string state_cap_arr[], int numLines)
{
    for (int i = 0; i < numLines; ++i)
    {
        cout << state_cap_arr[i] << endl;
    }
}

int main()
{
    int MAX_CITIES = 75;
    // store data from the txt file as an array 'state_cap_list'
    string state_cap_arr[MAX_CITIES];
    string filename = "state_capital.txt"; // set file name here

    // read data from the file
    int numLines = get_data(state_cap_arr, filename);

    // print the data stored in the array
    cout << "\nList of state capitals:" << endl;
    printArr(state_cap_arr, numLines);

    // test bubble sort array of cities
    bubbleSort(state_cap_arr, numLines);

    // print the sorted cities
    cout << "\nBubble sorted list of cities:" << endl;
    printArr(state_cap_arr, numLines);

    // test 'add' a new city
    string newCity = "Corvallis";
    insertCity(state_cap_arr, numLines, newCity);

    // print the updated list of cities
    cout << "\nUpdated list of cities after inserting \"" << newCity << "\":" << endl;
    printArr(state_cap_arr, numLines);

    // test 'search' for a city
    string targetCity = "Corvallis";
    int index = searchCity(state_cap_arr, numLines, targetCity);
    if (index != -1)
    {
        cout << "\n\"" << targetCity << "\" found at index " << index << endl;
    }
    else
    {
        cout << "\n\"" << targetCity << "\" not found" << endl;
    }

    // test 'remove' a city
    string cityToRemove = "Corvallis";
    removeCity(state_cap_arr, numLines, cityToRemove);

    // print the updated list of cities
    cout << "\nUpdated list of cities after removing \"" << cityToRemove << "\":" << endl;
    printArr(state_cap_arr, numLines);

    return 0;
}
