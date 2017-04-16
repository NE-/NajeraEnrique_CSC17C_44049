/*
 * File: ShopList.h
 * Author: Najera Enrique
 * Date Due: 17 April 2017
 * Purpose: Doubly linked list used as a shop
 *          so the user could buy items
 */

#ifndef SHOPLIST_H
#define SHOPLIST_H

// System Libraries
#include <string>

struct Shop{
    std::string data;
    Shop *next;
    Shop *prev;
};

#endif /* SHOPLIST_H */

