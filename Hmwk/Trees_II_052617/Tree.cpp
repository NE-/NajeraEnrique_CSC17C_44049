// System Libraries
#include <iostream>
#include <iomanip> // setw
using namespace std;

// User Libraries
#include "Tree.h"

// Start method insert
void Tree::insert(int val){
    // If NULL or exists, handle
    if(root != NULL)
        balance(val, root);
    
    else {
        root=new Node;    // Allocate memory for new node
        root->data=val;   // Set value
        root->left=NULL;  // Create left child
        root->right=NULL; // Create right child
    }
}// End method insert

// Start method balance
void Tree::balance(int val, Node* leaf){
    // If less than, go left
    if(val < leaf->data)
    {
        // Handle
        if(leaf->left!=NULL)
            balance(val, leaf->left);
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
            balance(val, leaf->right);
        else{
            // Empty node
            leaf->right=new Node;    // Create new node
            leaf->right->data=val;   // Set value
            leaf->right->left=NULL;  // Create left child
            leaf->right->right=NULL; // Create right child
      }
    }
}// End method hndlInsertbalance

// Start method deleteNode
void Tree::deleteNode(int val){
    hndlDelete(val, root);
}// End method deleteNode

// Start method hndlDelete
void Tree::hndlDelete(int val, Node* leaf){
    Node* next = leaf; // Keep track of current "leaf"
    Node* temp = leaf;
    
    if (leaf != NULL){
        // If value found, delete
        if (leaf->data == val){
            delete leaf;
            leaf->data = 0;
        }
            
        // If val < current leaf value, go left
        if (val < leaf->data)
            hndlDelete(val, leaf->left);
        // Else, must be greater so go right
        else
            hndlDelete(val, leaf->right);
    }
    // After going through entire tree
    // Bug this always shows up
    else
        cout << endl << endl << val << " was not found!" << endl; 
}// End method hndlDelete

// Start method clearTree deallocates memory
void Tree::clearTree(Node* leaf){
    // If leaf (bottom) has data
    if (leaf != NULL){
        clearTree(leaf->left);  // Clear left
        clearTree(leaf->right); // Clear right
        delete leaf;
    }
}// End method clearTree

// Start method clearTree
void Tree::clearTree()
{
  clearTree(root);
}// End method clearTree

// Start method print
void Tree::print(int o){
    // o = 1 POSTORDER
    // o = 2 INORDER
    // o = 3 PREORDER
    o = static_cast<int>(o); // Static cast just in case
    
    // If bad input, INIT arg to 1
    if (o > 3 || o <= 0)
        o = 1;
    
    // Public since only the class has
    // access to the tree
    if (o == 1)printPostorder(root);
    else if (o == 2)printInorder(root);
    else if (o == 3)printPreorder(root);
}// End method print


// Taken and edited from class assignment 17 May 2017
/* Given a binary tree, print its nodes according to the
   "bottom-up" postorder traversal. 
 */
// Start method printPostorder
void Tree::printPostorder(Node* node)
{
    if (node == NULL)
        return;

    // first recur on left subtree
    printPostorder(node->left);

    // then recur on right subtree
    printPostorder(node->right);

    // now deal with the node
    cout << node->data << " ";  
}// End method printPostorder

// Start method printInorder
/* Given a binary tree, print its nodes in inorder*/
void Tree::printInorder(Node* node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    cout << node->data << " "; 

    /* now recur on right child */
    printInorder(node->right);
}// End method printInorder

// Start method printPreorder
/* Given a binary tree, print its nodes in preorder*/
void Tree::printPreorder(Node* node)
{
    if (node == NULL)
        return;
    
    /* first print data of node */
    cout << node->data << " "; 

    /* then recur on left sutree */
    printPreorder(node->left); 

    /* now recur on right subtree */
    printPreorder(node->right);
}// End method printPreorder
