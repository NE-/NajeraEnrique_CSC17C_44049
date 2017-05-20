/*
 * File: Tree.h
 * Author: Najera Enrique
 * Date: 26 May 2017
 * Purpose: Tree with insert, delete, balance, and print features
 */

#ifndef TREE_H
#define TREE_H

// User Libraries
#include "treeSeed.h"

// Start class BasicTree
class Tree{
    public:
        // Constructor initializes tree
        Tree(){ root = NULL; }
        
        // Destructor calls clearTree
        // for recursive cleaning
        ~Tree(){ clearTree(); }
        
        // Function Prototypes
        void insert(int);     // Inserts value to tree
        void deleteNode(int); // Deletes a node based on value
        void clearTree();     // Deallocates memory
        void print(int);      // prints tree, arg takes order type
    private:
        void clearTree(Node*);       // Deallocates memory
        void balance(int, Node*);    // Handles insertions/balances
        void hndlDelete(int, Node*); // Deletes node based on value
        void printPostorder(Node*);  // prints postorder
        void printInorder(Node*);    // prints inorder
        void printPreorder(Node*);   // prints preorder
        
        // Declare objects
        Node *root;
};// End class BasicTree

#endif /* TREE_H */

