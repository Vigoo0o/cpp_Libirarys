#include <iostream>
#include <math.h>
#include "check_number.h"
using namespace std;
using namespace enNumberLib;
#pragma once

namespace MathLib
{
    bool validateNumberInRange(int number , int from = 0, int to = 10)
    {
        return (number >= from && number <= to);
    }

    int PowOfNumber(int Number, int Pow)
    {
        if(Pow == 0)
        {
            return 1;
        }

        int P = 1;

        for(int i = 0; i < Pow; i++)
        {
            P = P * Number;
        }

        return P;
    }

    int GetNumberInRange(int From, int To, string massage = "Enter The Number: ")
    {
        int Number = 0;

        do
        {
            cout << massage << ": ";
            cin >> Number;
        } while (Number < From || Number > To);
        
        return Number;
    }

    enPrimeNotPrime CheckPrime(int Number)
    {
        
        int M = round(Number / 2);

        for(int i = 2; i <= M; i++)
        {
            if(Number % i == 0)
                return enPrimeNotPrime::NotPrime;
        }

        return enPrimeNotPrime::Prime;
    }

    enPerfectOrNot CheckIsPerfect(int Number)
    {
        int Sum = 0;

        for(int i = 1; i < Number; i++)
        {
            if(Number % i == 0)
            {
                Sum += i;
            }
        }
        return Sum == Number ? enPerfectOrNot::Perfect : enPerfectOrNot::NotPerfect;
    }

    int CountDigitOfNumberFrequency(int Number, int Digit)
    {
        int Remender = 0, Count = 0;
        
        while (Number > 0)
        {
            Remender = Number % 10;

            if(Remender == Digit)
                Count++;

            Number = Number / 10;
        }

        return Count;
    }

    void PrintAllDigitsFrequency(int Number)
    {

        for(int i = 0; i < 10; i++)
        {
            short DigitFrequency = 0;
            DigitFrequency = CountDigitOfNumberFrequency(Number, i);

            if(DigitFrequency > 0)
            {
                cout << "Digit " << i << " Frequency Is: " << DigitFrequency << " Time(s)" << endl;
            }
        }
    }

    int ReversedNumber(int Number)
    {
        int Reverse = 0, LastDigit = 0;

        
        while (Number > 0)
        {
            LastDigit = Number % 10;
            Reverse = (Reverse * 10) + LastDigit;
            Number = Number / 10;
        }

        return Reverse;
    }

    void PrintDigit(int Number)
    {
        int Remender = 0;

        
        while (Number > 0)
        {
            Remender = Number % 10;
            Number = Number / 10;
            cout << Remender << endl;
        }
    }

    bool IsPalindromNumber(int Number)
    {
        return Number == ReversedNumber(Number);
    }

    void PrintInvertedNumberPattern(int Number)
    {
        for(int i = Number; i >= 1; i--)
        {
            for(int j = 1; j <= i; j++)
            {
                cout << i;
            }
            cout << endl;
        }
    }

    void PrintNumberPattern(int Number)
    {
        for(int i = 1; i <= Number; i++)
        {
            for(int j = 0; j < i; j++)
            {
                cout << i;
            }
            cout << endl;
        }
    }

    void PrintInvertedLetterPattern(int Number)
    {
        for(int i = 65 + Number - 1; i >= 65; i--)
        {
            for(int j = 1; j <= Number - ( 65 + Number - 1 - i); j++)
            {
                cout << char(i);
            }
            cout << endl;
        }
    }

    void PrintLetterPattern(int Number)
    {
        for(int i = 65; i <= (65 + Number - 1); i++)
        {
            for(int j = 1; j <= (i - 65 + 1); j++)
            {
                cout << char(i);
            }
            cout << endl;
        }
    }

    int RandomNumber(int From, int To)
    {
        int RandomNumber = rand() % (To - From + 1) + From;
        return RandomNumber;
    }

    void Swap(int& A, int& B)
    {
        int Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    bool IsOdd(int Number)
    {
        return Number % 2 != 0;
    }

    bool IsEven(int Number)
    {
        return Number % 2 == 0;
    }

    // Start Biult-In Math Function -> My(NameOfFunction)

    float MyABS(float Number)
    {
        return Number > 0 ? Number : Number * -1;
    }

    float GetFractionPart(float Number)
    {
        return Number - int(Number);
    }

    int MyRound(float Number)
    {
        int IntPart = int(Number);
        float Frection = GetFractionPart(Number);

        if(MyABS(Frection) >= .5)
        {
            if(Number > 0)
                return ++IntPart;
            else
                return --IntPart;
        }
        else
        {
            return IntPart;
        } 
    }

    int MyFloor(float Number)
    {
        if(Number > 0)
            return int(Number);
        else
            return int(Number) - 1;
    }

    int MyCeil(float Number)
    {
        if(MyABS(GetFractionPart(Number)) > 0)
        {
            if(Number > 0)
                return int(Number) + 1;
            else
                return int(Number);
        }
        else
        {
            return Number;
        }
    }

    int MySqrt(float Number)
    {
        return pow(Number, 0.5);
    }
}