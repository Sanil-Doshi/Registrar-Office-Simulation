#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student{

    public:

        Student(); //default constructor
        Student(int waitTime, int arrivalTime); //overloaded constructor
        ~Student(); //destructor

        //getters
        int getWaitTime();
        int getArrivalTime();
        int getTotalTime();
        int getTimeLeft();

        //setters
        void setWaitTime(int t);
        void setArrivalTime(int t);
        void setTotalTime(int t);
        void setTimeLeft(int t);

        bool operator == (Student *student);
        bool operator != (Student *student);

    private:

        int arrivalTime; // time arrived
        int totalTime; // time at window
        int waitTime; // time in line
        int timeLeft; // time left in the window


};

#endif
//Student keeps track of
// each student wait time and arrival time
