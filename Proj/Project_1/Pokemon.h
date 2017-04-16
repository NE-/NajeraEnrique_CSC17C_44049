/*
 * File: Pokemon.h
 * Author: Najera Enrique
 * Date Due: 17 April 2017
 * Purpose: Holds Pokemon properties
 */

#ifndef POKEMON_H
#define POKEMON_H

// System Libraries
#include <map>    // Holds Pokemon's power
#include <string>
using namespace std;

// Start class Pokemon
class Pokemon{
    public:
        // Default constructor
        Pokemon(){
            // INIT everything to 1
            health = 1;
            type = 1;
            level = 1;
        };// End default constructor
        
        // Constructor 
        // Takes in a type, total health, level, power of attacks
        Pokemon(string t, int h, int l, int p){
            health = h;
            maxHealth = h;
            type = t;
            level = l;
            power = p;
            
            // Check type and assign attacks
            // Map is
            if (type == "Weak Grass"){
                // Weak types only have 2 attacks
                attacks["Tackle"] = 1;
                attacks["Defend"] = 1;
            }
            else if (type == "Intermediate Grass"){
                // Intermediate types have 3 attacks
                attacks["Tackle"] = 1;
                attacks["Whip"] = 3;
                attacks["Absorb"] = 2;
            }
            else if (type == "Strong Grass"){
                // Strong types have all 4 attacks
                attacks["Whip"] = 3;
                attacks["Absorb"] = 2;
                attacks["Photosynthesis"] = 5;
                attacks["Spore"] = 4;
            }
            
            else if (type == "Weak Water"){
                // Weak types only have 2 attacks
                attacks["Tackle"] = 2;
                attacks["Defend"] = 1;
            }
            else if (type == "Intermediate Water"){
                // Intermediate types have 3 attacks
                attacks["Tackle"] = 2;
                attacks["Splash"] = 2;
                attacks["Wave"] = 4;
            }
            else if (type == "Strong Water"){
                // Strong types have all 4 attacks
                attacks["Splash"] = 2;
                attacks["Wave"] = 4;
                attacks["Whirlpool"] = 5;
                attacks["Tsunami"] = 6;
            }
            
            else if (type == "Weak Rock"){
                // Weak types only have 2 attacks
                attacks["Tackle"] = 2;
                attacks["Defend"] = 1;
            }
            else if (type == "Intermediate Rock"){
                // Intermediate types have 3 attacks
                attacks["Tackle"] = 1;
                attacks["Throw"] = 6;
                attacks["Quake"] = 5;
            }
            else if (type == "Strong Rock"){
                // Strong types have all 4 attacks
                attacks["Throw"] = 6;
                attacks["Quake"] = 8;
                attacks["Crush"] = 5;
                attacks["Sandstorm"] = 8;
            }
        }; // End Constructor
        
        // Destructor
        ~Pokemon(){
            // Delete our map just in case
            attacks.clear();
        };
        
        // Function Prototypes
        void hit(int p){health -= p;}    // Removes health by power of attacker
        void lvlUp(int lU){level += lU;} // Levels Pokemon up
        void heal(string med){
            // If already at full health, leave
            if (health == maxHealth) return;
            
            // If given full medicine, fill health
            // to max health
            if (med == "full"){
                health = maxHealth;
            }
            // If given half medicine, fill health
            // half of max
            else if (med == "half"){
                health += maxHealth / 2;
                // If previous calculation exceeds the max health,
                // health is our maxHealth
                if (health > maxHealth)
                    health = maxHealth;
            }
            // If given small dosage, add health by 2
            else if (med == "small"){
                health += 2;
                // If previous calculation exceeds the max health,
                // health is our maxHealth
                if (health > maxHealth)
                    health = maxHealth;
            }
            // If some kind of arg error, return
            else { return; }  
            
        }
        
        // Mutator Functions
        void setType(string t){type = t;}
        
        // Accessor Functions
        int getHealth() const {return health;}
        string getType() const {return type;}
        int getPower() const {return power;}
        int getLevel() const {return level;}
        map <string, int> getAttacks() const {return attacks;}
    private:
        // Declare Variables
        int health;    // Pokemon's total health
        int maxHealth; // Pokemon's maxHealth for healing
        string type;   //Pokemon's type
        int level;     // Pokemon's level
        int power;     // Pokemon's attack power
        
        map<string, int>attacks; // Holds list of attacks
                                 // Keytype (string) = name of attack
                                 // Value (int)      = power of attack
};// End class Pokemon

#endif /* POKEMON_H */
