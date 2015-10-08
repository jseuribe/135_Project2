/********************************************************************************************************************************************************
 Title: Uribe_project2.cpp
 Author: Jose Antonio Uribe
 Created: April 13, 2013
 Purpose: Utilising the classes employee, employeemgmt, log, and logmgmt, this program serves as a database interface to the files
 details.txt and timelog.txt, where the objects of employeemgmt and logmgmt obtain their values
 The user is asked to search for an employee, or their logs, update a specific employee within the object of employeemgmt Employees
 and sets to them the new user defined updates
 At the end, the user is prompted to save their changes, or discard and quit the program.
NOTE:
	ID's are assumed to be all unique!

 Build with: g++ -o project2 employee.cpp log.cpp logmgmt.cpp employeemgmt.cpp Uribe_project2main.cpp
Make sure details.txt and timelog.txt is in the same folder as the executable!
 Modifications:
********************************************************************************************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

#include "employee.h"
#include "log.h"
#include "logmgmt.h"
#include "employeemgmt.h"


void fileCheck(ifstream& file); //checks if the file has been opened succesfully
void fillEmployeeList(Employeemgmt& Employees, ifstream& file); //fills an object of Employeemgmt with the contents of a file
void fillLogList(logmgmt& Logs, ifstream& file); //files an object of type logmgmt with the contents of a file
void refillEmployeeListFile(Employeemgmt Employees);//refills a file with the contents of employees
void inputForSearch(Employeemgmt Employees, logmgmt Logs);//handles input management for searching Employees
void searchForLogs(logmgmt Logs);//handles input management for searching Logs
void newParams(Employeemgmt& Employees);//sets new parameters for the objects within Employees
void newLine();//gets rid of any unecessary characters from input


int main()
{

	//In this part, the files ifstreams are passed into functions, and saves their contents to their corresponding objects.
    ifstream details("details.txt");
    fileCheck(details);

    Employeemgmt Employees;

    fillEmployeeList(Employees, details);

    details.close();


    ifstream logFile("timelog.txt");
    fileCheck(logFile);

    logmgmt Logs;

    fillLogList(Logs, logFile);

    logFile.close();

    char option;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "~~~~~~~~~~~~~~~~~WELCOME~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "~~~~~TO ABC CORP'S DATABASE PROGRAM~~~~~~~~" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;


//Here the user is prompted to select an option. Selecting another option will result in a repeating of the prompt & main menu.
do
{
    cout << "________________________________________" << endl;
    cout << "MAIN MENU" << endl;
    cout << "What would you like to do? Enter a number please...\n";
    cout << "1) Search\n";
    cout << "2) Display logs\n";
    cout << "3) Update Information\n";
    cout << "4) Save & Quit\n";
    cout << "5) Quit without Saving.\n";

    cin >> option;
    newLine();

    switch(option)
    {
    case '1':
        inputForSearch(Employees, Logs);//input for search will bring the user to the search menu. Details are outlined within the function
        break;
    case '2':
        searchForLogs(Logs);//search for logs will bring the user to the search log menu. Details are outlined within the function.
        break;
    case '3':
        newParams(Employees);//passing the object Employees, the user is brought to the parameter update menu.
        break;
    case '4':
        refillEmployeeListFile(Employees);//if selected, will save to the file details.txt the contents of the object employee.
        break;
    case '5'://Entering this will otherwise end the program, discarding any updates done to Employees if any have been made.
        break;
    default:
        break;
    }

} while (option != '5' && option != '4');

    cout << "PROGRAM END" << endl;
    cout << "THANK YOU FOR USING ABC CORP'S DATABASE PROGRAM" << endl;
	return 0;
	//END OF PROGRAM
}

void fileCheck(ifstream& file)
//simply put, this function will check if the file is within the same directory as the executable.
//Otherwise, the program will end, prompting the changing of location of the file.
{
    if(file.fail())
    {
        cerr << "Input file could not be opened. Check if the file is in the same directory"
             << " as the executable.\n";
        exit(1);
    }
}

void fillEmployeeList(Employeemgmt& Employees, ifstream& file)
//this will fill each individual employee object within the object Employees with the contents of the file passed into the function
{

	string iD;
	int counter = 0;
	string name, dOB, socialSecurity, department, position;
    while(file >> iD)
    {
		file >> name >> socialSecurity >> dOB >> department >> position;
		Employees.fillArray(counter, iD, name, socialSecurity, dOB, department, position);
        counter++;
    }
    Employees.setLength(counter);

}

void fillLogList(logmgmt& Logs, ifstream& file)
//This program will fill the object Logs with the contents of timelog.txt
//This program will end if any time greater than 2300 is detected, and will prompt the user to remedy the situation.
{
    int counter = 0;
    string date, iD;
    double startTime, endTime;

    while(file >> iD )
    {
        file >> date >> startTime >> endTime;
	if(startTime > 2300 || endTime > 2300)
	{
	  cerr << "Error! Time(s) in the file are above 2300! Please go into timelog.txt and change these time(s)!" << endl;
	  exit(1);
	}
        Logs.fillLogs(counter, iD, date, startTime, endTime);
        counter++;
    }

    Logs.setLength(counter);
}

void refillEmployeeListFile(Employeemgmt Employees)
//This function will refill the file details.txt with the contents of the object Employees.
{
    ofstream refill("details.txt");

    int counter;
	string iD, name, dOB, socialSecurity, department, position;

	counter = Employees.returnLength();
	counter;
	for(int i = 0; i <=  counter; i++)
    {
	//Passed unto other variables are each individual data set of each object within Employees.
        iD = Employees.returnThisID(i);
        name = Employees.returnThisName(i);
        dOB = Employees.returnThisdOB(i);
        socialSecurity = Employees.returnThisSS(i);
        department = Employees.returnThisDepartment(i);
        position = Employees.returnThisPosition(i);
        if(i == counter-1)
	//The program accomodates for the end of the file here, making sure that it writes to the file only the amount of employees
	//it has been given earlier. It will avoid printing a blank line in the file so as to prevent erroneous readings in 
	//repeated uses of this program.
        {
            refill << iD << " " << name << " " << dOB << " " << socialSecurity << " " << department << " " << position;
            break;
        }
        refill << iD << " " << name << " " << dOB << " " << socialSecurity << " " << department << " " << position << endl;


    }


    refill.close();
}

void inputForSearch(Employeemgmt Employees, logmgmt Logs)
//A series of user inputs, here is the submenu that is called by case 1
{
    char query;
    string iD = "null", name, department, position;
    cout << "SEARCH MENU" << endl;
    cout << "How would you like to search? Enter the letter of the search type you wish to perform\n";
    cout << "i: ID" << endl;
    cout << "n: name" << endl;
    cout << "d: department" << endl;
    cout << "p: position" << endl;

    cin >> query;
    //The user is prompted here to enter a letter for whatever type of search the user desires.
    newLine();
    cout << endl;


    while(query != 'i' && query != 'n' && query != 'd' && query != 'p' && query != 'q')
    //A check is placed here, so as to avoid any incorrect search inputs.
    {
        cout << "Please re-enter your input with a valid character..." << endl;
        cin >> query;
        newLine();

    }

    switch(query)
    {
    case 'i':
        cout << "Enter an ID value to search" << endl;
        cin  >> iD;//The user enters the ID they wish to look up
        newLine();
        Employees.searchBasedOnID(iD, Logs);
	//the argument is passed here to retrieve any matching employees. If there are none, the user is told so
        break;                              
    case 'n':
        cout << "Enter a name to search by" << endl;
        cin >> name;//The user enters the name they wish to look up
        newLine();
        Employees.searchBasedOnName(name, Logs);
	//the argument is passed here to retrieve any matching employees. If there are none, the user is told 
        break;
    case 'd':
        cout << "Enter a department to search by" << endl;
        cin >> department;//The user enters the department they wish to look up
        newLine();
        Employees.searchBasedOnDepartment(department, Logs);
	//the argument is passed here to retrieve any matching employees. If there are none, the user is told 
        break;
    case 'p':
        cout << "Enter a position to search by" << endl;
        cin >> position;//The user enters the position they wish to look up
        newLine();
        Employees.searchBasedOnPosition(position, Logs);
//the argument is passed here to retrieve any matching employees. If there are none, the user is told 
        break;
    case 'q':
        break;
    }

    cout << "RETURNING TO MAIN MENU..." << endl;
}

void searchForLogs(logmgmt Logs)
//here the submenu for 2) search logs is contained
//It passes into it an object of type logmgmt
{
    string query = "null";
    int check = 0;

    cout << "SEARCH LOG MENU" << endl;
    cout << "Please enter an ID number for the employee you wish to search for..." << endl;
    cin >> query;//Using an ID number, the object Logs is searched for any matching logs with the same ID.
    newLine();

    cout << "________________________________________" << endl;

    check = Logs.checkExistingID(query);

    if(check == 0)
    //If the ID isn't valid, and otherwise doesn't return anything, the function call is promptly ended here.
    {
        cout << "This employee does not exist" << endl;
        return;
    }


    Logs.searchForLogs(query);
    //if the input makes it past the check before, the object Logs is checked for any matching logs.

    cout << "RETURNING TO MAIN MENU" << endl;



}

void newParams(Employeemgmt& Employees)
//New parameters handles any new changes made by the user
//It passes into it the object Employees, called by reference to save the changes made.
{
    const int MAXBIRTH = 10, MAXSS = 11, MINBIRTH = 7;
	string iD = "null";

	string newID, newName, newDOB, newSS, newDepartment, newPosition;
	int length;
	int index = -1;
	cout <<"CHANGE DATA MENU" << endl;

	cout << "Enter the ID of the employee's information you wish to update" << endl;
	cin >> iD;//The function searches by ID, so the user is asked for a valid ID.
	newLine();

	index = Employees.checkIDReal(iD);//here a value is returned, if anything but a number greater than 0, the function will end...
	//this index will be used to remember where in Employees is the ID saved to.
	if(index < 0)
	//if the ID is invalid, the function will tell the user so, and end.
	{
		cout << "This employee does not exist" << endl;
		return;
	}

	char option;
	char again;

do
{
	cout << "What parameter would you like to change for employee: " << iD << "?" << endl;
	cout << "i: ID" << endl;
	cout << "n: name" << endl;
	cout << "b: birthdate" << endl;
	cout << "s: social security" << endl;
	cout << "d: department" << endl;
	cout << "p: position" << endl;
	cin >> option;//the user is prompted to change any of these above parameters for their currently search ID.
	newLine();

	switch(option)
	{
		case 'i':
			cout << "Enter a new ID for employee: " << iD << "." << endl;
			cin >> newID;//the user enters an ID...
			newLine();
            		cout << "________________________________________" << endl;

			Employees.changeThisID(index, newID);//and passes the new ID into the matching object with the same ID.
			break;
		case 'n':
			cout << "Enter a new name for employee: " << iD << "." << endl;
			cin >> newName;
			newLine();
            		cout << "________________________________________" << endl;

			Employees.changeThisName(index, newName);
			break;
		case 'b':
			cout << "Enter a new birthdate for employee: " << iD << "." << endl;
			cin >> newDOB;//A new DOB is entered here
			length = newDOB.length();
			while (length > MAXBIRTH)
            		{//And if it isn't bigger than the maximum of 10 characters...
                		cout << "Re-enter your input; birthdate must be smaller than 9 characters" << endl;
                		cin >> newDOB;
                		length = newDOB.length();
            		}
			newLine();
            		cout << "________________________________________" << endl;
			Employees.changeThisDOB(index, newDOB);//is passed unto here.
			break;
		case 's':
			cout << "Enter a new Social Security for employee: " << iD << "." << endl;
			cin >> newSS;//A new SS is entered here.
			newLine();
			length = newSS.length();
			while (length > MAXSS)
            		{//Assuming it isn't bigger than the maximum length of 11
                		cout << "Re-enter your input; social security must contain 11 characters" << endl;
                		cin >> newSS;
                		length = newSS.length();
            		}
            		cout << "________________________________________" << endl;
			Employees.changeThisSS(index, newSS);//is passed into here.
			break;
		case 'd':
			cout << "Enter a new department for employee: " << iD << "." << endl;
			cin >> newDepartment;//The user enters a new department value
			newLine();
            		cout << "________________________________________" << endl;
			Employees.changeThisDepartment(index, newDepartment);//and passes it here
			break;
		case 'p':
			cout << "Enter a new position for employee: "  << iD << "." << endl;
			cin >> newPosition;//user enters a new position value
			newLine();
            		cout << "________________________________________" << endl;
			Employees.changeThisPosition(index, newPosition);//and passes it here.
		default:
			break;
}

	cout <<"Change another parameter? Y/y for yes" << endl;
	cin >> again;//Here the user is prompted to enter another parameter for the same employee.
    	newLine();

    if(again == 'y' || again == 'Y')
        cout << "RETURNING TO CHANGE DATA MENU" << endl;

} while (again == 'y' || again == 'Y');

    cout << "RETURNING TO MAIN MENU" << endl;
}

void newLine()
//newLine makes sure any unecessary characters are not read.
//EX: if the program asks for n, and the user enters "name name name"
//It will only read n and discard the rest.
{
    char symbol;

    do
    {
        cin.get(symbol);
    } while( symbol != '\n');
}

