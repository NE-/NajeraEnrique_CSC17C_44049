/*
 * File: main.cpp
 * Author: Najera Enrique
 * Purpose: Main game loop for Project 1 - Pokemon
 * Date Due: 17 April 2017
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
