/*
 * File: Game.h
 * Author: Najera Enrique
 * Date Due: 07 June 2017
 * Purpose: The game's main logic and drawing
 */

#ifndef GAME_H
#define GAME_H

// System Libraries
#include <map>
#include <set>
#include <list>

// User Libraries
#include "Login.h"
#include "Player.h"
#include "Pokemon.h"
#include "MonsterList.h"
#include "ShopList.h"
#include "EvolTree.h"

// Sorts the pokeDex set by string length
struct SortOrder {
    // Operator overload
    bool operator()(const string &first, const string &second){
        // Get the length of strings
        int length1 = first.length();
        int length2 = second.length();

        // If same length, return alphabetical order
        if (length1 == length2)
            return (first < second);
        return (length1 < length2);
    }
};

// Start class Game
class Game{
    public:
        // Constructor & Destructor
        Game();
        ~Game();
        
        // Function Prototypes
        bool isRunning(){return running;} // Should our game run
        void update();                    // Update logic
        void draw();                      // Draw based on updated logic
        void quitGame();                  // Quits the game
        void checkBattle(char);           // Check if we are in a battle state
        void fight(Pokemon *);            // Actual fighting state
        void dispSet();                   // Displays the set, or PokeDex
        void dispLog();                   // Displays the list, or program log
        Shop *stockShop(char);            // Fills doubly linked list with items
        void printShop_F(Shop *);         // Print shop in a forward fashion
        void printShop_B(Shop *);         // Print shop in a backward fashion
        
        // -Link List Functions
        void addBefore(MonList *, string, string);
        void prntList(MonList *);
        
    private:
        // Declare Variables
        bool running;    // is/should the game (be) running 
        bool justFought; // Did the player just fight
        int fAction;     // Holds fighting action player has provided
        
        char map[8][8];  // Map/World container
                         // Was dynamic and read from a file, but
                         // that caused too much seg_fault errors
                         // and delimiter errors
        int viewport;    // How much of the world to display on camera

        // Declare Objects
        std::set<string, SortOrder>pokeDex; // Holds all pokemon names 
                                            // in the current world
        std::list<string>log;               // Holds log of player input
        
        Login login;    // Login object
        Player p;       // Player
        MonList *mList; // List of Pokemon the player has
        Shop *sList_H;  // List of item in shop (holds the Head)
        Shop *sList_T;  // List of item in shop (holds the Tail)
        EvolTree evTree; // List of monsters and their evolutions
        
        // -Pokemon Objects
        Pokemon *starter;  // Starter, or default, Pokemon
        Pokemon *current;  // Holds current Pokemon our player is using
        
        Pokemon *w_weak;   // Weak Water
        Pokemon *w_inter;  // Intermediate Water
        Pokemon *w_strong; // Strong Water
        
        Pokemon *g_weak;   // Weak Grass
        Pokemon *g_inter;  // Intermediate Grass
        Pokemon *g_strong; // Strong Grass
        
        Pokemon *r_weak;   // Weak Rock
        Pokemon *r_inter;  // Intermediate Rock
        Pokemon *r_strong; // Strong Rock
        
        // Declare iterators
        std::map<string, int>::iterator mIt; // Loops through Pokemon attacks
        std::set<string>::iterator sIt;      // Loops through PokeDex
        std::list<string>::iterator lIt;     // Loops through log

};// End class Game

#endif /* GAME_H */
