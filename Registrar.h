#ifndef REGISTRAR_H
#define REGISTRAR_H

#include <vector>
#include <iostream>

#include "Window.h"
#include "GenQueue.h"
#include "FileProcessor.h"

using namespace std;

class Registrar{

    public:
        Registrar();
        Registrar(int totalWindows);
        ~Registrar();

        void simulate(vector<Student> s);

        bool windowsIdle();

        void totalWindows();
        void totalStudents();






        void printStatistics(double meanStudent, double medianStudent, int longestStudent, int numStudentsOverTen, 
                            double meanWindow, int longestWindow, int numWindowsOverFive);

        double studentMean();
        double studentMedian();
        int longestStudentWaitTime();
        int overTenMinutes();
        double windowMean();
        int longestWindowIdleTime();
        int windowOverFiveMinutes();

    private:

        vector<Student> *students;
        vector<Window> *registrar;

        GenQueue<Student> *studentLine;

        int time;

        int *waitTimes;
        int *idleTimes;
        int numStudents;
        int numWindows;


};


#endif
// array full of all wait times