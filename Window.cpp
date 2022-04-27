#include "Window.h"

Window::Window(){

    student = new Student(0,0);
    idleTime = 0;
    isOccupied = false;

}

Window::~Window(){

    delete student;
}

Student Window::getStudent(){
    
    return *student;
}

void Window::setStudent(Student s){
    student = &s;
    isOccupied = true;
}

int Window::getIdleTime(){

    return idleTime;
}

void Window::setIdleTime(int t){

    idleTime = t;
}

bool Window::windowOccupied(){

    if(isOccupied){
        return true;
    }
    return false;
}

bool Window::operator == (Window *window)
{
    //Checks if the variables are the same
    if(student == window->student && getIdleTime() == window->getIdleTime()){
        return true;
    }
    return false;
}
bool Window::operator != (Window *window)
{
    //Checks if the variables are not the same
    if(student != window->student || this->getIdleTime() != window->getIdleTime()){
        return true;
    }
    return false;
}

bool Window::changeTime(){

    //If the window doesnt have a student then it is idle and gets more idle time
    if(!isOccupied){
        idleTime++;
        return true;
    } else {
        
        //Decrement time
        student->setTimeLeft(student->getTimeLeft()-1);
        //If the student has no time left it is removed frim the window
        if(student->getTimeLeft() == 0) {
            isOccupied = false;
            return false;

        } else {
            return true;
        } 
    }
}