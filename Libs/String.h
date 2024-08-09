#pragma once
#include <string>
#include <iostream>
#include <cctype>
using namespace std;

namespace StringLib
{
    // static to be call without object
    string toUpper(string str)
    {
        string result = "";
        for (int i = 0; i < str.length(); i++)
        {
            result += toupper(str[i]);
        }
        return result;
    }

    string reverseString(string str)
    {
        string reversed = "";

        for(int i = str.length() - 1; i >= 0; i--)
            reversed += str[i];

        return reversed;
    }

    string stringRepeat(string str, int r = 2, string sep = ", ", bool showEnd = false)
    {
        string result = "";
        for(int i = 0; i < r; i++)
        {
            result += str;
            if(!(i + 1 == r))
                result += sep;
        }

        if(showEnd)
            result += sep;

        return result;
    }

    string trimString(string str, string direction = "All", char ch = ' ')
    {
        string result = "";
        int firstCharsCount = 0;
        int lastCharsCount = 0;

        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == ch)
            {
                firstCharsCount++;
            }
            else
            {
                break;
            }
        }
        for(int i = str.length() - 1; i > 0; i--)
        {
            if(str[i] == ch)
            {
                lastCharsCount++;
            }
            else
            {
                break;
            }
        }

        if(direction == "Left")
        {
            for(int i = firstCharsCount; i < str.length(); i++)
            {
                result += str[i];
            }
        }
        else if(direction == "Right")
        {
            for(int i = 0; i < str.length() - lastCharsCount; i++)
            {
                result += str[i];
            }
        }
        else if(direction == "All")
        {
            for(int i = firstCharsCount; i < str.length() - lastCharsCount; i++)
            {
                result += str[i];
            }
        }

        cout << firstCharsCount << endl;
        cout << lastCharsCount << endl;

        return result;
    }

    short length(string str)
    {
        int result = 0;

        for(int i = 0; i < str.length(); i++)
        {
            result++;
        }

        return result;
    }

    string subString(string str, int start = 0, int end = 10, bool incEnd = true, bool countSpace = true)
    {
        string result;

        for(int i = start; incEnd ? i <= end : i < end; i++)
        {
            if(!countSpace && str[i] == ' ')
            {
                end++;
            }
            result += str[i];
        }

        return result;
    }

    string cleanString(string str, bool keepnumber = true)
    {
        string result = "";
        for(char c : str)
        {
            if(c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
            {
                result += c;
            }
            else if(keepnumber && c >= '0' && c <= '9')
            {
                result += c;
            }
        }
        return result;
    }

    short countWords(string str)
    {
        short count = 0;

        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == ' ')
                count++;
        }
        count++;
        return count;
    }

}
