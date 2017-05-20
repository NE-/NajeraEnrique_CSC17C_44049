/*
 * File: main.cpp
 * Author: Najera Enrique
 * Date: 26 May 2017
 * Purpose: Create a tree class with
 *          insert, delete, balance, print
 */

// System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// User Libraries
#include "Tree.h"

// Start method main
int main(int argc, char *argv[]){
    // Random number seed
    srand(time(0));
    
    // Declare and init variables
    int m = 0, // Number of children a parent can have
        h = 0; // Height of the tree
    
    int pow = 1;      // Holds power for equation solving 
                      // number of nodes
    int numNodes = 0; // Holds total number of nodes
    
    // Declare Objects
    Tree intTree;
    
    // Prompt for number of children
    // Found bug: crashes when m = 1
    cout << "Enter size m > 1 of m-ary tree: ";
    cin >> m;
    
    // Error checking
    if (m <= 1)cout << "\nm must be greater than 1!\n";
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
    
    // Create the tree with random numbers
    for (int i = 1; i <= numNodes; i++)
        intTree.insert(rand() % 100 + 1);
    
    // Print the tree before deletion
    cout << "\n\n~~~~~Tree before deletion~~~~~\n";
    
    cout << "\nPostorder\n";
    intTree.print(1);
    cout << "\nInorder\n";
    intTree.print(2);
    cout << "\nPreorder\n";
    intTree.print(3);
    
    // Delete a random number
    intTree.deleteNode(rand() % 100 + 1);
    
     // Print the tree after deletion
    cout << "\n\n~~~~~Tree before deletion~~~~~\n";
    
    cout << "\nPostorder\n";
    intTree.print(1);
    cout << "\nInorder Failed!\n";
    //intTree.print(2);
    cout << "\nPreorder\n";
    intTree.print(3);
    
    // SYS_EXIT(0)
    return 0;
}// End method main
