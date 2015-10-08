#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;
#include "log.h"

string empLog::getID()
{
    return (this->iD);
}

string empLog::getDate()
{
    return (this->date);
}

double empLog::getStartTime()
{
    return (this->startTime);
}

double empLog::getEndTime()
{
    return (this->endTime);
}

void empLog::setID(string iD)
{
    this->iD = iD;
}

void empLog::setDate(string date)
{
    this->date = date;
}

void empLog::setStartTime(double startTime)
{
    this->startTime = startTime;
}

void empLog::setEndTime(double endTime)
{
    this->endTime = endTime;
    setElapsedTime();

}

void empLog::displayID()
{
    cout << this->iD << " ";
}

void empLog::displayDate()
{
    cout << this->date << " ";
}

void empLog::displayStart()
{
    cout << this->startTime << " ";
}

void empLog::displayEnd()
{
    cout << this->endTime << " ";
}

void empLog::displayElapsedTime()
{
    cout << this->elapsedTime;
}

void empLog::setElapsedTime()
{

    double time;

    time = ((int((this->endTime/100) - (this->startTime/100)))) +
    abs(((int(this->endTime/100) - this->endTime/100)/.6)+((int(this->startTime/100) -
    this->startTime/100)/.6));

    if(time < 0)
        time += 24;

    this->elapsedTime = time;

}

double empLog::returnElapsedTime()
{
    return this->elapsedTime;
}


