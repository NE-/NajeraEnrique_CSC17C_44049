/*
 * File: LLdoubly
 * Author: Najera Enrique
 * Date: 29 March 2017
 * Purpose: Implement doubly linked list
 */

#ifndef LLDOUBLY_H
#define LLDOUBLY_H

// System Libraries
#include <iostream>
#include <iomanip>

using namespace std;

// User Libraries
#include "link.h"

//Start template class LLdoubly
template <class T>
class LLdoubly{
    public:
        // Constructor
        LLdoubly(int howMany){
            lnkList = fillLst(howMany);
        }
        // Destructor
        ~LLdoubly(){
            if(lnkList==NULL)return;         //Empty List? then leave
            do{
                Link<T> *temp=lnkList->next; //Traverse the list
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
};// End template class LLdoubly

template <class T>
Link<T> *LLdoubly<T>::fillLst(T n){
    Link<T> *front=new Link<T>;  //Create the front link
    //Link<T> *prev=front;       //Set the front equal to the traversal link
    front->prev->data=n--;       //Fill the front with data
    front->next=NULL;            //Point the front to no where
    do{
        Link<T> *end=new Link<T>;//Create a new link
        end->data=n--;           //Fill with data
        end->next=NULL;          //Point to no where
        front->next=end;   //Previous link will point to the end
        front->prev=end;         //Move to the end
    }while(n>0);                 //Repeat until filled
    return front;                //Return the beginning of the Linked list
}

template <class T>
void LLdoubly<T>::prntList(int perLine){
    int colCnt=0;                //Column counter
    Link<T> *next=lnkList;       //Start at the front of the list
    cout<<endl;                  //Put the beginning on a new line
    do{
        cout<<setw(6)<<next->data<<" ";  //Print the link
        if(colCnt++%perLine==(perLine-1))cout<<endl;
        next=next->next;      //Go to the next link
    }while(next!=NULL);          //Stop when your at the end
    cout<<endl;
}

template <class T>
Link<T>* LLdoubly<T>::endLst(Link<T>* front){
    Link<T> *lnk=front,*end;//Start the link at the front to find the end
    do{
        end=lnk;         //Are we at the end yet?
        lnk=lnk->next;//Traverse to the next link
    }while(lnk!=NULL);   //Finally found the end when NULL
    return end;
}

template <class T>
void LLdoubly<T>::addLnk(T val){
    Link<T> *nx2last=endLst(lnkList);//Find the last link in the list
    Link<T> *last=new Link<T>;       //Create a new last link
    last->data=val;                  //Fill with the value desire
    last->next=NULL;              //Point the added link to no where
    nx2last->next=last;           //Put the last link on the end 
}

// Start method addBefore
template <class T>
void LLdoubly<T>::addBefore(T before, T val){
    Link<T> *next = lnkList;       // Keep track of next node
    //Link<T> *prev = new Link<T>;    // Store previous nodes to prevent overwrite
    Link<T> *newNode = new Link<T>; // Creates new node for new value
    
    newNode->data = val; // Store value in newNode's data
    
    // Go through list until it hits position wanted
    while(next->next != NULL && next->data != before)
    {
        // Clone everything before 'before'
        next->prev = next;
        next=next->next;
    }
    
    // Store newNode into the linked list
    next->next = newNode;
    newNode->next = next;
}// End method addBefore

// Start method addAfter
template <class T>
void LLdoubly<T>::addAfter(T after, T val){
    Link<T> *next = lnkList;       // Keep track of next node
    //Link<T> *prev = new Link<T>;    // Store previous nodes to prevent overwrite
    Link<T> *newNode = new Link<T>; // Creates new node for new value
    
    newNode->data = val; // Store value in newNode's data
    
    // Go through list until it hits position wanted
    while(next->next != NULL && next->data != after-1)
    {
        // Clone everything before 'before'
        next->prev = next;
        next=next->next;
    }
    
    // Store newNode into the linked list
    next->next = newNode;
    newNode->next = next;
}// End method addAfter

// Start method addEnd
template <class T>
void LLdoubly<T>::addEnd(T val){
    addLnk(0);          // Add new link to the end
    Link<T> *end = endLst(lnkList); // Go to the end
    end->data=val;             // Overwrite the value with val param
}// End method addEnd

// Start method addBeg
template <class T>
void LLdoubly<T>::addBeg(T val){
    Link<T> *newNode = new Link<T>; // Creates new node for new value
    
    newNode->data = val;      // Fill in newNode data
    newNode->next = lnkList; // Fill in newNode's address
    lnkList = newNode;          // Add newNode to the front
}// End method addBeg

// Start method delByValue
template <class T>
void LLdoubly<T>::delByValue(T val){
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
            next = next->next;
        }
    }
    // If number not found, output error
    if (next == NULL)cout << "Could not find " << val << " in list!\n";
    else{
        temp->next = next->next; // Hold pointer before deleting
        delete next;                   // Delete the node
    }
}// End method delByValue

#endif /* LLDOUBLY_H */

