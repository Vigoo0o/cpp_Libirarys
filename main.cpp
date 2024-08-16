// To Tist Functions

#include <iostream>

#include "./Libs/array.h"
#include "./Libs/IO.h"
#include "./Libs/math.h"
#include "./Libs/String.h"
#include "./Libs/Utility.h"
#include "./Libs/valdation.h"

using namespace std;

// Swap Function Using Poiners

void swap(int *ptr1, int *ptr2)
{
    int temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}


int main()
{
    int a = 1, b = 2;

    cout << "a Before Swaping Is: " << a << endl;
    cout << "b Before Swaping Is: " << b << endl;
    cout << endl;

    swap(&a, &b);

    cout << "a After Swaping Is: " << a << endl;
    cout << "b After Swaping Is: " << b << endl;
    cout << endl;
    return 0;
}