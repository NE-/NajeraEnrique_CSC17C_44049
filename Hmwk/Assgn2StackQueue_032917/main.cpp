/*
 * File: main.cpp
 * Author: Najera Enrique
 * Date: 29 March 2017
 * Purpose: Create a stack/queue from linked list.
 */

// System Libraries
#include <iostream>

using namespace std;

// User Libraries
#include "LLstack.h"
#include "LLqueue.h"

// Start method main
int main(int argc, char** argv){
    // Declare Variables
    int perLine = 10; // Print X values of the print
                      // method in objects
    
    /****************************
     *                          *
     *        START STACK       *
     *                          *
     ****************************/
    
    // Declare integer stack object
    LLstack<int> intStack;
    
    cout << "----Integer Stack----\n"<<endl;
    
    // Pushing
    cout << "Push the number 7\n";
    intStack.push(7);
    intStack.prntStack(perLine);
    
    cout << "Push the number 12\n";
    intStack.push(12);
    intStack.prntStack(perLine);
    
    cout << "Push the number 576\n";
    intStack.push(576);
    intStack.prntStack(perLine);
    
    cout << "Push the number 3\n";
    intStack.push(3);
    intStack.prntStack(perLine);
    
    // Popping
    cout << "\nPop " << intStack.pop() << endl;
    intStack.prntStack(perLine);
    
    cout << "\nPop " << intStack.pop() << endl;
    intStack.prntStack(perLine);
    
    cout << "\nPop " << intStack.pop() << endl;
    intStack.prntStack(perLine);
    
    // Declare float stack object
    LLstack<float> floatStack;
    
    cout << "\n----Float Stack----\n"<<endl;
    
    // Pushing
    cout << "Push the number 7\n";
    floatStack.push(7);
    floatStack.prntStack(perLine);
    
    cout << "Push the number 12.6\n";
    floatStack.push(12.6);
    floatStack.prntStack(perLine);
    
    cout << "Push the number 5.76\n";
    floatStack.push(5.76);
    floatStack.prntStack(perLine);
    
    cout << "Push the number 3\n";
    floatStack.push(3);
    floatStack.prntStack(perLine);
    
    // Popping
    cout << "\nPop " << floatStack.pop() << endl;
    floatStack.prntStack(perLine);
    
    cout << "\nPop " << floatStack.pop() << endl;
    floatStack.prntStack(perLine);
    
    cout << "\nPop " << floatStack.pop() << endl;
    floatStack.prntStack(perLine);
    
    /****************************
     *                          *
     *        END   STACK       *
     *                          *
     ****************************/
    
    /****************************
     *                          *
     *        START QUEUE       *
     *                          *
     ****************************/
    
    // Declare integer queue
    LLqueue<int> intQueue;
    
    cout << "\n----Integer Queue----\n"<<endl;
    
    // Pushing
    cout << "Push the number 2\n";
    intQueue.push(2);
    intQueue.prntQueue(perLine);
    
    cout << "Push the number 83\n";
    intQueue.push(83);
    intQueue.prntQueue(perLine);
    
    cout << "Push the number 514\n";
    intQueue.push(514);
    intQueue.prntQueue(perLine);
    
    cout << "Push the number 6\n";
    intQueue.push(6);
    intQueue.prntQueue(perLine);
    
    // Popping
    cout << "\nPop " << intQueue.pop() << endl;
    intQueue.prntQueue(perLine);
    
    cout << "\nPop " << intQueue.pop() << endl;
    intQueue.prntQueue(perLine);
    
    cout << "\nPop " << intQueue.pop() << endl;
    intQueue.prntQueue(perLine);
    
    // Declare float queue
    LLqueue<float> floatQueue;
    
    cout << "\n----Float Queue----\n"<<endl;
    
    // Pushing
    cout << "Push the number 2\n";
    floatQueue.push(2);
    floatQueue.prntQueue(perLine);
    
    cout << "Push the number 2.85\n";
    floatQueue.push(2.85);
    floatQueue.prntQueue(perLine);
    
    cout << "Push the number 5.14\n";
    floatQueue.push(5.14);
    floatQueue.prntQueue(perLine);
    
    cout << "Push the number 4\n";
    floatQueue.push(4);
    floatQueue.prntQueue(perLine);
    
    // Popping
    cout << "\nPop " << floatQueue.pop() << endl;
    floatQueue.prntQueue(perLine);
    
    cout << "\nPop " << floatQueue.pop() << endl;
    floatQueue.prntQueue(perLine);
    
    cout << "\nPop " << floatQueue.pop() << endl;
    floatQueue.prntQueue(perLine);
    
    /****************************
     *                          *
     *        END   QUEUE       *
     *                          *
     ****************************/
    
    return 0;
} // End method main

