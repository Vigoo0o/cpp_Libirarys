#pragma once
#include <string>
#include <iostream>
#include <cctype>
using namespace std;

namespace StringLib
{

    string reverseString(string str)
    {
        string reversed = "";

        for (int i = str.length() - 1; i >= 0; i--)
            reversed += str[i];

        return reversed;
    }

    string stringRepeat(string str, int r = 2, string sep = ", ", bool showEnd = false)
    {
        string result = "";
        for (int i = 0; i < r; i++)
        {
            result += str;
            if (!(i + 1 == r))
                result += sep;
        }

        if (showEnd)
            result += sep;

        return result;
    }

    string trimString(string str, string direction = "All", char ch = ' ')
    {
        string result = "";
        int firstCharsCount = 0;
        int lastCharsCount = 0;

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == ch)
            {
                firstCharsCount++;
            }
            else
            {
                break;
            }
        }
        for (int i = str.length() - 1; i > 0; i--)
        {
            if (str[i] == ch)
            {
                lastCharsCount++;
            }
            else
            {
                break;
            }
        }

        if (direction == "Left")
        {
            for (int i = firstCharsCount; i < str.length(); i++)
            {
                result += str[i];
            }
        }
        else if (direction == "Right")
        {
            for (int i = 0; i < str.length() - lastCharsCount; i++)
            {
                result += str[i];
            }
        }
        else if (direction == "All")
        {
            for (int i = firstCharsCount; i < str.length() - lastCharsCount; i++)
            {
                result += str[i];
            }
        }

        cout << firstCharsCount << endl;
        cout << lastCharsCount << endl;

        return result;
    }

    string subString(string str, int start = 0, int end = 10, bool incEnd = true, bool countSpace = true)
    {
        string result;

        for (int i = start; incEnd ? i <= end : i < end; i++)
        {
            if (!countSpace && str[i] == ' ')
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
        for (char c : str)
        {
            if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
            {
                result += c;
            }
            else if (keepnumber && c >= '0' && c <= '9')
            {
                result += c;
            }
        }
        return result;
    }

    short countWords(string str)
    {
        short count = 0;

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == ' ')
                count++;
        }
        count++;
        return count;
    }

    void printFirstLetterOfEachword(string str)
    {
        bool isFirstLetter = true;

        for (short i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ' && isFirstLetter)
            {
                cout << str[i] << endl;
            }
            isFirstLetter = (str[i] == ' ' ? true : false);
        }
    }

    bool isUpper(char c)
    {
        if (int(c) >= 65 && int(c) <= 90)
        {
            return true;
        }
        return false;
    }

    bool isLower(char c)
    {
        if (int(c) >= 97 && int(c) <= 122)
        {
            return true;
        }
        return false;
    }

    string upperFirstLetterOfEachWordASCII(string str)
    {
        bool isFirstLetter = true;

        for (short i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ' && isFirstLetter)
            {
                // Because if it is already upper don't change it
                if (isLower(str[i]))
                {
                    str[i] = char(str[i] - 32);
                }
            }
            isFirstLetter = (str[i] == ' ' ? true : false);
        }

        return str;
    }

    string lowerFirstLetterOfEachWordASCII(string str)
    {
        bool isFirstLetter = true;

        for (short i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ' && isFirstLetter)
            {
                // Because if it is already upper don't change it
                if (isUpper(str[i]))
                {
                    str[i] = char(str[i] + 32);
                }
            }
            isFirstLetter = (str[i] == ' ' ? true : false);
        }

        return str;
    }

    string toUpper(string str)
    {
        for (short i = 0; i < str.length(); i++)
        {
            if (isLower(str[i]))
            {
                str[i] = char(str[i] - 32);
            }
        }
        return str;
    }

    string toLower(string str)
    {
        for (short i = 0; i < str.length(); i++)
        {
            if (isUpper(str[i]))
            {
                str[i] = char(str[i] + 32);
            }
        }

        return str;
    }

    bool isPalindrom(string str)
    {
        string strReverse = reverseString(str);
        return toLower(strReverse) == toLower(str) ? true : false;
    }

    char invertLetterCase(char c)
    {
        if (isUpper(c))
            return char(c + 32);
        else if (isLower(c))
            return char(c - 32);
        else
            return c;
    }

    string invertCase(string str)
    {
        for (short i = 0; i < str.length(); i++)
        {
            str[i] = invertLetterCase(str[i]);
        }

        return str;
    }

    short length(string str)
    {
        short counter = 0;

        for (char &c : str)
        {
            counter++;
        }

        return counter;
    }

    short lengthOfCapitalLetters(string str)
    {
        short counter = 0;

        for (char &c : str)
        {
            if (isUpper(char(c)))
            {
                counter++;
            }
        }

        return counter;
    }

    short lengthOfSmallLetters(string str)
    {
        short counter = 0;

        for (char &c : str)
        {
            if (isLower(char(c)))
            {
                counter++;
            }
        }

        return counter;
    }

    short countCharExist(string str, char c)
    {
        short counter = 0;

        for (const char &ch : str)
        {
            if (ch == c)
                counter++;
        }

        return counter;
    }
}
