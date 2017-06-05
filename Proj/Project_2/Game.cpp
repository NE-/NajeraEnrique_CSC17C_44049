/*
 * File: Game.cpp
 * Author: Najera Enrique
 * Date Due: 07 June 2017
 * Purpose: Main Game container
 *          Builds and draws map,
 *          Creates objects,
 *          Handles Game state: fighting, menu/pause
 */

// User Libraries
#include "Game.h"

// System Libraries
#include <iostream>
#include <iomanip>   // setw()
#include <cstdlib>   // rand()
#include <ctime>     // time()
#include <set>
#include <typeinfo>  // typeid()
#include <algorithm> // sort()

using namespace std;

// Start  constructor Game
Game::Game(){
    // Login before starting game
    login.menu();
    
    cout << "\nLOADING...\n";
    // Set random number seed
    srand(time(0));

    // Initialize variables
    viewport = 5;       // View up to 5 elements on X and Y
                        // Changing this could cause seg_fault
                        // If change is wanted, however, must also
                        // change the Player object's "if (camera_ < [int]) camera_++;"
                        // where '_' means 'X' or 'Y' and [int] means any integer value
                        // Its all trial and error and depends on the 'map' array size!!

    justFought = false; // Checks if player just fought a monster
                        // to prevent a fight loop on the same tile

    // Create our Pokemon
    // Format (type, health, level, power)
    // -Starter
    starter = new Pokemon("Weak Grass", 10, 3, 3);
    current = starter; // Our current Pokemon

    // -Water
    w_weak = new Pokemon("Weak Water", 8, 2, 2);
    w_inter = new Pokemon("Intermediate Water", 12, 5, 4);
    w_strong = new Pokemon("Strong Water", 18, 9, 6);

    // -Grass
    g_weak = new Pokemon("Weak Grass", 5, 2, 1);
    g_inter = new Pokemon("Intermediate Grass", 10, 5, 3);
    g_strong = new Pokemon("Strong Grass", 14, 9, 5);

    // -Rock
    r_weak = new Pokemon("Weak Rock", 6, 2, 2);
    r_inter = new Pokemon("Intermediate Rock", 14, 6, 6);
    r_strong = new Pokemon("Strong Rock", 20, 9, 8);

    // Fill our list with the starter
    mList = new MonList;
    MonList *prev = mList;
    prev->data = starter->getType();
    prev->linkPtr = NULL;
    MonList *end=new MonList;
    end->data=starter->getType();
    end->linkPtr=NULL;
    prev->linkPtr=end;
    prev=end;
    // End fill list

    // Fill our shop list
    sList_H = stockShop('h');
    sList_T = stockShop('t');

    // Create the map
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            // Create Border
            if (i == 0 || j == 0 || 
                j == 7 || i == 7)
                map[i][j] = '0';
            // Tall Grass
            else if (i >= 4 && j >= 4 && map[i][j] != '0')
                map[i][j] = 'v';
            // Concrete
            else if (i <= 4 && j >= 4 && map[i][j] != '0')
                map[i][j] = 'x';
            // Water
            else if (i == 6 && map[i][j] != 'x')
                map[i][j] = '~';
            // Hospital
            else if (i == 1 && j == 1)
                map[i][j] = 'H';
            // Evolution Tree
            else if (i == 3 && j == 1)
                map[i][j] = 'E';
            // Floor
            else map[i][j] = '.';
        }
    }
    // End creating map

    // Create our pokedex
    pokeDex.insert("Weak Grass");
    pokeDex.insert("Weak Water");
    pokeDex.insert("Weak Rock");

    pokeDex.insert("Intermediate Grass");
    pokeDex.insert("Intermediate Water");
    pokeDex.insert("Intermediate Rock");

    pokeDex.insert("Strong Grass");
    pokeDex.insert("Strong Water");
    pokeDex.insert("Strong Rock");

    p.setViewSet(false);    

    // If successfully logged in, start loop
    if (login.loginSuccess()){
        // Start our loop once elements successfully initialized
        cout << "======START!!======\n";
        cout << "*TIP: Use 'h' for help!!*\n\n";
        running = true;
    }
    // Else leave game
    else {
        running = false;
    }
}// End constructor Game

// Start destructor Game
Game::~Game(){
    // Destroy our Pokemon objects
    delete w_weak;
    delete w_inter;
    delete w_strong;
    delete g_weak;
    delete g_inter;
    delete g_strong;
    delete r_weak;
    delete r_inter;
    delete r_strong;
    
    // Delete the set just in case
    // No pointers so we can just clear it
    pokeDex.clear();  
    
    // Destroy MonList if it contains elements
    if (mList==NULL) ;
    else{
        do{
            MonList *temp=mList->linkPtr;
            delete mList;
            mList = temp;
        }while (mList!=NULL);
    }
}// End destructor Game

// Start method update
void Game::update(){
    p.update(); // Update our player
    
    // If player wants to see PokeDex, display
    if (p.getViewSet())dispSet();
    
    // If player quits, end game
    if (p.quits()){
        cout << "\nSHUTTING DOWN...\n";
        quitGame();
    }
}// End method update

// Start method checkBattle
// Checks if our player will fight
void Game::checkBattle(char lastCh){
    // Check water types
    if (lastCh == '~'){
        // 50% chance of a weak pokemon
        if (rand() % 100 < 75){
            fight(w_weak);
        }
        // 40 % chance of an intermediate pokemon
        else if (rand() % 100 < 40){
            fight(w_inter);
        }
        // 20% chance of a strong pokemon
        else if (rand() % 100 < 20){
            fight(w_strong);
        }
    }
    
    // Check grass type
    if (lastCh == 'v'){
        // 50% chance of a weak pokemon
        if (rand() % 100 < 50){
            fight(g_weak);
        }
        // 40 % chance of an intermediate pokemon
        else if (rand() % 100 < 30){
            fight(g_inter);
        }
        // 20% chance of a strong pokemon
        else if (rand() % 100 < 20){
            fight(g_strong);
        }
    }
    
    // Check rock type
    if (lastCh == 'x'){
        // 50% chance of a weak pokemon
        if (rand() % 100 < 75){
            fight(r_weak);
        }
        // 40 % chance of an intermediate pokemon
        else if (rand() % 100 < 40){
            fight(r_inter);
        }
        // 20% chance of a strong pokemon
        else if (rand() % 100 < 20){
            fight(r_strong);
        }
    }
    
    // Check if in hospital
    if (lastCh == 'H'){
        cout << "\nShop? (NOT YET IMPLEMENTED)\n";
        cout << "***Items in stock***\n";
        cout << "forwards: ";printShop_F(sList_H);
        cout << "\nbackwards:";printShop_B(sList_T);
        cout << endl;
    }
    
    // Check if in evolution tree
    if (lastCh == 'E'){
        cout <<"\nEVOLUTION TREE\n";
        evTree.print();
    }
}// End method checkBattle

// Start method fight
// Puts our game into a fighting state
void Game::fight(Pokemon *monster){
    // Declare Variables
    bool fighting = true; // Loops our fighting state
    
    //log.push_back(monster->getType()); UGLY OTUPUT
    
    // Output who approached us
    cout << "\nA " << monster->getType() 
         << " Level " << monster->getLevel() << " Appeared!!\n";
    // Output our Pokemon's current state
    cout << "\nYour Pokemon at hand: " << mList->data 
         << " Level " << current->getLevel() << endl;
    
    // The fighting loop
    while (fighting){
        // Output health of both
        cout << "\nYour Pokemon's Health: " << current->getHealth() << endl;
        cout << monster->getType() << "'s Health: " << monster->getHealth() << endl;
        
        // Prompt for player fighting action
        cout << "\nWhat do you do?\n";
        cout << "1) Attack " << endl
             << "2) Catch  " << endl
             << "3) Run    " << endl
             << "4) Use Heal" << endl
             << "Action: ";

        cin >> fAction;

        // If bad input, just leave
        if (cin.fail()) {
            // Log cin fail as 999
            log.push_back("CIN ERROR");
            cout << "\nGot Away Safely\n";
            cin.ignore();
            cin.clear();
            fighting = false;
            return;
        }
        
        // Static cast to prevent wrong type errors
        fAction = static_cast<int>(fAction);

        // Chose to attack
        if (fAction == 1){
            // Insert to log
            log.push_back("ATTACK");
            // Outputs user's available attacks
            cout << "\nYour Attacks\n";
            
            for (mIt = current->getAttacks().begin();
                    mIt != current->getAttacks().end(); mIt++){
                cout << mIt->first << " " << " Power: " << mIt->second;
                cout << endl;
            }
            
            // Prompt for attack (SOON)
            
            // Output attack used
            mIt = current->getAttacks().begin();
            cout << "\nYour " << current->getType() << " used "
                 << mIt->first << "!" << endl;
            
            // Decrease offending monster's attack
            monster->hit(mIt->second);
        }
        // Chose to catch
        else if (fAction  == 2){
            // Insert to log
            log.push_back("CATCH");
            
            // Dying health = easier catch (80%)
            if (monster->getHealth() <= 3){
                if (rand() % 100 < 80){
                    // Swap algorithm changes player's monster
                    std::swap(current, monster);
                    cout << "Successfully caught a " << current->getType() 
                            << "!" << endl;
                    // Add catch to our list
                    addBefore(mList, monster->getType(), current->getType());
                    // Fully heal new Pokemon
                    current->heal("full");
                    // Leave the fighting state
                    fighting = false;
                    return ;
                }
                else {
                    cout << "Failed to catch " << monster->getType() << endl;
                }
            }
            // Sick health = decent chance (50%)
            else if (monster->getHealth() > 3 && monster->getHealth() <=5){
                if (rand() % 100 < 50){
                    // Swap algorithm changes player's monster
                    std::swap(current, monster);
                    cout << "Successfully caught a " << current->getType() 
                            << "!" << endl;
                    // Add catch to our list
                    addBefore(mList, monster->getType(), current->getType());
                    // Fully heal new Pokemon
                    current->heal("full");
                    // Leave the fighting state
                    fighting = false;
                    return ;
                }
                else {
                    cout << "Failed to catch " << monster->getType() << endl;
                }
            }
            // Healthy = small chance (2%)
            else if (monster->getHealth() > 6){
                if (rand() % 100 < 2){
                    // Swap algorithm changes player's monster
                    std::swap(current, monster);
                    cout << "Successfully caught a " << current->getType() 
                            << "!" << endl;
                    // Add catch to our list
                    addBefore(mList, monster->getType(), current->getType());
                    // Fully heal new Pokemon
                    current->heal("full");
                    // Leave the fighting state
                    fighting = false;
                    return ;
                }
                else {
                    cout << "Failed to catch " << monster->getType() << endl;
                }
            }
            // Other, output failed to catch message
            else { cout << "Failed to catch " << monster->getType() << endl; }

        }
        // Chose to run
        else if (fAction == 3){
            // Insert to log
            log.push_back("RUN");
            cout << "\nGot Away Safely\n";
            fighting = false;
            return;
        }
        // Choose to heal player's monster
        else if (fAction == 4){
            // Log this event
            log.push_back("HEAL");
            
            // If no items, leave
            if (p.getItems().empty()){
                cout << "\nNO ITEMS!" << endl;
            }
            // If item, heal Pokemon accordingly
            else {
                cout << "\nUsed " << p.getItems().top() << " heal!" << endl;
                current->heal(p.getItems().top());
                
                cout << "\nYour Pokemon now has " << current->getHealth() 
                        << " health points!" << endl;
                
                // Remove item from list
                p.popItems();
            }
            
        }
        // If error, just leave
        else {
            // Insert to log
            log.push_back("OUT OF BOUNDS ERROR");
            cout << "\nGot Away Safely\n";
            fighting = false;
            return;
        }
        
                /*** Monster Action Handler ***/
        
        // Check if monster is dead before attacking
        // BUG SINCE I'M USING LINKED LIST FOR DISPLAYING POKEMON TYPE!!
        if (monster->getHealth() == 0){
            cout << "\n" << monster->getType() << " killed!" << endl;
            cout << "Your " << current->getType() << " leveled up "
                 << monster->getLevel() / 2 << "!" << endl;
            
            // Level up our monster
            current->lvlUp(monster->getLevel() / 2);
            
            // Change type if level is high
            if (current->getLevel() >= 5 && current->getLevel() <= 13 ){
                addBefore(mList, current->getType(), "Intermediate Grass"); // Add to list first!
                current->setType("Intermediate Grass"); // Should split 'type' & 'element'
            }
            else if (current->getLevel() >= 14 && current->getType() != "Strong Grass"){
                addBefore(mList, current->getType(), "Intermediate Grass"); // Add to list first!
                current->setType("Strong Grass");       // Should split 'type' & 'element'
            }
            
            // Reset attacker's health to prevent infinite level up
            monster->heal("full");
            
            // Leave fighting state
            fighting = false;
            return ;
        }
        
        // Low level 40% chance of attacking
        if (monster->getLevel() < 10){
            if (rand() % 100 < 40){
                // Outputs attack used
                mIt = monster->getAttacks().begin();
                cout << endl << monster->getType() 
                     << " used "  << mIt->first << "!\n";
                
                current->hit(monster->getPower()); // Decrease player health
            }
            else {
                cout << endl << monster->getType() << " failed to attack!\n";
            }
        }
        // Intermediate 60% chance of attacking
        else if (monster->getLevel() > 10 && monster->getLevel() < 14){
            if (rand() % 100 < 60){
                // Outputs attack used
                mIt = monster->getAttacks().begin();
                cout << endl << monster->getType() 
                     << " used "  << mIt->first << "!\n";
                
                current->hit(monster->getPower()); // Decrease player health
            }
            else {
                cout << endl << monster->getType() << " failed to attack!\n";
            }
        }
        // High levels 80% attack
        else {
            if (rand() % 100 < 80){
                // Outputs attack used
                mIt = monster->getAttacks().begin();
                cout << endl << monster->getType() 
                     << " used "  << mIt->first << "!\n";
                
                current->hit(monster->getPower()); // Decrease player health
            }
            else {
                cout << endl << monster->getType() << " failed to attack!\n";
            }
        }
        // End monster attack handler
        
        // If our Pokemon's health has dropped to or below 0
        // End game
        if (current->getHealth() <= 0){
            // Output game over message
            cout << "\n====Your Pokemon died!====\n";
            cout << "====Game Over====\n";
            
            // Print the list of Pokemon the player had
            prntList(mList);
            
            // Leave this loop
            fighting = false;
            
            // Leave the game
            quitGame();
            cout << "\n====Your Pokemon died!====\n";
            cout << "====Game Over====\n";
            cout << "\nPress any key to quit\n\n";
       }
    
    }// End fighting loop
        
    // Gives 1 step delay before Pokemon appear
    justFought = true;
}// End method fight

// Start method dispSet
void Game::dispSet(){
    cout << "\n=======PokeDex========\n";
    cout << "These are all the Pokemon found in this world\n";
    // Go through PokeDex set and output
    for (sIt = pokeDex.begin(); sIt != pokeDex.end(); sIt++)
        cout << *sIt << endl;
    cout << "\n=======Nontindo=======\n";
    p.setViewSet(false);
}// End method dispSet

// Start method dispLog displays the log
// Log contains user actions
void Game::dispLog(){
    // Declare Variables
    int i = 0; // Move counter
    cout << "\nYour attack log:\n";
    
    // Loop through log
    for (lIt = log.begin(); lIt != log.end(); lIt++){
        i++; // Increment move counter
        // Output move number and what user used against monster
        cout << setw(8) << "MOVE: " << i
             << setw(5) << "  USED: " << *lIt << endl;
    }// End for loop
    
    cout << "\nSorted log to count number of times "
         << "an action was used\n";
    
    // Declare counter variables
    int numAttack = 0;
    int numCatch  = 0;
    int numRun    = 0;
    int numHeal   = 0;
    
    // Sort algorithm
    log.sort();
    
    // Output and count
    for (lIt = log.begin(); lIt != log.end(); lIt++){
        cout << *lIt << endl;
        // BUG: DOESN'T COUNT FOR EACH
        // ONLY COUNTS FOR ONE ("ATTACK")!!
        // DEBUGGER'S CONSOLE DOESNT COOPERATE!!
        if (*lIt == "ATTACK")     numAttack++;
        else if (*lIt == "CATCH") numCatch++;
        else if (*lIt == "RUN")   numRun++;
        else if (*lIt == "HEAL")  numHeal++;
    }
    
    // Output count results
    cout << endl;
    cout << "Attacks used: " << numAttack << endl;
    cout << "Catches used: " << numAttack << endl;
    cout << "Times Ran:    " << numAttack << endl;
    cout << "Times Healed: " << numAttack << endl;
    cout << endl;
}// End method dispLog

// Start method quitGame
void Game::quitGame(){
    dispLog();       // Display the log
    running = false; // Quit our game loop
}// End method quitGame

// Start method draw
// Draws our game elements
void Game::draw(){
    // Get the last tile our player stepped on to overwrite it
    char lastChar = map[p.getPosY()][p.getPosX()];
    
    // Check if a Pokemon has approached us
    // If our player just fought, skip this
    if (p.getState() == 'p' && !justFought)checkBattle(lastChar);
    
    // Place our player in the world
    map[p.getPosY()][p.getPosX()] = '8';
    
    // Draw our map/world
    for (int i = p.getCameraY(); i < viewport + p.getCameraY(); i++){
        for (int j = p.getCameraX(); j < viewport + p.getCameraX(); j++){
            cout << setw(2) << map[i][j] << " ";
        }
        cout << endl;
    }
    
    // Overwrite the last character
    map[p.getPosY()][p.getPosX()] = lastChar;
    
    // We did not just fight
    justFought = false;
    
}// End method draw


        /*** Link List Functions ***/

// Start method addBefore
// BUG ADDS MORE THAN ONE!!
void Game::addBefore(MonList *front, string before, string val){
    MonList *next = front;           // Keeps track of next node
    MonList *prev = new MonList;     // Stores previous node
    MonList *newNode  = new MonList; // Creates new node for next value
    
    newNode->data = val; // Store value in newNode's data
    
    // Go through list until it hits position wanted
    while (next->linkPtr != NULL && next->data != before){
        // Clone everything before 'before'
        prev = next;
        next = next->linkPtr;
    }
    
    // Store newNode into the linked list
    prev->linkPtr = newNode;
    newNode->linkPtr = next;
}// End method addBefore

// Start method printList prints our Pokemon all game
void Game::prntList(MonList *front){
    cout << "\nYour Pokemon\n";
    MonList *next=front; //Start at the front of the list
    cout<<endl;          //Put the beginning on a new line
    do{
        cout<<setw(4)<<next->data<<" "; //Print the link
        next=next->linkPtr;             //Go to the next link
        cout << endl;
    }while(next!=NULL);                 //Stop when your at the end
    cout<<endl;

}// End method printList

// Start method stockShop
// Takes in char 'h' for returning the HEAD
// Takes in char 't' for returning the TAIL
// else return HEAD
Shop *Game::stockShop(char loc){
    Shop *head; // Head
    Shop *tail; // End
    Shop *n;    // Next
    
    // Full heal
    n = new Shop;
    n->data = "Full";
    n->prev = NULL;   // First node has no previous
    head = n;
    tail = n;
    
    // Half heal
    n = new Shop;
    n->data = "Half";
    n->prev = tail;
    tail->next = n;
    tail = n;
    
    // Small heal
    n = new Shop;
    n->data = "Small";
    n->prev = tail;
    tail->next = n;
    tail = n;
    
    // Close list
    tail->next = NULL;
    
    // Check the argument for proper return
    if (loc == 't' || loc == 'T') return tail;
    else return head;
}// End method stockShop

// Start method printShop_F
void Game::printShop_F(Shop *head){
    Shop *temp = head; // Points to front of list
    
    // Print while data
    do {
        cout << temp->data << " ";
        temp = temp->next; // Point to next node
    }while(temp != NULL);
    cout << endl;
}// End method printShop_F

// Start method printShop_B
void Game::printShop_B(Shop *tail){
    Shop *temp = tail; // Points to end of list
    
    // Print while data
    do {
        cout << temp->data << " ";
        temp = temp->prev; // Point to previous node
    }while(temp != NULL);
    cout << endl;

}// End method printShop_B
