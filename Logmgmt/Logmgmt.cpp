#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#include "log.h"
#include "Logmgmt.h"

void logmgmt::fillLogs(int index, string iD, string date, double startTime, double endTime)
{
    this->LogArray[index].setID(iD);
    this->LogArray[index].setDate(date);
    this->LogArray[index].setStartTime(startTime);
    this->LogArray[index].setEndTime(endTime);
}

void logmgmt::displayThisLog(int index)
{
    this->LogArray[index].displayID();
    this->LogArray[index].displayDate();
    this->LogArray[index].displayStart();
    this->LogArray[index].displayEnd();
    this->LogArray[index].displayElapsedTime();
    cout << "_________________________________" << endl;
}

void logmgmt::setLength(int length)
{
    this->length = length;
}


void logmgmt::searchForLogs(string iD)
{
    int counter = 0;
    string currentiD = "null";

    for(int i = 0; i < this->length; i++)
    {
        currentiD = this->LogArray[i].getID();
        //cout << iD << endl;
        //cout << i << endl;

        if(currentiD == iD)
        {
            LogArray[i].displayID();
            LogArray[i].displayDate();
            LogArray[i].displayStart();
            LogArray[i].displayEnd();
            LogArray[i].displayElapsedTime();
            cout << " Hours";
            cout << endl;
            cout << "________________________________________" << endl;

            counter++;

        }

    }

    if(counter == 0)
        cout << "No logs exist for employee ID " << iD << endl;
}

void logmgmt::returnTotalHoursWorked(string iD)
{
    double sum = 0;
    int counter = 0;
    string currentiD = "null";
    for(int i = 0; i < this->length; i++)
    {
        currentiD = this->LogArray[i].getID();


        if(currentiD == iD)
        {
            sum += this->LogArray[i].returnElapsedTime();
            counter++;

        }

    }

    if(counter == 0)
        return;

    cout << "Total hours worked: " << sum << endl;
    cout << "________________________________________" << endl;
}

int logmgmt::checkExistingID(string iD)
{
    string checker = "null";

    for(int i = 0; i < this->length; i++)
    {
        checker = LogArray[i].getID();

        if(checker == iD)
        {
            return 1;
        }
    }
    return 0;
}

