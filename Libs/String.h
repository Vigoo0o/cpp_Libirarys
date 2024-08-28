#pragma once
#include <string>
#include <iostream>
#include <cctype>

#include "struct.h"
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

    short countChar(string str, char c, bool caseSensitive = true)
    {
        short counter = 0;

        for (const char &ch : str)
        {
            if (caseSensitive)
            {
                if (ch == c)
                {
                    counter++;
                }
            }
            else
            {
                if (ch == c || ch == invertLetterCase(c))
                {
                    counter++;
                }
            }
        }

        return counter;
    }

    vector<string> split(string str, string delimeter)
    {
        vector<string> result;

        short position = 0;
        string sStr;

        while ((position = str.find(delimeter)) != string::npos)
        {
            sStr = str.substr(0, position);

            result.push_back(sStr);

            str.erase(0, position + delimeter.length());
        }

        result.push_back(str);

        return result;
    }

    string trim(string str, string direction = "All")
    {
        string result = "";
        short firstLetterPos = 0;
        short lastLetterPos = 0;

        // Get Position Of First Letter
        for (short i = 0; i < str.length(); i++)
        {
            if (str[i] == ' ')
                firstLetterPos++;
            else
                break;
        }

        // Get Position Of Last Letter
        for (short i = str.length() - 1; i > 0; i--)
        {
            if (str[i] == ' ')
                lastLetterPos++;
            else
                break;
        }

        if (direction == "Left")
        {
            for (short i = firstLetterPos; i < str.length(); i++)
                result += str[i];
        }
        else if (direction == "Right")
        {
            for (short i = 0; i < str.length() - lastLetterPos; i++)
                result += str[i];
        }
        else if (direction == "All")
        {
            for (short i = firstLetterPos; i < str.length() - lastLetterPos; i++)
                result += str[i];
        }

        return result;
    }

    string joinString(vector<string> vector, string delemeer = " ")
    {
        string result = "";

        for (short i = 0; i < vector.size(); i++)
        {
            if (i != vector.size() - 1)
                result += vector[i] + delemeer;
            else
                result += vector[i];
        }

        return result;
    }

    string joinString(string arr[], short size, string delemeer = " ")
    {
        string result = "";

        for (short i = 0; i < size; i++)
        {
            if (i != size - 1)
                result += arr[i] + delemeer;
            else
                result += arr[i];
        }

        return result;
    }

    string reverseWordsInString(string str)
    {
        string result = "";
        vector<string> vStr = split(str, " ");

        vector<string>::iterator itr = vStr.end();

        while (itr != vStr.begin())
        {
            --itr;
            result += *itr + " ";
        }

        return result;
    }

    string replaceWordsInString(string str, string replace, string replaceWith, bool caseSensitive = false)
    {
        string result = "";
        vector<string> vStr = split(str, " ");

        for (short i = 0; i < vStr.size(); i++)
        {
            if (caseSensitive)
            {
                if (vStr[i] == replace)
                    vStr[i] = replaceWith;
            }
            else
            {
                if (toLower(vStr[i]) == toLower(replace))
                    vStr[i] = replaceWith;
            }
        }

        for (const string &str : vStr)
        {
            result += str + " ";
        }

        return result;
    }

    bool isPunctuation(char c)
    {
        if (c == '.' || c == '?' || c == '!' || c == ',' || c == ';' || c == ':' || c == '-' || c == '_' || c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}' || c == '\'' || c == '\"')
            return true;
        return false;
    }

    string removePunctuationInString(string str)
    {
        string result = "";

        for (const char &c : str)
        {
            if (!isPunctuation(c))
                result += c;
        }

        return result;
    }

    string convertRecordToLine(structLib::stClient client, string separetor)
    {
        string lineRecord = "";

        lineRecord += client.accountNumber + separetor;
        lineRecord += client.binCode + separetor;
        lineRecord += client.name + separetor;
        lineRecord += client.phoneNumber + separetor;
        lineRecord += to_string(client.accountBalance);

        return lineRecord;
    }
}
