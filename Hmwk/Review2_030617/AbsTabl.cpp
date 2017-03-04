/*
 * File: AbsTabl.cpp
 * Author: Najera Enrique
 * Date: 06 March 2017
 * Purpose: Implementation for AbsTabl
 */

// User Libraries
#include "AbsTabl.h"

// Start accessor method getSzRow
int AbsTabl::getSzRow() const
{
    return szRow;
}// End accessor method  getSzRow

// Start accessor method  getSzCol
int AbsTabl::getSzCol() const
{
    return szCol;
}// End accessor method  getSzCol

// Start accessor method getData
int AbsTabl::getData(int row, int col) const
{
    // Returns contents of array by row, by col
    return columns[row]->getData(col);
}// End accessor method  getData
