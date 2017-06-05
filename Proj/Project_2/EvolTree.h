/*
 * File: EvolTree.h
 * Author: Najera Enrique
 * Date Due: 07 June 2017
 * Purpose: Tree to hold evolution tree
 */

#ifndef EVOLTREE_H
#define EVOLTREE_H

// System Libraries
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

struct node {
    std::string data;
    struct node* left;
    struct node* right;
};

// Start class EvolTree
class EvolTree{
    // Constructor and Destructor
    public:
        EvolTree(){fill();} // Fill the tree
        ~EvolTree(){}
        
        // Function Prototypes
        void print(){print(root);} // Prints tree
    private:
        // Start method fill
        void fill(){
            // Add Pokemon to the tree
            root = newNode("THE ROOT OF ALL IS A MYSTERY!\n");
            
            root->left = newNode("Weak Grass");
            root->left->left = newNode("Intermediate Grass");
            root->left->right = newNode("Strong Grass");
            
            root->right = newNode("Weak Water");
            root->right->left = newNode("Intermediate Water");
            root->right->right = newNode("Strong Water\n");
            
            root->left->left->right= newNode("Weak Rock");
            root->left->left->right->left= newNode("Intermediate Rock");
            root->left->left->right->right= newNode("Strong Rock");
        } // End method fill
        
        // Start method print
        void print(struct node* node){
            if (node == NULL)
              return;
            
            /* first print data of node */
            std::cout << node->data << " ";  
            
            /* then recur on left subtree */
            print(node->left);

            /* now recur on right subtree */
            print(node->right);
        } // End method print
        
        // Start method newNode
        struct node* newNode(std::string data){
            struct node* node = new struct node;

            node->data = data;
            node->left = NULL;
            node->right = NULL;

            return (node);
        } // End method newNode

        // Declare Objects
        node *root;
}; // End class EvolTree

#endif /* EVOLTREE_H */

