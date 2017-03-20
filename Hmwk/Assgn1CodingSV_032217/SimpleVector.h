/*
 * File: SimpleVector.h
 * Author: Najera Enrique
 * Date: 22 March 2017
 * Purpose: Modify Simple Vector  to utilize a linked list 
 *          instead of a dynamic array.
 */

#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

// System Libraries
#include <iostream>
#include <new>
#include <cstdlib>

// User Libraries
#include "link.h"

using namespace std;

// Start class SimpleVector
template <class T>
class SimpleVector
{
    private:
        T *aptr;
        int arraySize;              // Holds size of list for size()
        void memError();
        void subError();
        Link<T> *lnkList;           // Declare a list of type T
        Link<T> *fillLst(T, T);     // Private since only the class uses it
        Link<T> *endLst(Link<T> *); // Private since only the class uses it
    public:
        SimpleVector()
            { aptr = 0; arraySize = 0;}
        SimpleVector(int, T);
        
        SimpleVector(const SimpleVector &);
        
        ~SimpleVector();
        
        int size() const
            { return arraySize;}
        
        T getElementAt(int position);
        
        T &operator[](const int &);
        
        // Link list specific function prototypes
        void prntList();
        void addVal(int);
};// End class SimpleVector

template <class T>
SimpleVector<T>::SimpleVector(int s, T val)
{
    // Fill the list and multiply by value val
    lnkList = fillLst(s, val);
    /*arraySize = s;
    
    try
    {
        aptr = new T [s];
    }
    catch (bad_alloc)
    {
        memError();
    }
    
    for (int count = 0; count < arraySize; count++)
        *(aptr + count) = 0;*/
}

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
    arraySize = obj.arraySize;
    
    aptr = new T [arraySize];
    if (aptr == 0)
        memError();
    
    for (int count = 0; count < arraySize; count++)
        *(aptr + count) = *(obj.aptr + count);
}

template <class T>
SimpleVector<T>::~SimpleVector()
{
    if (arraySize > 0)
        delete [] aptr;
}

        /* LINK LIST FUNCTION PROTOTYPES START */

// Start method fillLst
template <class T>
Link<T> *SimpleVector<T>::fillLst(T n, T val){
    Link<T> *front=new Link<T>;  //Create the front link
    Link<T> *prev=front;         //Set the front equal to the traversal link
    int temp = 0;                // Holds value to be multiplied by
    prev->data=temp;             //Fill the front with data
    prev->linkPtr=NULL;          //Point the front to no where
    temp++;n--;
    do{
        Link<T> *end=new Link<T>;//Create a new link
        end->data=temp*val;      //Fill with data
        end->linkPtr=NULL;       //Point to no where
        prev->linkPtr=end;       //Previous link will point to the end
        prev=end;                //Move to the end
        temp++;n--;              // Inc temp for multiplication
    }while(n>0);                 //Repeat until filled
    return front;                //Return the beginning of the Linked list
}// End method fillLst

// Start method prntList
template <class T>
void SimpleVector<T>::prntList(){
    int colCnt=0;               //Column counter
    Link<T> *next=lnkList;      //Start at the front of the list
    cout<<endl;                 //Put the beginning on a new line
    // Removed 'perLine' since the book prints in one single line
    do{
        cout<<next->data<<" ";  //Print the link
        next=next->linkPtr;     //Go to the next link
    }while(next!=NULL);         //Stop when your at the end
    cout<<endl;
}// End method prntList

// Start method addVal
// Adds each value in the list by 'val'
template <class T>
void SimpleVector<T>::addVal(int val){
    Link<T> *next=lnkList; // Start at the front
    
    // GO through the list and add each element by 'val'
    do{
        next->data += val;
        next=next->linkPtr;
    }while(next!=NULL);
}// End method addVal

        /* LINK LIST FUNCTION PROTOTYPES END */

template <class T>
void SimpleVector<T>::memError()
{
    cout << "ERROR: Cannot allocate memory.\n";
    exit(EXIT_FAILURE);
}

template <class T>
void SimpleVector<T>::subError()
{
    cout << "ERROR: Subscript out of range.\n";
    exit(EXIT_FAILURE);
}

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
    if (sub < 0 || sub >= arraySize)
        subError();
    return aptr[sub];
}
template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
    if (sub < 0 || sub >= arraySize)
        subError();
    return aptr[sub];
}

#endif /* SIMPLEVECTOR_H */

