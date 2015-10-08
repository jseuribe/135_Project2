#ifndef LOG_H
#define LOG_H

//Class empLog stores the values of iD, date, start and end Times, along with the total
//elapsed time worked in that specific date.
class empLog
{
private:
    std::string iD;
    std::string date;
    double startTime;
    double endTime;
    double elapsedTime;
    void setElapsedTime();//calculates when endTime is received, total elapsed time from start to finish.
public:
    std::string getID();//returns member value iD
    std::string getDate();//returns member value date
    double getStartTime();//returns member value startTime
    double getEndTime();//returns member value endTime
    void setID(std::string iD);//sets to the object the value in the argument to iD.
    void setDate(std::string date);//sets to the object the value in the argument to date
    void setStartTime(double startTime);//sets to the object the value in the argument to startTime
    void setEndTime(double endTime);//sets to the object in the value in the argument to endTime
    void displayID();//displays the iD
    void displayDate();//displays the date of the log
    void displayStart();//displays startTime
    void displayEnd();//displays endTime
    void displayElapsedTime();//displays elapsed time
    double returnElapsedTime();//returns elapsed time.
};

#endif // LOG_H
