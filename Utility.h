#pragma once
#include <iostream>
#include "./check_number.h"
#include "./math.h"
using namespace std;
using namespace enNumberLib;

namespace UtilityLib
{

    float DaysToWeek(float Dayes)
    {
        return Dayes / 7;
    }

    bool GuessPassword(string Password)
    {
        string Word = "";
        int Counter = 0;

        for(int i = 65; i <= 90; i++)
        {
            for(int j = 65; j <= 90; j++)
            {
                for(int k = 65; k <= 90; k++)
                {
                    Counter++;

                    Word += char(i);
                    Word += char(j);
                    Word += char(k);

                    cout << "\nTrial" << " [" << Counter << "]: " << Word << endl;
                    
                    if(Word == Password)
                    {
                        cout << "\nPassword Is: " << Word << endl;
                        cout << "Found After "<< "[" << Counter << "] " << "Trial(s)" << endl;
                        return true;
                    }
                    Word = "";
                }
            }
        }
        cout << "\nPassword Not Found!" << endl;
        return false;
    }

    void PrintWordsFromAAAtoZZZ()
    {
        string Word = "";

        for(int i = 65; i <= 90; i++)
        {
            for(int j = 65; j <= 90; j++)
            {
                for(int k = 65; k <= 90; k++)
                {
                    Word += char(i);
                    Word += char(j);
                    Word += char(k);

                    cout << Word << endl;
                    Word = "";
                }
            }
        }
    }

    string EncryptedText(string Text, short Key)
    {

        for(int i = 0; i < Text.length(); i++)
        {
            Text[i] = char((int)Text[i] + Key);
        }

        return Text;
    }

    string DecryptText(string Text, short Key)
    {

        for(int i = 0; i < Text.length(); i++)
        {
            Text[i] = char((int)Text[i] - Key);
        }

        return Text;
    }

    char GetRandomChar(enCharType CharType)
    {
        char RandomChar;

        if(CharType == enCharType::CapitalLetter)
            RandomChar = MathLib::RandomNumber(65, 90);
        else if(CharType == enCharType::SmallLetter)
            RandomChar = MathLib::RandomNumber(97, 122);
        else if(CharType == enCharType::SpicialCaracter)
            RandomChar = MathLib::RandomNumber(33, 47);
        else if(CharType == enCharType::Digit)
            RandomChar = MathLib::RandomNumber(48, 57);

        return RandomChar;
    }

    string GenerateWord(enCharType Type, int Length)
    {
        string Word = "";

        for(int i = 0; i < Length; i++)
        {
            Word += GetRandomChar(Type);
        }

        return Word;
    }

    string GenerateKey()
    {
        string Key = "";

        for(int i = 0; i < 4; i++)
        {
            Key += GenerateWord(enCharType::CapitalLetter, 4);

            if(i != 3)
                Key += "-";
        }

        return Key;
    }
};