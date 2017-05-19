/*
 * File: BasicTree.h
 * Author: Najera Enrique
 * Date: 19 May 2017
 * Purpose: Hold basic tree implementation
 *          Structure and 
 */

#ifndef BASICTREE_H
#define BASICTREE_H

// User Libraries
#include "treeSeed.h"

// Start class BasicTree
class BasicTree{
    public:
        // Constructor initializes tree
        BasicTree(){ root = NULL; }
        
        // Destructor calls clearTree
        // for recursive cleaning
        ~BasicTree(){ clearTree(); }
        
        // Function Prototypes
        void insert(int);   // Inserts value to tree
        Node *search(int ); 
        void clearTree();
        void print();
    private:
        void clearTree(Node*);
        void hndlInsert(int , Node*);
        Node *search(int , Node*);
        void printBackwards(Node*, int);
        
        Node *root;
};// End class BasicTree

#endif /* BASICTREE_H */

