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

    void loadDataFromFileToVector(string filePath, vector<string> &vFile)
    {
        fstream file;
        file.open(filePath, ios::in);

        if(file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                vFile.push_back(line);
            }
            file.close();
        }
    }
}