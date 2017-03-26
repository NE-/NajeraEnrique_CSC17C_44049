/*
 * File: main.cpp
 * Author: Najera Enrique
 * Date: 29 March 2017
 * Purpose: Circularly linke dlist implementation
 */

// System Libraries
#include <iostream>

// User Libraries
#include "LLcircularly.h"

using namespace std;

// Start method main
int main(int argc, char** argv){
    // Declare variables
    int perLine = 5,
        howMany = 10;
    
    // Output datatype
    cout << "Integer implementation\n";
    // Declare int object
    LLcircularly<int> intCirc(howMany);
    
    // Print the list
    intCirc.prntList(perLine);
    
    // Add to the list
    intCirc.addLnk(0);
    intCirc.prntList(perLine);
    
    // Add before
    cout << endl << "Add the number 16 before list data 4\n";
    intCirc.addBefore(4, 16);
    intCirc.prntList(perLine);
    
    // Add after
    cout << endl << "Add the number 12 after list data 8\n";
    intCirc.addAfter(8, 12);
    intCirc.prntList(perLine);
    
    // Add end
    cout << endl << "Add the number 22 at the end\n";
    intCirc.addEnd(22);
    intCirc.prntList(perLine);
    
    // Add beginning
    cout << endl << "Add the number 27 at the Beginning\n";
    intCirc.addBeg(27);
    intCirc.prntList(perLine);
    
    // Delete by value
    cout << endl << "Delete the number 2 from the list\n";
    intCirc.delByValue(2);
    intCirc.prntList(perLine);
    
    /****************************************
     *                                      *
     *      END INTEGER IMPLEMENTATION      *
     *                                      *
     ****************************************/
    
    // Output datatype
    cout << "Float implementation\n";
    // Declare float object
    LLcircularly<float> floatCirc(howMany);
    
    // Print the list
    floatCirc.prntList(perLine);
    
    // Add to the list
    floatCirc.addLnk(0);
    floatCirc.prntList(perLine);
    
    // Add before
    cout << endl << "Add the number 16.2 before list data 4\n";
    floatCirc.addBefore(4, 16.2);
    floatCirc.prntList(perLine);
    
    // Add after
    cout << endl << "Add the number 12.45 after list data 8\n";
    floatCirc.addAfter(8, 12.45);
    floatCirc.prntList(perLine);
    
    // Add end
    cout << endl << "Add the number 22.3 at the end\n";
    floatCirc.addEnd(22.3);
    floatCirc.prntList(perLine);
    
    // Add beginning
    cout << endl << "Add the number 27.27 at the Beginning\n";
    floatCirc.addBeg(27.27);
    floatCirc.prntList(perLine);
    
    // Delete by value
    cout << endl << "Delete the number 12.45 from the list\n";
    floatCirc.delByValue(12.45);
    floatCirc.prntList(perLine);
    
    return 0;
}// End method main