#include "Registrar.h"

int main(int argc, char** argv){
    FileProcessor *fp = new FileProcessor();
    fp->readFile(argv[1]);


    Registrar *registrar = new Registrar();
    //registrar->simulate(); // need to get the vector students as argument

    delete registrar;

    return 0;
}