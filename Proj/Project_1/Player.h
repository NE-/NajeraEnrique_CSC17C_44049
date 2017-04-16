/*
 * File: Player.h
 * Author: Najera Enrique
 * Date Due: 17 April 2017
 * Purpose: Contains our Player properties
 *          Also updates movement
 */

#ifndef PLAYER_H
#define PLAYER_H

// System Libraries
#include <stack>
#include <string>

// Start class Player
class Player{
    public:
        // Constructor & Destructor
        Player();
        ~Player(){items.empty();}

        // Function Prototypes
        void update();   // Handle user input
        void outHelp();  // Outputs a help page
        void popItems(){items.pop();} // Uses the stack's 'pop' algorithm

        // Mutator Functions
        void setState(char s){state = s;}     // Sets player's state
        void setViewSet(bool b){viewSet = b;} // Sets if PokeDex set 
                                              // should be displyed

        // Accessor Functions
        int getCameraX() const {return cameraX;}   // Get our camera's x position
        int getCameraY() const {return cameraY;}   // Get our camera's y position
        int getPosX()    const {return posX;}      // Get our player's x position
        int getPosY()    const {return posY;}      // Get our player's y position
        char getState()  const {return state;}     // Get our player's state
        bool getViewSet() const { return viewSet;} // View pokeDex set?
        std::stack<std::string> getItems() const {return items; } // Get inventory
        bool quits() const {return quit;};         // Did player just quit

    private:
        // Declare Variables
        int cameraX;  // Holds camera's x position
        int cameraY;  // Holds camera's y position
        int posX;     // Holds player's x position
        int posY;     // Holds player's y position
        char action;  // Holds player input
        char state;   // Holds player's state
        bool viewSet; // Tells game to display PokeDex set
        bool quit;    // Holds if player decided to quit
        
        // Declare Objects
        std::stack<std::string>items; // Holds all our items
};// End class Player

#endif /* PLAYER_H */

