#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using namespace std;

// bubble sort function to sort the array of cities lexicographically
void bubbleSort(string state_cap_arr[], int size)
{
    bool swapped;
    do
    {
        swapped = false;
        for (int i = 1; i < size; ++i)
        {
            if (state_cap_arr[i - 1] > state_cap_arr[i])
            {
                swap(state_cap_arr[i - 1], state_cap_arr[i]);
                swapped = true;
            }
        }
        --size;
    } while (swapped);
}

#endif