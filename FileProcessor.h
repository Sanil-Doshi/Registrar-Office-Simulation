#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <iostream>
#include <string>
#include <fstream>
#include <exception>

#include "Student.h"
#include "GenQueue.h"
#include "Registrar.h"

using namespace std;

class FileProcessor{
  
    public:

        FileProcessor();
        FileProcessor(int numWindows);
        ~FileProcessor();

        void readFile(string inputFile);
    
    private:

        int time;
};

#endif