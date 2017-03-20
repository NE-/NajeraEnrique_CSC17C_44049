/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on March 8th, 2017, 8:01 PM
 * Purpose: Singularly Linked List
 * 
 * Edited by: Najera Enrique
 * Date Due: 22 March 2017
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
#include "link.h"

//Global Constants

//Function Prototypes
Link *fillLst(int);
void  prntLst(Link *,int);
void  destLst(Link *);
Link  *endLst(Link *);
void   addLnk(Link *,int);
void   delLnk();
int    fndLnk(int);

void addBefore(Link *, int, int);
void addAfter(Link *, int, int);
void addEnd(Link *, int);
Link *addBeg(Link *, int);
void delByValue(Link *, int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    Link *lnkList;
    int howMany=10,perLine=5;
    
    //Input Data
    lnkList=fillLst(howMany);
    
    //Print the list
    prntLst(lnkList,perLine);
    
    //Add to the list
    addLnk(lnkList,0);
    prntLst(lnkList,perLine);

    // Add before
    cout << endl << "Add the number 16 before list data 4\n";
    addBefore(lnkList, 4, 16);
    prntLst(lnkList,perLine);
    
    // Add after
    cout << endl << "Add the number 12 after list data 8\n";
    addAfter(lnkList, 8, 12);
    prntLst(lnkList,perLine);
    
    // Add end
    cout << endl << "Add the number 22 at the end\n";
    addEnd(lnkList, 22);
    prntLst(lnkList, perLine);
    
    // Add beginning
    cout << endl << "Add the number 27 at the Beginning\n";
    lnkList=addBeg(lnkList, 27);
    prntLst(lnkList, perLine);
    
    // Delete by value
    cout << endl << "Delete the number 2 from the list\n";
    delByValue(lnkList, 2);
    prntLst(lnkList, perLine);
    
    //Destroy the List
    destLst(lnkList);
    
    //Exit Stage Right
    return 0;
}

Link *fillLst(int n){
    Link *front=new Link;   //Create the front link
    Link *prev=front;       //Set the front equal to the traversal link
    prev->data=n--;         //Fill the front with data
    prev->linkPtr=NULL;     //Point the front to no where
    do{
        Link *end=new Link;//Create a new link
        end->data=n--;     //Fill with data
        end->linkPtr=NULL; //Point to no where
        prev->linkPtr=end; //Previous link will point to the end
        prev=end;          //Move to the end
    }while(n>0);           //Repeat until filled
    return front;          //Return the beginning of the Linked list
}

void  prntLst(Link *front,int perLine){
    int colCnt=0;                //Column counter
    Link *next=front;            //Start at the front of the list
    cout<<endl;                  //Put the beginning on a new line
    do{
        cout<<setw(4)<<next->data<<" ";  //Print the link
        if(colCnt++%perLine==(perLine-1))cout<<endl;
        next=next->linkPtr;      //Go to the next link
    }while(next!=NULL);          //Stop when your at the end
    cout<<endl;
}

void  destLst(Link *front){
    if(front==NULL)return;         //Empty List? then leave
    do{
        Link *temp=front->linkPtr; //Traverse the list
        delete front;              //Delete the front of the list
        front=temp;                //Set the new front of the list
    }while(front!=NULL);           //Stop when we reach the end.
}

Link *endLst(Link *front){
    Link *lnk=front,*end;//Start the link at the front to find the end
    do{
        end=lnk;         //Are we at the end yet?
        lnk=lnk->linkPtr;//Traverse to the next link
    }while(lnk!=NULL);   //Finally found the end when NULL
    return end;
}

void   addLnk(Link *front,int val){
    Link *nx2last=endLst(front);//Find the last link in the list
    Link *last=new Link;        //Create a new last link
    last->data=val;             //Fill with the value desire
    last->linkPtr=NULL;         //Point the added link to no where
    nx2last->linkPtr=last;      //Put the last link on the end 
}

// Start method addBefore
void addBefore(Link *front, int before, int val){
    Link *next = front;       // Keep track of next node
    Link *prev = new Link;    // Store previous nodes to prevent overwrite
    Link *newNode = new Link; // Creates new node for new value
    
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
void addAfter(Link *front, int after, int val){
    Link *next = front;       // Keep track of next node
    Link *prev = new Link;    // Store previous nodes to prevent overwrite
    Link *newNode = new Link; // Creates new node for new value
    
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
void addEnd(Link *front, int val){
    addLnk(front, 0);          // Add new link to the end
    Link *end = endLst(front); // Go to the end
    end->data=val;             // Overwrite the value with val param
}// End method addEnd

// Start method addBeg
Link *addBeg(Link *front, int val){
    Link *newNode = new Link; // Creates new node for new value
    
    newNode->data = val;      // Fill in newNode data
    newNode->linkPtr = front; // Fill in newNode's address
    front = newNode;          // Add newNode to the front
    return front;             // Return front to overwrite entire list
}// End method addBeg

// Start method delByValue
void delByValue(Link *front, int val){
    /*
     * ERROR: cannot delete head of list
     */
    Link *next = front; // Go through list
    Link *temp = front; // Temp list
    
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
