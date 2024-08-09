// To Tist Functions

#include <iostream>

#include "./Libs/array.h"
#include "./Libs/IO.h"
#include "./Libs/math.h"
#include "./Libs/String.h"
#include "./Libs/Utility.h"
#include "./Libs/valdation.h"

using namespace std;

int main()
{
    string name = valdationLib::readString("Enter Your Name: ");
    cout << "\nYour name is: " << name << "\n\n";
    return 0;
}