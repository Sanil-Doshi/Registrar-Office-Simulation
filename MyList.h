#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class MyList{
    public:

        virtual void insertFront(T d) = 0;
        virtual void insertBack(T d) = 0;

        virtual T removeFront() = 0;
        virtual T removeBack() = 0;
        virtual T removeNode(T value) = 0;

        virtual int find(T value) = 0;
        virtual bool isEmpty() = 0;
        virtual unsigned int getSize() = 0;
};


#endif