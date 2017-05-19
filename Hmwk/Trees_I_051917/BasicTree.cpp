// System Libraries
#include <iostream>
#include <iomanip> // setw
using namespace std;

// User Libraries
#include "BasicTree.h"

// Start method insert
void BasicTree::insert(int val){
    // If NULL or exists, handle
    if(root != NULL)
        hndlInsert(val, root);
    
    else {
        root=new Node;    // Allocate memory for new node
        root->data=val;   // Set value
        root->left=NULL;  // Create left child
        root->right=NULL; // Create right child
    }
}// End method insert

// Start method hndlInsert
void BasicTree::hndlInsert(int val, Node* leaf){
    // If less than, go left
    if(val < leaf->data)
    {
        // Handle
        if(leaf->left!=NULL)
            hndlInsert(val, leaf->left);
        else{
            // Empty node
            leaf->left = new Node;   // Create new node
            leaf->left->data = val;  // Set value
            leaf->left->left = NULL; // Create left child
            leaf->left->right=NULL;  // Create right child
        }  
    }
    // If greater than, go right
    else if(val >= leaf->data)
    {
        // Handler
        if(leaf->right!=NULL)
            hndlInsert(val, leaf->right);
        else{
            // Empty node
            leaf->right=new Node;    // Create new node
            leaf->right->data=val;   // Set value
            leaf->right->left=NULL;  // Create left child
            leaf->right->right=NULL; // Create right child
      }
    }
}// End method hndlInsert

// Start method clearTree deallocates memory
void BasicTree::clearTree(Node* leaf){
    // If leaf (bottom) has data
    if (leaf != NULL){
        clearTree(leaf->left);  // Clear left
        clearTree(leaf->right); // Clear right
        delete leaf;
    }
}// End method clearTree

// Start method clearTree
void BasicTree::clearTree()
{
  clearTree(root);
}// End method clearTree

// Start method print
void BasicTree::print(){
    // Public since only the class has
    // access to the tree
    printBackwards(root, 0);
}// End method print

// Start method printPreorder
// Taken and edited from class assignment 17 May 2017
// 'c' argument is a counter for clean output
void BasicTree::printBackwards(Node* node, int c)
{
    c++; // Increment counter
    
    if (node == NULL)
        return;
    
    // then recur on left sub tree 
    printBackwards(node->left, c); 

    // now recur on right subtree 
    printBackwards(node->right, c);
    
    // first print data of node 
    cout << setw(4) << node->data << " "; 
    
    // Output as 10's
    if (c % 10 == 0) cout << endl;
}// End method printPreorder
