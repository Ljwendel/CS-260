#include <iostream>
#include <cstdio>

using std::cout;
using std::endl;

// #define true 1
// #define false 0
// #define pi 3.141592563

int main() {

    char mander = 'A';
    int eger = 24;
    float rootBeer = 3.14;
    bool ean = true;

    unsigned short shorty = 65535;
    long long longy = 4200000000000;
    double precision = 6.28;

    cout << "Hello STD?" << endl << (int)mander << endl << eger << endl << rootBeer << endl <<
        ean << endl << shorty << endl << longy << endl << precision << endl;

    if(eger == 25) {
        cout<< "The if statement condition resolves as truthy." << endl;
    } else if (eger) {
        cout<< "The else if clause condition resolves as truthy." << endl;
    } else {
        cout<< "The if statement condition resolves as falsey." << endl;
    }

    cout << "This statement will always run." << endl;
    cout << "This statement will also always run." << endl;

    printf("This is a tring with some formatting, such as an int %i, or a character %c\n", mander, mander);

    int i = 0;
    for (; ; )
    {
        // cout << "i: " << i << endl;
        printf("i: %i\n", i);
        i++;
        if (i >= 10) {
            break;
        }
    }
    printf("i (after the loop): %i\n", i);

    while (i < 20) {

        printf("i (during while loop): %i\n", i);
        i++;
    }

    return 0;
}