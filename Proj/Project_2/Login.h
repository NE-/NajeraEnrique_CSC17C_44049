/*
 * File: Login.h
 * Author: Najera Enrique
 * Date Due: 07 June 2017
 * Purpose: Login screen to implement hashing algorithms
 */

#ifndef LOGIN_H
#define LOGIN_H

// Start class Login
// Bug: when you sign up and try to sign in using
//      the new login info, it throws 'login unsuccessful,'
//      after signing in, press '3' (exit) and you're in
class Login{
    public:
        Login(){leave = false; loggedIn = false; size = 0;}
        ~Login(){delete [] loginHolder;}
        
        bool loginSuccess(){ return loggedIn; }
        
        void menu(); // Shows log in menu
        
        void signIn(); // Checks fake database for username + password
        void signUp(); // Creates an entry for new username + password
        
    private:
        bool loggedIn;    // Checks if log in success
        bool leave;       // Tells game to exit
        unsigned int *loginHolder; // Array to hold hashed login info
        int size;         // Holds size for allocating memory
        
        unsigned int BKDRHash(const std::string&);
        
        // Private Functions
        void scan(); // Counts contents in database
        void heapSort(unsigned int *, unsigned int); // Sorts database
        void heapify(unsigned int *, unsigned int, unsigned int); // Rearrange the heap
}; // End class Login

#endif /* LOGIN_H */

