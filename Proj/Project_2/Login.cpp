/*
 * File: Login.cpp
 * Author: Najera Enrique
 * Date Due: 07 June 2017
 * Purpose: Login screen to implement hashing algorithms
 */

// System Libraries
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

// User Libraries
#include "Login.h"

// Start method scan
void Login::scan(){
    ifstream inFile("users.pokeDB"); // File object
    
    // Count lines in file
    size = count(istreambuf_iterator<char>(inFile),
          istreambuf_iterator<char>(), '\n');
    
    // Allocate memory
    // One size larger just in case
    loginHolder = new unsigned int[size + 1];
    
    // Bug: output differs, but using unsigned ints 
    // causes stuck on an infinite loop
    if (loginHolder != nullptr){
        ifstream inDB;
        unsigned int getHashes = 0;
        int i = 0;
        
        // Assign every array index to a hashed value
        inDB.open("users.pokeDB");
        // Different numbers
        while (inDB >> getHashes)
            loginHolder[i] = reinterpret_cast<unsigned int>(getHashes);
        inDB.close();
    }
    
    // Recursive sort
    // Either fails or succeeds
    heapSort(loginHolder, size);
    
    // Output sorted array to a file
    // Delete file to see results
    ofstream ofSorted;
    
    ofSorted.open("sorted_users.pokeDB", ios::app);
        // Go through sorted array and output to file
        for (int i = 0; i < size; i++)
            ofSorted << loginHolder[i] << endl;
    ofSorted.close();
}// End method scan

// Start method menu
void Login::menu(){
    scan(); // Scan the database for sorting
    
    int choice = 0; // Holds menu choice

    // Prompt for choice
    cout << "____Pokemon CSC 17 C____" << std::endl;
    cout << "1) Sign In\n2) Sign Up\n3) Exit\n";
    cin >> choice;
    
    // Check choice
    switch (choice){
        case 1:
            signIn();
            break;
        case 2:
            signUp();
            break;
        default:
            /*
             *  Bug if sign in fail
             *  Repeats sign in error message
             */
            cout << "Exiting...\n";
            leave = true;  
            break;
    }
}// End method menu

// Start method signIn
void Login::signIn(){
    /*
     * Default login
     * user & pass = admin : password
     */
    ifstream inDB;
    
    string user = "";
    string pass = "";
    unsigned int dbHash = 0;
    unsigned int hash = 0;
    
    // Prompt for username and password
    cout << "Enter username: ";
    cin >> user;
    cout << "\nEnter password: ";
    cin >> pass;
    
    // Check database for hashed values
    // Bad Practice: could be cracked by key generator
    hash = BKDRHash(user + pass);
    inDB.open("users.pokeDB");
        while (inDB >> dbHash){
            if (hash == dbHash){
                loggedIn = true;
                break;
            }
            else {
                cout << "\n\nUsername and/or password incorrect!\n\n";
                menu();
            }
        }
    inDB.close();
}// End method signIn

// Start method signUp
void Login::signUp(){
    /*
     * Bug: after sign up, new username and password
     * fail, but exiting lets user through
     * First time users must make account!
     */
    ofstream outDB; // Stream object for database storage
    
    string user = "";
    string pass = "";
    unsigned int hash = 0;
    
    // Prompt for username and password
    cout << "Enter a new username: ";
    cin >> user;
    cout << "\nEnter password for " << user << ": ";
    cin >> pass;

    // Hash info
    hash = BKDRHash(user + pass);
    
    // Open our database
    outDB.open("users.pokeDB", ios::app);
        // Write to database
        outDB << hash << endl;
        cout << "\n\nSignup Success!!\n\n";
    outDB.close();
    
    // Reload the menu
    menu();
    
}// End method signUp

// Start method BKDRHash
/*
 * Taken from "GeneralHashFunctions.cpp" assignment
 * http://www.partow.net/programming/hashfunctions/index.html 
 */
unsigned int Login::BKDRHash(const std::string& str){
    // Declare Variables
    unsigned int seed = 131;
    unsigned int hash = 0;
    
    // Go through each character and encrypt
    for (std::size_t i = 0; i < str.length(); i++){
        hash = (hash * seed) + str[i];
    }
    
    // Return encrypted string as UINT
    return hash;
}// End method BKDRHash

// Start method heapify
void Login::heapify(unsigned int *a, unsigned int n, unsigned int i){
    // Declare and Initialize Variables
    unsigned int largest = i;       // Holds largest index
    unsigned int left = 2 * i + 1;  // Left side
    unsigned int right = 2 * i + 2; // Right side
    
    // Check largest index
    if (left < n && a[left] > a[largest])
        largest = left;
    
    if (right < n && a[right] > a[largest])
        largest = right;
    
    if (largest != i){
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}// End method heapify

// Start method heapSort
void Login::heapSort(unsigned int *a, unsigned int n){
    for (int i=n/2-1; i>=0;i--)
        heapify(a, n, i);
    for (int i=n-1; i>=0; i--){
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}// End method heapSort
