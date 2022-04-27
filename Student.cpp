#include "Student.h"

Student::Student(){

    arrivalTime = 0;
    waitTime = 0;
}

Student::Student(int wait, int arrive){

    totalTime = wait;
    arrivalTime = arrive;
}

Student::~Student(){}

int Student::getWaitTime(){

    return waitTime;
}

int Student::getArrivalTime(){

    return arrivalTime;
}

int Student::getTotalTime(){

    return totalTime;
}

int Student::getTimeLeft(){

    return timeLeft;
}

void Student::setTotalTime(int t){
    totalTime = t;
}

void Student::setArrivalTime(int t){
    arrivalTime = t;
}

void Student::setWaitTime(int t){
    waitTime = t;
}

void Student::setTimeLeft(int t){
    timeLeft = t;
}

bool Student::operator == (Student *student)
{
    //Checks if the variables are the same
    if((getArrivalTime() == student->getArrivalTime()) && (getTimeLeft() == student->getTimeLeft()) && (getTotalTime() == student->getTotalTime()) && (getWaitTime() == student->getWaitTime())){
        return true;
    }
    return false;
}
bool Student::operator != (Student *student)
{
    //Checks if the variables are not the same
    if((getArrivalTime() != student->getArrivalTime()) || (getTimeLeft() != student->getTimeLeft()) || (getTotalTime() != student->getTotalTime()) || (getWaitTime() != student->getWaitTime())){
        return true;
    }
    return false;
}
