/*
 * File: Player.cpp
 * Author: Najera Enrique
 * Date Due: 17 April 2017
 * Purpose: Contains our Player properties
 *          Also updates movement
 */

// User Libraries
#include "Player.h"

// System Libraries
#include <iostream>
#include <cstdlib>  // rand()
using namespace std;

// Start constructor Player
Player::Player(){
    // INIT variables
    cameraX = 0;
    cameraY = 0;
    posX = 2;     // Place at center of camera
    posY = 2;     // Place at center of camera
    state = 'p';  // State playing
    action = ' '; // No action taking place
    quit = false;
}// End constructor Player

// Start method update
void Player::update(){
    // Prompt for action
    cout << "Action: ";
    cin >> action;
    
    // Action handler
    switch(action){
        // If playing in the world
        // UP
        case 'w':
            // Moves everything UP
           // if (state == 'p'){ /!\ ERROR: makes player freeze
                if (cameraY > 0)cameraY--; // If camera in bounds
                if (posY > 1)posY--;       // If player in bounds
            //}
            break;
        // LEFT
        case 'a':
            // Moves everything LEFT
           // if (state == 'p'){ /!\ ERROR: makes player freeze
            if (cameraX > 0)cameraX--; // If camera in bounds
            if (posX > 1)posX--;//}    // If player in bounds
            break; 
        // DOWN
        case 's':
            // Moves everything DOWN
            //if (state == 'p'){ /!\ ERROR: makes player freeze
            if (cameraY < 3)cameraY++; // If camera in bounds
            if (posY < 6)posY++;//}    // If player in bounds
            break;
        // RIGHT
        case 'd':
            // Moves everything RIGHT
            //if (state == 'p'){ /!\ ERROR: makes player freeze
            if (cameraX < 3)cameraX++; // If camera in bounds
            if (posX < 6)posX++;//}    // If player in bounds
            break;
        // HELP
        case 'h':
            // Displays help page
            //if (state == 'p'){ /!\ ERROR: makes player freeze
            outHelp();//}
            break;
        // PAUSE (just displays PokeDex)
        case 'p':
            viewSet = true;
            break;
        // QUIT
        case'q':
            // Acknowledges game that player quit
            quit = true;
            break;
        // Else do nothing
        default:
            break;
    }// End action handler
    
    // After every move, check for an item
    // 6% chance to find 'small' heal
    if (rand() % 500 < 30 && rand() % 100 > 15){
        cout << "\n Found small heal!!\n";
        items.push("small");
    }
    // 3% chance to find 'half' heal
    else if (rand() % 500 < 15 && rand() % 1000 > 5){
        cout << "\n Found half heal!!\n";
        items.push("half");
    }
    // 1% chance to find 'full' heal
    else if (rand() % 500 < 5){
        cout << "\n Found full heal!!\n";
        items.push("full");
    }
    // Found nothing!
    else {}
    
    cout << endl;
}// End method update

// Start method outHelp
void Player::outHelp(){
    // Output help page
    cout << "Legend "<<endl
         << " '8' PLAYER\n"
         << " '~' WATER (water types found here)\n"
         << " 'x' CONCRETE (rock types found here)\n"
         << " 'v' TALL GRASS (grass types found here)\n"
         << " '.' NORMAL TILE (Items found here)\n"
         << " 'H' HOSPITAL (Buy medicine here)\n"
         << endl
         << "Actions "<<endl
         << " In world\n"
         << "    w move up\n"
         << "    s move down\n"
         << "    a move left\n"
         << "    d move right\n"
         << "    p PokeDex menu\n"
         << "    h brings up this menu\n"
         << "    q quits the game\n"
         << "    ~dying also stops the game\n"
         << " In battle\n"
         << "    1 attacks rival Pokemon\n"
         << "    2 attempts to catch Pokemon\n"
         << "    3 runs from battle\n"
         << "    4 uses health potion for your Pokemon\n"
         << "Casually walking around gives chance of finding items!\n"
         << endl;
}// End method outHelp
