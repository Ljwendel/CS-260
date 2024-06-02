#ifndef INSERT_CITY_H
#define INSERT_CITY_H
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using namespace std;

// function to insert a new city into the correct position in the sorted array of cities
void insertCity(string state_cap_arr[], int &numLines, const string &newCity)
{
    // identify the correct position to insert the new city
    int i = numLines - 1;
    while (i >= 0 && state_cap_arr[i] > newCity)
    {
        state_cap_arr[i + 1] = state_cap_arr[i];
        --i;
    }

    // insert new city into the correct position
    state_cap_arr[i + 1] = newCity;
    ++numLines;
}

#endif