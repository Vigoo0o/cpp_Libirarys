// To Tist Functions

#include <iostream>
#include <fstream>
#include <vector>

#include "./Libs/array.h"
#include "./Libs/IO.h"
#include "./Libs/math.h"
#include "./Libs/String.h"
#include "./Libs/Utility.h"
#include "./Libs/valdation.h"
#include "./Libs/file.h"

using namespace std;

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

int main()
{
    vector<string> vFile;
    loadDataFromFileToVector("test", vFile);

    for(const string &line : vFile)
    {
        cout << line << endl;
    }
    return 0;
}