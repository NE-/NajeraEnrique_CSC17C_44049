/*
 * File: main.cpp
 * Author: Najera Enrique
 * Date: 22 March 2017
 * Purpose: Modify Simple Vector  to utilize a linked list 
 *          instead of a dynamic array.
 */

// System Libraries
#include <iostream>

// User Libraries
#include "SimpleVector.h"

using namespace std;

// Start method main
int main(){
    // Declare and Initialize variables
    const int SIZE = 10; // Size of list
    
    // Declare objects
    SimpleVector<int> intTable(SIZE, 2);
    SimpleVector<double> doubleTable(SIZE, 2.14);
    
    /* List filled within class
     * for (count = 0; count < SIZE; count++)
    {
        intTable[count] = (count * 2);
        doubleTable[count] = (count * 2.14);
    }*/
    
    cout << "These values are in intTable:\n";
    intTable.prntList();
    cout << endl;
    cout << "These values are in doubleTable:\n";
    doubleTable.prntList();
    cout << endl;
    
    cout << "\nAdding 5 to each element of intTable"
         << " and doubleTable.\n";
    intTable.addVal(5);
    doubleTable.addVal(5);
    
    cout << "These values are in intTable:\n";
    intTable.prntList();
    cout << endl;
    cout << "These values are in doubleTable:\n";
    doubleTable.prntList();
    cout << endl;
    
    cout << "\nIncrementing each element of intTable and"
         << " doubleTable.\n";
    intTable.addVal(1);
    doubleTable.addVal(1);
    
    cout << "These values are in intTable:\n";
    intTable.prntList();

    cout << endl;
    cout << "These values are in doubleTable:\n";
    doubleTable.prntList();
    cout << endl;
    
    return 0;
}// End method main