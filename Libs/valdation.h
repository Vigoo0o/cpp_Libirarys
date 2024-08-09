#pragma once
#include <iostream>
#include <string>
#include <limits>
using namespace std;


namespace valdationLib
{
    int readNumber(string massage = "Enter Number: ")
    {
        int num = 0;

        cout << massage;
        cin >> num;

        while (cin.fail())
        {
	        // used to reset any error flags in the input stream
            cin.clear();
            //Extracts characters from the input sequence and discards them
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid number, Enter a valid number: ";
            cin >> num;
        }

        return num;
    }

    string readString(string massage = "Enter: ")
    {
        string str = "";

        cout << massage;
        getline(cin, str);

        while (cin.fail())
        {
	        // used to reset any error flags in the input stream
            cin.clear();
            //Extracts characters from the input sequence and discards them
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid number, Enter a valid number: ";
            cin >> str;
        }

        return str;
    }
}
