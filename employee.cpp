#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "employee.h"

string Employee::getID()
{
    return this->iD;
}
string Employee::getName()
{
    return (this->name);
}

string Employee::getDOB()
{
    return (this->dOB);
}

string Employee::getSS()
{
    return (this->socialSecurity);
}

string Employee::getDepartment()
{
    return (this->department);
}

string Employee::getPosition()
{
    return (this->position);
}

// SETTERS BEGIN HERE

void Employee::setID(string number)
{
    this->iD = number;
}

void Employee::setName(string name)
{
    this->name = name;
}

void Employee::setdOB(string dOB)
{
    this->dOB = dOB;
}

void Employee::setSS(string socialSecurity)
{
    this->socialSecurity = socialSecurity;
}

void Employee::setDepartment(string department)
{
    this->department = department;
}

void Employee::setPosition(string position)
{
    this->position = position;
}

//displayers

void Employee::displayID()
{
    cout << "ID: " << this->iD << endl;
}

void Employee::displayName()
{
    cout << "Name: " << this->name << endl;
}
void Employee::displaydOB()
{
    cout << "DOB: " << this->dOB << endl;
}

void Employee::displaySS()
{
    cout << "Social Security Number: " << this->socialSecurity << endl;
}

void Employee::displayDepartment()
{
    cout << "Department: " << this->department << endl;
}

void Employee::displayPosition()
{
    cout << "Position: " << this->position << endl;
}
