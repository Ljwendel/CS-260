#ifndef GET_DATA_H
#define GET_DATA_H
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using namespace std;

// function to read data from my "state_and_capital" text file and store it into an array
int get_data(string state_cap_arr[], const string &filename)
{
    // max number of lines in the file
    int MAX_CITIES = 75;
    // opens the text file
    ifstream inputFile(filename);

    string line;
    // count the number of lines read
    int count = 0;

    // read data from the file and store it into the array
    while (getline(inputFile, line) && count < MAX_CITIES)
    {
        state_cap_arr[count++] = line;
    }

    // close the file
    inputFile.close();

    return count; // return the number of lines read
}

#endif