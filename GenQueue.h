#ifndef GENQUEUE_H
#define GENQUEUE_H
#include <iostream>
#include <exception>

#include "LinkedList.h"

using namespace std;


//array based queue
template<class T>
class GenQueue{

public:

    GenQueue(); //default constrcutor
    ~GenQueue(); //destructor

    //core functions
    void enqueue(T d);
    T dequeue(); 

    //aux functions
    T peek();
    bool isEmpty();
    unsigned int getSize();

private:

    DoublyLinkedList<T> *linkedlist;
    unsigned int nSize;
};

template<class T>
GenQueue<T>::GenQueue(){

    linkedlist = new DoublyLinkedList<T>();
    nSize = 0;

}

template<class T>
GenQueue<T>::~GenQueue(){

    delete linkedlist;
}

template<class T>
void GenQueue<T>::enqueue(T d){

    linkedlist->insertBack(d);
    nSize++;

}

template<class T>
T GenQueue<T>::dequeue(){

    nSize--;
    return linkedlist->removeFront();
}

template<class T>
T GenQueue<T>::peek(){

    return linkedlist->front->data;
}

template<class T>
bool GenQueue<T>::isEmpty(){

    return nSize == 0;
}

template<class T>
unsigned int GenQueue<T>::getSize(){

    return nSize;
}

#endif


