#pragma once
#include <iostream>
#include <fstream>

namespace fileLib
{
    // Print File Content
    void printFileContent(string filePath)
    {
        fstream file;
        file.open(filePath, ios::in);

        if(file.is_open())
        {
            string line;

            while (getline(file, line))
            {
                cout << line << endl;
            }
            file.close();
        }
    }

    // Load Data From File To Vector
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

    // Save Vector To File
    void saveVectorToFile(string filePath, vector<string> vFile)
    {
        fstream file;
        file.open(filePath, ios::out);

        if(file.is_open())
        {
            for(const string &line : vFile)
            {
                if(line != "")
                    file << line << "\n";
            }
            file.close();
        }
    }

    // Delete item from file
    void deleteRecordFromFile(string filePath, string record)
    {
        vector<string> fileContent;
        loadDataFromFileToVector(filePath, fileContent);

        for(string &line : fileContent)
        {
            if(line == record)
                line = "";
        }

        saveVectorToFile(filePath, fileContent);
    }

}
