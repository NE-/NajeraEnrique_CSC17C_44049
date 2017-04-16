/*
 * File: MonsterList.h
 * Author: Najera Enrique
 * Date Due: 17 April 2017
 * Purpose: Holds a list of monsters the player has caught
 */

#ifndef MONSTERLIST_H
#define MONSTERLIST_H

// System Libraries
#include <string>

//Start structure MonList
struct MonList {
    string data;      // Holds Pokemon's type
    MonList *linkPtr; // Pointer to next data
};// End structure MonList

#endif /* MONSTERLIST_H */
