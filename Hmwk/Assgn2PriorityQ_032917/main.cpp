/*
 * File: main.cpp
 * Author: Najera Enrique
 * Date: 29 March 2017
 * Purpose: Create priority queue
 */

// System Libraries
#include <iostream>

using namespace std;
// User Libraries
#include "LLpriorityQ.h"

// Start method main
int main(int argc, char** argv){
    int howMany = 10;

    // Declare int object
    LLpriorityQ<int> intPriority(howMany);
    
    cout << "\nNumber   Priority" << endl;
    intPriority.prntList();
    
    cout << "\nSort based on priority\n";
    intPriority.sortList();
    cout << "\nNumber   Priority" << endl;
    intPriority.prntList();
    
    return 0;
}// End method main
