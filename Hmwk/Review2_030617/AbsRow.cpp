/*
 * File: AbsRow.cpp
 * Author: Najera Enrique
 * Date: 06 March 2017
 * Purpose: Return array creation data
 */

// User Libraries
#include "AbsRow.h"

// Start accessor method  getSize
int AbsRow::getSize()const
{
    return size;
}// End accessor method  getSize

// Start accessor method  getData
int AbsRow::getData(int i) const
{
    return rowData[i];
}// End accessor method  getData
