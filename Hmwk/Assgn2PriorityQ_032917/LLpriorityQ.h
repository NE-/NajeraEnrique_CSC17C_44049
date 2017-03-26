/*
 * File: LLpriorityQ.h
 * Author: Najera Enrique
 * Date: 29 March 2017
 * Purpose: 
 */

#ifndef LLPRIORITYQ_H
#define LLPRIORITYQ_H

// System Libraries
#include <iostream>
#include <iomanip>
#include <stdlib.h> // srand, rand
#include <time.h>   // time

using namespace std;

// User Libraries
#include "linkQ.h"

// Start template class LLpriorityQ
template <class T>
class LLpriorityQ{
    public:
        // Constructor
        LLpriorityQ(int howMany){
            // INIT random number seed
            // Used for setting priority
            srand (time(NULL));
            lnkList = fillLst(howMany);
            listSize = howMany;
        }
        // Destructor
         // Destructor
        ~LLpriorityQ(){
            if(lnkList==NULL)return;         //Empty List? then leave
            do{
                LinkQ<T> *temp=lnkList->linkPtr; //Traverse the list
                delete lnkList;              //Delete the front of the list
                lnkList=temp;                //Set the new front of the list
            }while(lnkList!=NULL);           //Stop when we reach the end.
        }
        
        // Function Prototypes
        void prntList();
        void sortList();
        string priorityCheck(int); // Checks priority meaning
    private:
        int listSize; // Holds size of list for sorting
        LinkQ<T> *lnkList;
        LinkQ<T> *fillLst(T);
};

template <class T>
LinkQ<T> *LLpriorityQ<T>::fillLst(T n){
    LinkQ<T> *front=new LinkQ<T>;    //Create the front link
    LinkQ<T> *prev=front;            //Set the front equal to the traversal link
    prev->data=n--;                  //Fill the front with data
    prev->priority = rand() % 6 + 1; // Fill the priority
    prev->linkPtr=NULL;              //Point the front to no where
    do{
        LinkQ<T> *end=new LinkQ<T>;//Create a new link
        end->data=n--;           //Fill with data
        end->priority = rand() % 6 + 1; /* 1 = Low
                                         * 2 = Below Normal
                                         * 3 = Normal
                                         * 4 = Above Normal
                                         * 5 = High
                                         * 6 = Realtime
                                         */
        end->linkPtr=NULL;       //Point to no where
        prev->linkPtr=end;       //Previous link will point to the end
        prev=end;                //Move to the end
    }while(n>0);                 //Repeat until filled
    return front;                //Return the beginning of the Linked list
}

template <class T>
void LLpriorityQ<T>::prntList(){
    int colCnt=0;                //Column counter
    LinkQ<T> *next=lnkList;       //Start at the front of the list
    cout<<endl;                  //Put the beginning on a new line
    do{
        cout<<setw(6)<<next->data<<" "   //Print the link
            <<setw(10)<<next->priority // Print the priority
            <<"   "<<priorityCheck(next->priority);
        cout<<endl;
        next=next->linkPtr;      //Go to the next link
    }while(next!=NULL);          //Stop when your at the end
    cout<<endl;
}

// Start method priorityCheck 
// returns priority meaning
template <class T>
string LLpriorityQ<T>::priorityCheck(int priority){
    switch(priority){
        case 1: // Low
            return "Low ";
            break;
        case 2: // Below Normal
            return "Below Normal ";
            break;
        case 3: // Normal
            return "Normal ";
            break;
        case 4: // Above Normal
            return "Above Normal ";
            break;
        case 5: // High
            return "High ";
            break;
        case 6: // Realtime
            return "Realtime ";
            break;
        default:
            return "ERROR: priority level out of bounds [1 to 6]";
    };
}// End method priorityCheck

// Start method sortList
template <class T>
void LLpriorityQ<T>::sortList(){
    /*
     * ERROR: if the first priority is greater than the next,
     *        it will sort up to the first 5 elements,
     *        else it wont sort at all
     */
    LinkQ<T> *front = lnkList;
    LinkQ<T> *next = front;
    T tempP; // Temporarily hold priority value
    T tempN; // Temporarily hold number value
    int swap = 1; // Swap flag

    // Implemented bubble sort
    for (int i = 1; (i <= listSize) && swap; i++){
        swap = 0;
        next = next->linkPtr;
        for (int j = 0; j < (listSize - 1); j++){
            if (next == NULL || front == NULL)return;
            else if (next->priority > front->priority){
                // Swap priorities
                tempP = front->priority;
                front->priority = next->priority;
                next->priority = tempP;
                
                // Swap numbers
                tempN = front->data;
                front->data = next->data;
                next->data = tempN;
                front = front->linkPtr;
                
                swap = 1;
            } 
        }
    }
}

#endif /* LLPRIORITYQ_H */

