#ifndef EMPLOYEE_H
#define EMPLOYEE_H

//Class employee contains an ID, name, dOB, socialsecurity number, the employee's department and their position within the department.
//Various member functions exist to set the member values, return the member values, and display the membervalues
class Employee
{
private:
   std::string iD;
   std::string name;
   std::string dOB;
   std::string socialSecurity;
   std::string department;
   std::string position;
public:
    std::string getID();//Simply returns the integer value within variable iD.
    std::string getName();//Returns the string object of name.
    std::string getDOB();//Returns the string object of dOB
    std::string getSS();//Returns the string object of socialSecurity
    std::string getDepartment();//Returns the string value of the member department
    std::string getPosition();//returns the string value of the member position
    void setID(std::string number);//will set the calling object's id number to whatever is used as the parameter
    void setName(std::string name);//will set the calling object's name member to whatever is used as the parameter.
    void setdOB(std::string dOB);//will set the dOB to whatever the calling object's parameter is.
    void setSS(std::string socialSecurity);//will set the calling object's social security member to whatever is used as the parameter
    void setDepartment(std::string department);//will set the object's member value of department to the parameter value
    void setPosition(std::string position);//will set the object's member value of position to whatever the parameter value is
    void displayID();//displays ID: iD
    void displayName();//displays Name: name
    void displaydOB();//displays DOB: dOB
    void displaySS();//displays Social Security Number: socialSecurity
    void displayDepartment();//displays Department: department
    void displayPosition();//displays Position: position.

};

#endif // EMPLOYEE_H
