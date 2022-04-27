#include "FileProcessor.h"

FileProcessor::FileProcessor(){

    time = 0;
}

FileProcessor::~FileProcessor(){}

void FileProcessor::readFile(string inputFile){

    vector<Student> *totalStudents; //vector of student

    string newline = "";
    string windows; //number of windows
    string studentTime;
    int numStudents; //number of students
    int arrivalTime; //time the students arrive
    int timeOfStudent; //the time each student arrives

    ifstream readFile(inputFile);

    //gets first line of file as number of windows and converts it to an int
    getline(readFile, windows);
    int numWindows = stoi(windows);

    while (getline(readFile, newline)){

        arrivalTime = stoi(newline); 

        getline(readFile, newline); 
        numStudents = stoi(newline);

        for (int i = 0; i < numStudents; ++i) {
            
            getline(readFile, newline);

            timeOfStudent = stoi(newline);

            Student newStudent = Student(timeOfStudent, arrivalTime);

            totalStudents->push_back(newStudent);            
        }
    }

    Registrar *registrar = new Registrar(numWindows);

    registrar->simulate(*totalStudents);


    readFile.close();
}