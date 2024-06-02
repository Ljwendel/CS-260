#ifndef SEARCHREMOVE_CITY_H
#define SEARCHREMOVE_CITY_H
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using namespace std;

// function to search for a city in the array
int searchCity(const string state_cap_arr[], int numLines, const string &targetCity)
{
    for (int i = 0; i < numLines; ++i)
    {
        if (state_cap_arr[i] == targetCity)
        {
            return i; // return index of city
        }
    }
    return -1; // not able to locate city
}

// function to remove a city from the list
void removeCity(string state_cap_arr[], int &numLines, const string &targetCity)
{
    int index = searchCity(state_cap_arr, numLines, targetCity);
    if (index != -1)
    {
        for (int i = index; i < numLines - 1; ++i)
        {
            state_cap_arr[i] = state_cap_arr[i + 1];
        }
        --numLines;
        cout << "\n\"" << targetCity << "\" removed from the list" << endl;
    }
    else
    {
        cout << "\"" << targetCity << "\" not found in the list" << endl;
    }
}

#endif