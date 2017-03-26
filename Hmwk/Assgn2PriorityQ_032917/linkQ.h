/*
 * File: linkQ.h
 * Author: Najera Enrique
 * Date: 29 March 2017
 * Purpose: Create a priority queue linked list
 */
#ifndef LINKQ_H
#define LINKQ_H

template <typename T>
struct LinkQ{
    T data;
    int priority;
    LinkQ *linkPtr;
};

#endif /* LINKQ_H */

