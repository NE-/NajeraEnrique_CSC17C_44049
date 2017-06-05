/*
 * File: main.cpp
 * Author: Najera Enrique
 * Date Due: 07 June 2017
 * Purpose: Main game loop for Project 1 - Pokemon
 */

// User Libraries
#include "Game.h"

// Start method main handles game loop
int main(int argc, char** argv) {
    // Declare Objects
    Game g;
    
    // After game has been initialized
    while (g.isRunning()){
        g.draw();   // Draw our game at default settings
        g.update(); // Update our game
    }
    
    // SYS_EXIT
    return 0;
}// End method main
