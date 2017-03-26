/*
 * File: main.cpp
 * Author: Najera Enrique
 * Date: 29 March 2017
 * Purpose: Create a doubly linked list
 * 
 * Reference: https://en.wikipedia.org/wiki/Doubly_linked_list
 */

// System Libraries
#include <iostream>

using namespace std;

// User Libraries
#include "LLdoubly.h"

// Start method main
int main(int argc, char** argv){
    // Declare variables
    int perLine = 5,
        howMany = 10;
    
    cout << "Integer implementation" << endl;
    // Declare object type int
    LLdoubly<int> intDoubly(howMany);
    
    // Print the list
    intDoubly.prntList(perLine);
    
    // Add to the list
    intDoubly.addLnk(0);
    intDoubly.prntList(perLine);
    
    // Add before
    cout << endl << "Add the number 16 before list data 4\n";
    intDoubly.addBefore(4, 16);
    intDoubly.prntList(perLine);
    
    // Add after
    cout << endl << "Add the number 12 after list data 8\n";
    intDoubly.addAfter(8, 12);
    intDoubly.prntList(perLine);
    
    // Add end
    cout << endl << "Add the number 22 at the end\n";
    intDoubly.addEnd(22);
    intDoubly.prntList(perLine);
    
    // Add beginning
    cout << endl << "Add the number 27 at the Beginning\n";
    intDoubly.addBeg(27);
    intDoubly.prntList(perLine);
    
    // Delete by value
    cout << endl << "Delete the number 2 from the list\n";
    intDoubly.delByValue(2);
    intDoubly.prntList(perLine);
    
    /****************************************
     *                                      *
     *      END INTEGER IMPLEMENTATION      *
     *                                      *
     ****************************************/
    
    // Output datatype
    cout << "Float implementation\n";
    // Declare float object
    LLdoubly<float> floatDoubly(howMany);
    
    // Print the list
    floatDoubly.prntList(perLine);
    
    // Add to the list
    floatDoubly.addLnk(0);
    floatDoubly.prntList(perLine);
    
    // Add before
    cout << endl << "Add the number 16.2 before list data 4\n";
    floatDoubly.addBefore(4, 16.2);
    floatDoubly.prntList(perLine);
    
    // Add after
    cout << endl << "Add the number 12.45 after list data 8\n";
    floatDoubly.addAfter(8, 12.45);
    floatDoubly.prntList(perLine);
    
    // Add end
    cout << endl << "Add the number 22.3 at the end\n";
    floatDoubly.addEnd(22.3);
    floatDoubly.prntList(perLine);
    
    // Add beginning
    cout << endl << "Add the number 27.27 at the Beginning\n";
    floatDoubly.addBeg(27.27);
    floatDoubly.prntList(perLine);
    
    // Delete by value
    cout << endl << "Delete the number 12.45 from the list\n";
    floatDoubly.delByValue(12.45);
    floatDoubly.prntList(perLine);
    
    return 0;
}// End method main

