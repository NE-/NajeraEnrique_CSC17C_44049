/*
 * File: LLqueue.h
 * Author: Najera Enrique
 * Date: 29 March 2017
 * Purpose: Create queue from linked list (FIFO)
 */

#ifndef LLQUEUE_H
#define LLQUEUE_H

// System Libraries
#include <iostream>
#include <iomanip>

using namespace std;

// User Libraries
#include "link.h"

// Start template class LLqueue
template <class T>
class LLqueue{
    public:
        // Constructor
        LLqueue(){
            lnkList = new Link<T>;   // Create new Link
            lnkList->data = 0;       // Set to 0 for EXIT_SUCCESS
            lnkList->linkPtr = NULL; // Set to NULL
        }
        // Destructor
        ~LLqueue(){
            if(lnkList==NULL)return;            //Empty List? then leave
            do{
                Link<T> *temp=lnkList->linkPtr; //Traverse the list
                delete lnkList;                 //Delete the front of the list
                lnkList=temp;                   //Set the new front of the list
            }while(lnkList!=NULL);              //Stop when we reach the end.
        }
        
        // Function Prototypes
        void prntQueue(int); // Prints queue elements
        void push(T);        // Pushes type into queue
        T pop();             // Pops last element (FIFO)
        
    private:
        Link<T> *lnkList;
};// End template class LLstack

template <class T>
void LLqueue<T>::prntQueue(int perLine){
    int colCnt=0;                //Column counter
    Link<T> *next=lnkList;       //Start at the front of the list
    cout<<endl;                  //Put the beginning on a new line
    do{
        cout<<setw(5)<<next->data<<" ";   //Print the link
        if(colCnt++%perLine==(perLine-1))cout<<endl;
        next=next->linkPtr;      //Go to the next link
    }while(next!=NULL);          //Stop when your at the end
    cout<<endl;
}

// Start method push
template <class T>
void LLqueue<T>::push(T val){
    Link<T> *newNode = new Link<T>; // Create new node

    newNode->data = val;            // Fill data with argument
    newNode->linkPtr = lnkList;     // Fill new address
    lnkList = newNode;              // Add to front
}// End method push

// Start method pop
template <class T>
T LLqueue<T>::pop(){
    Link<T> *pop = lnkList;          // Go to the end of list for FIFO
    Link<T> *end = lnkList->linkPtr; // Holds end of list
    T tempVal = 0;                   // Holds data before deletion
    
    // If already at end, delete
    if (lnkList->linkPtr == NULL){
        delete lnkList;
        lnkList = NULL;
    }  
    else{
        // GO through the list until reach end
        while (end->linkPtr != NULL){
            pop = end;
            end = end->linkPtr;
            tempVal = end->data; // Hold value before deletion
        }

        delete end;          // Delete
        pop->linkPtr = NULL; // Set new end by setting to NULL
    }
    
    // Return data before deletion
    return tempVal;
}// End method pop

#endif /* LLQUEUE_H */
