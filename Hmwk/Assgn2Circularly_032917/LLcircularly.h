/*
 * File: LLcircularly.h
 * Author: Najera Enrique
 * Date: 29 March 2017
 * Purpose: Create circularly linked list
 */

#ifndef LLCIRCULARLY_H
#define LLCIRCULARLY_H

// System Libraries
#include <iostream> 
#include <iomanip>

using namespace std;

// User Libraries
#include "link.h"

template <class T>
class LLcircularly{
    public:
        // Constructor
        LLcircularly(int howMany){
            // Input data
            lnkList = fillLst(howMany);
        }
        // Destructor
        ~LLcircularly(){
            if(lnkList==NULL)return;         //Empty List? then leave
            do{
                Link<T> *temp=lnkList->linkPtr; //Traverse the list
                delete lnkList;              //Delete the front of the list
                lnkList=temp;                //Set the new front of the list
            }while(lnkList!=NULL);           //Stop when we reach the end.
        }
        
        // Function Prototypes
        void prntList(int);
        void addLnk(T);
        void addBefore(T, T);
        void addAfter(T, T);
        void addEnd(T);
        void addBeg(T);
        void delByValue(T);
        
    private:
        Link<T> *lnkList;           // Declare a list of type T
        Link<T> *fillLst(T);        // Private since only the class uses it
        Link<T> *endLst(Link<T> *); // Private since only the class uses it
};

template <class T>
Link<T> *LLcircularly<T>::fillLst(T n){
    Link<T> *front=new Link<T>;  //Create the front link
    Link<T> *prev=front;         //Set the front equal to the traversal link
    prev->data=n--;              //Fill the front with data
    prev->linkPtr=NULL;          //Point the front to no where
    do{
        Link<T> *end=new Link<T>;//Create a new link
        end->data=n--;           //Fill with data
        end->linkPtr=front;       //Point to front
        prev->linkPtr=end;       //Previous link will point to the end
        prev=end;                //Move to the end
    }while(n>0);                 //Repeat until filled
    return front;                //Return the beginning of the Linked list
}

template <class T>
void LLcircularly<T>::prntList(int perLine){
    int colCnt=0;                //Column counter
    Link<T> *front=lnkList->linkPtr; // Hold reference to the front
    Link<T> *next=lnkList;       //Start at the front of the list
    cout<<endl;                  //Put the beginning on a new line
    do{
        cout<<setw(6)<<next->data<<" ";  //Print the link
        if(colCnt++%perLine==(perLine-1))cout<<endl;
        next=next->linkPtr;      //Go to the next link
    }while(next->linkPtr!=front);          //Stop when your at the end
    cout<<endl;
}

template <class T>
Link<T>* LLcircularly<T>::endLst(Link<T>* front){
    Link<T> *lnk=front,*end;//Start the link at the front to find the end
    do{
        end=lnk;         //Are we at the end yet?
        lnk=lnk->linkPtr;//Traverse to the next link
    }while(lnk!=NULL);   //Finally found the end when NULL
    return end;
}

template <class T>
void LLcircularly<T>::addLnk(T val){
    Link<T> *nx2last=endLst(lnkList);//Find the last link in the list
    Link<T> *last=new Link<T>;       //Create a new last link
    last->data=val;                  //Fill with the value desire
    last->linkPtr=NULL;              //Point the added link to no where
    nx2last->linkPtr=last;           //Put the last link on the end 
}

// Start method addBefore
template <class T>
void LLcircularly<T>::addBefore(T before, T val){
    Link<T> *next = lnkList;       // Keep track of next node
    Link<T> *prev = new Link<T>;    // Store previous nodes to prevent overwrite
    Link<T> *newNode = new Link<T>; // Creates new node for new value
    
    newNode->data = val; // Store value in newNode's data
    
    // Go through list until it hits position wanted
    while(next->linkPtr != NULL && next->data != before)
    {
        // Clone everything before 'before'
        prev = next;
        next=next->linkPtr;
    }
    
    // Store newNode into the linked list
    prev->linkPtr = newNode;
    newNode->linkPtr = next;
}// End method addBefore

// Start method addAfter
template <class T>
void LLcircularly<T>::addAfter(T after, T val){
    Link<T> *next = lnkList;       // Keep track of next node
    Link<T> *prev = new Link<T>;    // Store previous nodes to prevent overwrite
    Link<T> *newNode = new Link<T>; // Creates new node for new value
    
    newNode->data = val; // Store value in newNode's data
    
    // Go through list until it hits position wanted
    while(next->linkPtr != NULL && next->data != after-1)
    {
        // Clone everything before 'before'
        prev = next;
        next=next->linkPtr;
    }
    
    // Store newNode into the linked list
    prev->linkPtr = newNode;
    newNode->linkPtr = next;
}// End method addAfter

// Start method addEnd
template <class T>
void LLcircularly<T>::addEnd(T val){
    addLnk(0);          // Add new link to the end
    Link<T> *end = endLst(lnkList); // Go to the end
    end->data=val;             // Overwrite the value with val param
}// End method addEnd

// Start method addBeg
template <class T>
void LLcircularly<T>::addBeg(T val){
    Link<T> *newNode = new Link<T>; // Creates new node for new value
    
    newNode->data = val;      // Fill in newNode data
    newNode->linkPtr = lnkList; // Fill in newNode's address
    lnkList = newNode;          // Add newNode to the front
}// End method addBeg

// Start method delByValue
template <class T>
void LLcircularly<T>::delByValue(T val){
    /*
     * ERROR: cannot delete head of list
     */
    Link<T> *next = lnkList; // Go through list
    Link<T> *temp = lnkList; // Temp list
    
    // Search through list for 'vsl'
    while(next != NULL){
        // If found, leave loop
        if (next->data == val)
            break;
        else{
            temp = next;
            next = next->linkPtr;
        }
    }
    // If number not found, output error
    if (next == NULL)cout << "Could not find " << val << " in list!\n";
    else{
        temp->linkPtr = next->linkPtr; // Hold pointer before deleting
        delete next;                   // Delete the node
    }
}// End method delByValue

#endif /* LLCIRCULARLY_H */

