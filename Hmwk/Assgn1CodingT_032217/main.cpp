/*
 * File: main.cpp
 * Author: Najera Enrique
 * Date: 22 March 2017
 * Purpose: Singularly Linked List Using a Template Class
 */

// System Libraries
#include <iostream>

// User Libraries
#include "LinkList.h"

using namespace std;

// Start Method main
int main(int argc, char** argv) {
    // Declare variables
    int perLine = 5,
        howMany = 10;
    
    // Output datatype
    cout << "Integer implementation\n";
    // Declare int object
    LinkList<int> intList(howMany);
    
    // Print the list
    intList.prntList(perLine);
    
    // Add to the list
    intList.addLnk(0);
    intList.prntList(perLine);
    
    // Add before
    cout << endl << "Add the number 16 before list data 4\n";
    intList.addBefore(4, 16);
    intList.prntList(perLine);
    
    // Add after
    cout << endl << "Add the number 12 after list data 8\n";
    intList.addAfter(8, 12);
    intList.prntList(perLine);
    
    // Add end
    cout << endl << "Add the number 22 at the end\n";
    intList.addEnd(22);
    intList.prntList(perLine);
    
    // Add beginning
    cout << endl << "Add the number 27 at the Beginning\n";
    intList.addBeg(27);
    intList.prntList(perLine);
    
    // Delete by value
    cout << endl << "Delete the number 2 from the list\n";
    intList.delByValue(2);
    intList.prntList(perLine);
    
    /****************************************
     *                                      *
     *      END INTEGER IMPLEMENTATION      *
     *                                      *
     ****************************************/
    
    // Output datatype
    cout << "Float implementation\n";
    // Declare float object
    LinkList<float> floatList(howMany);
    
    // Print the list
    floatList.prntList(perLine);
    
    // Add to the list
    floatList.addLnk(0);
    floatList.prntList(perLine);
    
    // Add before
    cout << endl << "Add the number 16.2 before list data 4\n";
    floatList.addBefore(4, 16.2);
    floatList.prntList(perLine);
    
    // Add after
    cout << endl << "Add the number 12.45 after list data 8\n";
    floatList.addAfter(8, 12.45);
    floatList.prntList(perLine);
    
    // Add end
    cout << endl << "Add the number 22.3 at the end\n";
    floatList.addEnd(22.3);
    floatList.prntList(perLine);
    
    // Add beginning
    cout << endl << "Add the number 27.27 at the Beginning\n";
    floatList.addBeg(27.27);
    floatList.prntList(perLine);
    
    // Delete by value
    cout << endl << "Delete the number 12.45 from the list\n";
    floatList.delByValue(12.45);
    floatList.prntList(perLine);
    
    return 0;
}
