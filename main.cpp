// To Tist Functions

#include <iostream>
#include <string>
#include <vector>

#include "./Libs/array.h"
#include "./Libs/IO.h"
#include "./Libs/math.h"
#include "./Libs/String.h"
#include "./Libs/Utility.h"
#include "./Libs/valdation.h"
#include "./Libs/file.h"

using namespace std;

// 47 --> Stop in

struct stClient
{
    string accountNumber;
    string binCode;
    string name;
    string phoneNumber;
    double accountBalance;
};

string convertRecordToLine(stClient client, string separetor)
{
    string lineRecord = "";

    lineRecord += client.accountNumber + separetor;
    lineRecord += client.binCode + separetor;
    lineRecord += client.name + separetor;
    lineRecord += client.phoneNumber + separetor;
    lineRecord += to_string(client.accountBalance);

    return lineRecord;
}

stClient convertLineRecordToRecord(string lineRecord)
{
    stClient result;
    vector<string> record = StringLib::split(lineRecord, "##");

    result.accountNumber = record[0];
    result.binCode = record[1];
    result.name = record[2];
    result.phoneNumber = record[3];
    result.accountBalance = stod(record[4]);

    return result;
}

int main()
{
    stClient client;
    client.accountNumber = "A150";
    client.binCode = "1234";
    client.name = "Tarek Ashraf";
    client.phoneNumber = "+201113423481";
    client.accountBalance = 5000;

    string lineRecord = convertRecordToLine(client, "##");

    stClient client1;

    client1 = convertLineRecordToRecord(lineRecord);

    cout << client1.accountNumber << endl;
    cout << client1.binCode << endl;
    cout << client1.name << endl;
    cout << client1.phoneNumber << endl;
    cout << client1.accountBalance << endl;

    return 0;
}