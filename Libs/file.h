#pragma once
#include <iostream>
#include <fstream>

namespace fileLib
{
    void printFileContent(string path)
    {
        fstream file;
        file.open(path, ios::in); // in --> Read Mode

        if (file.is_open())
        {
            string line;
            int lineCount = 0;

            while (getline(file, line))
            {
                lineCount++;
                cout << "[" << lineCount << "]: " << line << endl;
            }
            file.close();
        }
    }
}