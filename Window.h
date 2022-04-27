#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>

#include "Student.h"
#include "GenQueue.h"

using namespace std;

class Window{

    public:
        
        Window(); //default constructor
        ~Window(); //destructor

        //getters
        Student getStudent();
        int getIdleTime();

        //setters
        void setStudent(Student s);
        void setIdleTime(int t);

        bool windowOccupied();

        bool operator == (Window *window);
        bool operator != (Window *window);


        bool changeTime();

    private:

        Student *student;

        int idleTime;
        bool isOccupied;
        bool isIdle;

};

#endif







//Window keeps track of
// a student
// if its occupied
// idle time

//keeps track of
// waiting time for students
// idle time for the windows