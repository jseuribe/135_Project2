#ifndef LOGMGMT_H
#define LOGMGMT_H

//class logmgmt is a class designed to handle an array of objects empLog
//it can fill itself, display any index's contents, and check if an ID exists within itself

class logmgmt
{
private:
    static const int maxLength = 500;
    empLog LogArray[maxLength];
    int length;

public:
    //Fills the index instance of the array with the arguments given to the member function
    void fillLogs(int index, std::string iD, std::string date, double startTime, double endTime);
    //displays the index's contents
    void displayThisLog(int index);
    //sets the max length of this object
    void setLength(int length);
    //searches for the log with the given iD argument
    void searchForLogs(std::string iD);
    //returns total hours worked for an ID number
    void returnTotalHoursWorked(std::string iD);
    //checks if the id exists.
    int checkExistingID(std::string iD);

};

#endif // LOGMGMT_H


