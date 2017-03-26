/*
 * Author: Dr. Mark E. Lehr
 * Created on March 8th, 2017, 8:01 PM
 * Purpose: Singularly Linked List
 * 
 * Edited By: Najera Enrique
 * Date Due: 29 March 2017
 * Purpose: Rewrite to implement template class
 */
#ifndef LINK_H
#define LINK_H

template <typename T>
struct Link{
    T data;
    Link *linkPtr;
};

#endif /* LINK_H */

