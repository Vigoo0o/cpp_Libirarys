#pragma once
#include <iostream>
using namespace std;

namespace IOLib
{
    void PrintResult(int Result)
    {
        cout << Result << endl;
    }

    void PrintResult(float Result)
    {
        cout << Result << endl;
    }

    void PrintResult(double Result)
    {
        cout << Result << endl;
    }

    void PrintResult(string Result)
    {
        cout << Result << endl;
    }

    void PrintResult(char Result)
    {
        cout << Result << endl;
    }

    string ReadString(string Massage = "Please Enter String: ")
    {
        string str = "";

        cout << Massage;
        cin >> str;

        return str;
    }

    float ReadPossitveNumber(string Massage)
    {
        float Number = 0;

        do
        {
            cout << Massage;
            cin >> Number;
        } while (Number <= 0);

        return Number;
    }

    int ReadNumber(string massage)
    {
        int Number = 0;

        cout << massage + ": ";
        cin >> Number;

        return Number;
    }

    string readString(string massage = "Enter String:\n")
    {
        string str;

        cout << massage;
        getline(cin, str);

        return str;
    }

}
