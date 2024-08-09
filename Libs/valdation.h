#pragma once
#include <iostream>
#include <string>
#include <limits>
using namespace std;


namespace valdationLib
{
    int readNumber(string massage = "Enter Number: ")
    {
        int number = 0;

        cout << massage;
        cin >> number;

        while (cin.fail())
        {
            cin.clear();

            //Extracts characters from the input sequence and discards them
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid number, Enter a valid number: ";
            cin >> number;
        }

        return number;
    }
}