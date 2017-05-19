/*
 * File: main.cpp
 * Author: Najera Enrique
 * Date: 19 May 2017
 * Purpose: Create a basic tree class
 */

// System Libraries
#include <iostream>
using namespace std;

// User Libraries
#include "BasicTree.h"

// Start method main
int main(int argc, char *argv[]){
    // Declare and init variables
    int m = 0, // Number of children a parent can have
        h = 0; // Height of the tree
    
    int pow = 1;      // Holds power for equation solving 
                      // number of nodes
    int numNodes = 0; // Holds total number of nodes
    
    // Declare Objects
    BasicTree intTree;
    
    // Prompt for number of children
    cout << "Enter size m > 0 of m-ary tree: ";
    cin >> m;
    
    // Error checking
    if (m <= 0)cout << "\nm must be greater than 0!\n";
    else {
        // Prompt for height
        cout << "\nEnter the height (excluding the root) > 0 of the tree: ";
        cin >> h;
        
        // Error checking
        if (h <= 0)cout << "\nHeight must be greater than 0!\n";
        else {
            // Solve for total number of nodes
            // ( (m ^ (h + 1)) - 1 ) / (m - 1)
            
            // Find the power of m ^ (h + 1)
            for (int i = 0; i < h + 1; i++)
                pow *= m;
            
            // Subtract 1
            pow--;
            
            // Divide
            numNodes = pow / (m - 1);
        }
    }
    
    // Create the tree
    for (int i = 1; i <= numNodes; i++)
        intTree.insert(i);
    
    // Print the tree
    cout << endl;
    intTree.print();
    
    // SYS_EXIT(0)
    return 0;
}// End method main
