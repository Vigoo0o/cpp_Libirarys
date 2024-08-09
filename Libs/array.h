#pragma once
#include <iostream>
#include "./math.h"
#include "./Utility.h"
#include "./IO.h"
using namespace std;

namespace ArrayLib
{
    void ReadArray(int arr[], int& Length)
    {
        cout << "Enter Number Of Element: ";
        cin >> Length;

        cout << "\nEnter Array Element:\n";
        for(int i = 0; i < Length; i++)
        {
            cout << "Element [" << i+1 << "]: ";
            cin >> arr[i];
        }
        cout << endl;
    }

    void PrintArray(int Arr[], int Length, bool InOneLine = false, string Massage = "Array Elements: ")
    {
        cout << endl;
        cout << Massage << endl;
        for(int i = 0; i < Length; i++)
        {
            if(InOneLine)
            {
                cout << Arr[i];
                if(i != Length - 1)
                {
                    cout << ", ";
                }
            }
            else
            {
                cout << Arr[i] << endl;
            }
        }
        cout << endl;
        cout << endl;
    }

    int TimesRepeted(int Arr[], int Target, int Length)
    {
        int Counter = 0;

        for(int i = 0; i < Length; i++)
        {
            if(Arr[i] == Target)
                Counter++;
        }

        return Counter;
    }

    void FillArrayWithRandomNumbers(int Arr[], int Length,int From = 1,int To = 10)
    {
        for(int i = 0; i < Length; i++)
            Arr[i] = MathLib::RandomNumber(From, To);
        cout << endl;
    }

    int MaxNumberInArray(int Arr[], int Length)
    {
        int MaxNumber = Arr[0];
        for(int i = 1; i < Length; i++)
        {
            if(MaxNumber < Arr[i])
                MaxNumber = Arr[i];
        }
        return MaxNumber;
    }

    int MinNumberInArray(int Arr[], int Length)
    {
        int MaxNumber = Arr[0];
        for(int i = 1; i < Length; i++)
        {
            if(MaxNumber > Arr[i])
                MaxNumber = Arr[i];
        }
        return MaxNumber;
    }

    int SumArray(int Arr[], int Length)
    {
        int Sum = 0;
        
        for(int i = 0; i < Length; i++)
            Sum += Arr[i];

        return Sum;
    }

    float ArrayAvradge(int Arr[], int Length)
    {
        return (float)SumArray(Arr, Length) / Length;
    }

    void CopyArray(int ArrSource[], int ArrDestination[], int Length)
    {
        for(int i = 0; i < Length; i++)
            ArrDestination[i] = ArrSource[i];
    }

    void CopyPrimeNumbersInArray(int ArrSource[], int ArrDestination[], int Length, int& Length2)
    {
        int Counter = 0;
        for(int i = 0; i < Length; i++)
        {
            if(MathLib::CheckPrime(ArrSource[i]))
            {
                ArrDestination[Counter] = ArrSource[i];
                Counter++;
            }
        }
        Length2 = --Counter;
    }

    void SumOf2Arrayss(int SumArr[], int Arr1[], int Arr2[], int Length)
    {
        for(int i = 0; i < Length; i++)
            SumArr[i] = Arr1[i] + Arr2[i];
    }

    bool IsNumberInArray(int Arr[], int Length, int Target)
    {
        for(int i = 0; i < Length; i++)
        {
            if(Arr[i] == Target)
                return true;
        }
        return false;
    }

    void FillArrayWithOrder(int Arr[], int Length)
    {
        for(int i = 0; i < Length; i++)
            Arr[i] = i + 1;
        cout << endl;
    }

    void ShuffleArray(int Arr[], int Length)
    {
        for(int i = 0; i < Length; i++)
            MathLib::Swap(Arr[MathLib::RandomNumber(1, Length) - 1], Arr[MathLib::RandomNumber(1, Length) - 1]);
    }

    void ReversedArray(int ArrSource[], int ArrDestination[], int Length)
    {
        int Counter = Length;
        for(int i = 0; i < Length; i++)
        {
            ArrDestination[i] = ArrSource[Counter - 1];
            Counter--;
        }
    }

    void FillArrayWithKeys(string Arr[], int Length)
    {
        for(int i = 0; i < Length; i++)
        {
            Arr[i] = UtilityLib::GenerateKey();
        }
    }

    short FindNumberPossitionInArray(int Number, int Arr[], int Length)
    {
        for(int i = 0; i < Length; i++)
        {   
            if(Arr[i] == Number)
                return i;
        }
        return -1;
    }

    bool IsNumberInArray(int Number, int Arr[], int Length)
    {
        for(int i = 0; i < Length; i++)
        {
            if(Arr[i] == Number)
                return true;
        }
        return false;
    }

    // For Add One Item
    void AddArrayElement(int Element, int Arr[], int& Length)
    {
        Length++;
        Arr[Length - 1] = Element;
    }

    // For Add A Lot Of Items
    void InputUserNumbersInArray(int Arr[], int& Length)
    {
        bool AddMore = true;
        do
        {
            AddArrayElement(IOLib::ReadPossitveNumber("Please Enter A Number "), Arr, Length);

            cout << "\nDo You Want To Add More Element? [0]NO, [1]Yes? ";
            cin >> AddMore;
        } while (AddMore);
        
    }

    void CopyArrayUsingAddArrayElement(int ArrSorce[], int ArrDestination[], int ArrSorceLength, int ArrDestinationLength)
    {
        for(int i = 0; i < ArrSorceLength; i++)
            AddArrayElement(ArrSorce[i], ArrDestination, ArrDestinationLength);
    }

    void CopyOddNumbers(int ArrSorce[], int ArrDestenation[], int SorceLength, int& DestenationLength)
    {
        for(int i = 0; i < SorceLength; i++)
        {
            if(MathLib::IsOdd(ArrSorce[i]))
            {
                AddArrayElement(ArrSorce[i], ArrDestenation, DestenationLength);
            }

        }
    }

    void CopyPrimeNumbers(int ArrSorce[], int ArrDestenation[], int SorceLength, int& DestenationLength)
    {
        for(int i = 0; i < SorceLength; i++)
        {
            if(MathLib::CheckPrime(ArrSorce[i]) == enPrimeNotPrime::Prime)
            {
                AddArrayElement(ArrSorce[i], ArrDestenation, DestenationLength);
            }

        }
    }

    void CopyDistinctNumbers(int ArrSorce[], int ArrDestenation[], int SorceLength, int& DestenationLength)
    {
        for(int i = 0; i < SorceLength; i++)
        {
            if(!(IsNumberInArray(ArrDestenation, DestenationLength, ArrSorce[i])))
            {
                AddArrayElement(ArrSorce[i], ArrDestenation, DestenationLength);
            }
        }
    }

    bool IsPalindromArray(int Arr[], int Length)
    {

        for(int i = 0; i < Length; i++)
        {
            if(Arr[i] != Arr[Length - i - 1])
                return false;
        }
        return true;
    }

    int OddCount(int Arr[], int Length)
    {
        int Counter = 0;
        for(int i = 0; i < Length; i++)
            if(MathLib::IsOdd(Arr[i])) Counter++;

        return Counter;
    }

    int EvenCount(int Arr[], int Length)
    {
        int Counter = 0;
        for(int i = 0; i < Length; i++)
            if(MathLib::IsEven(Arr[i])) Counter++;

        return Counter;
    }

    int PossitiveCount(int Arr[], int Length)
    {
        int Counter = 0;
        for(int i = 0; i < Length; i++)
            if(Arr[i] >= 0) Counter++;

        return Counter;
    }

    int NegativeCount(int Arr[], int Length)
    {
        int Counter = 0;
        for(int i = 0; i < Length; i++)
            if(Arr[i] < 0) Counter++;

        return Counter;
    }
}