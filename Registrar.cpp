#include "Registrar.h"


Registrar::Registrar(){

    time = 0;
    studentLine = new GenQueue<Student>();

}

Registrar::Registrar(int totalWindows){

    time = 0;
    for (int i = 0; i < totalWindows; i++){
        registrar->push_back(Window());
    }
    
    studentLine = new GenQueue<Student>();
}

Registrar::~Registrar(){

    delete[] studentLine;

}

void Registrar::simulate(vector<Student> s){

    while(!windowsIdle() || !studentLine->isEmpty()){

        //putting student into the queue (student line)
        //iterates through the student vector
        for (int i = 0; i < s.size(); i++){
            //if student arrival time equals time, add it to the queue
            if(s.at(i).getArrivalTime() == time){
                studentLine->enqueue(s.at(i));
            }
        }

        //removes it from the queue and adds it to the registrar
        //iterates through the  registrar vector
        for (int i = 0; i < registrar->size(); i++){
            //if the window is not occupied and the student line (queue) is not empty
            if(!registrar->at(i).windowOccupied() && !studentLine->isEmpty()){

                //remove student from the student line (queue)
                Student student = studentLine->dequeue();
                //add the student to a window in the registrar
                registrar->at(i).setStudent(student);
                
            }
        }

        //iterare through the registrar
        for (int i = 0; i < registrar->size(); i++){
            //if the window at the registrar is not occupied (has a timeLeft of 0)
            if(!registrar->at(i).changeTime()){
                // The student leaves the window and is added to the total students vector
                students->push_back(registrar->at(i).getStudent());
                // the window is open
            }
        }

        //For students still waiting in line, increment their wait time
        for (int i = 0; i < studentLine->getSize(); i++){
            //Remove student from front of queue and add it to the back to increment time
            Student student = studentLine->dequeue();
            student.setWaitTime(student.getWaitTime()+1);
            studentLine->enqueue(student);
            
        }

        ++time;
    }

    printStatistics(studentMean(), studentMedian(), longestStudentWaitTime(), overTenMinutes(), windowMean(), longestWindowIdleTime(), windowOverFiveMinutes());
}

double Registrar::studentMean(){

    int sum = 0;

    for(int i = 0; i < numStudents; i++){
        sum += students->at(i).getWaitTime();

    }

    double mean = double(sum) / numStudents;
    return mean;
}

double Registrar::studentMedian(){

    for (int i = 0; i < numStudents; i++){

        int waitTime1 = students->at(i).getWaitTime();

        for (int j = 0; j < numStudents; j++){

            int waitTime2 = students->at(j).getWaitTime();

            if (waitTime1 > waitTime2){

                int temp = students->at(i).getWaitTime();
                students->at(i).setWaitTime(students->at(i).getWaitTime());
                students->at(j).setWaitTime(students->at(j).getWaitTime());
            }
        }
    }

    if (numStudents % 2 == 1){
        int mIndex = (numStudents -1) /2;
        return students->at(mIndex).getWaitTime();

    } else {
        int rIndex = numStudents / 2;
        int lIndex = rIndex - 1;
        return(students->at(lIndex).getWaitTime() + students->at(rIndex).getWaitTime());
    }
}

int Registrar::longestStudentWaitTime(){

    int longestTime = students->at(0).getWaitTime();

    for (int i = 1; i < numStudents; i++){

        if (students->at(i).getWaitTime() > longestTime){

            longestTime = students->at(i).getWaitTime();
        }
    }
    return longestTime;
}

int Registrar::overTenMinutes(){

    int count = 0;

    for (int i = 0; i < numStudents; i++){

        if (students->at(i).getWaitTime() >= 10){
            count++;

        }
    }
    return count;
}

double Registrar::windowMean(){

    double windowMean = 0.0;
    int sum = 0;

    for (int i = 0; i < numWindows; i++){

        sum += registrar->at(i).getIdleTime();
    }

    windowMean = double(sum) / numWindows;

    return windowMean;
}

int Registrar::longestWindowIdleTime(){

    int longestWindowTime = registrar->at(0).getIdleTime();

    for (int i = 1; i < numWindows; i++){

        if (registrar->at(i).getIdleTime() > longestWindowTime){

            longestWindowTime = registrar->at(i).getIdleTime();
        }
    }
    
    return longestWindowTime;
}

int Registrar::windowOverFiveMinutes(){

    int count = 0;

    for (int i = 0; i < numWindows; i++){

        if (registrar->at(i).getIdleTime() >= 5){

            count++;
        }
    }

    return count;

}

bool Registrar::windowsIdle(){
    
    for (int i = 0; i < numWindows; i++){
        
        if(!registrar->at(i).windowOccupied()){
            
            return false;
        }
    }
    return true;
}

void Registrar::printStatistics(double meanStudent, double medianStudent, int longestStudent, int numStudentsOverTen, 
                                double meanWindow, int longestWindow, int numWindowsOverFive){


    cout << endl;
    cout << "REGISTRAR STATISTICS: " << endl;
    cout << endl;
    cout << "Mean Student Wait Time: " << meanStudent << endl;
    cout << "Median Student Wait Time: " << medianStudent << endl;
    cout << "Longest Student Wait Time: " << longestStudent << endl;
    cout << "Number of Students Waiting Over 10 Minutes: " << numStudentsOverTen << endl;
    cout << "Mean Window Idle Time: " << meanWindow << endl;
    cout << "Longest Window Idle Time: " << longestWindow << endl;
    cout << "Number of Windows Idle Over 5 Minutes: " << numWindowsOverFive << endl;


}