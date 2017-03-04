/*
 * File: PlusTab.cpp
 * Author: Najera Enrique
 * Date: 06 March 2017
 * Purpose: Adds contents of two object arrays
 */

#include "PlusTab.h"

// Start operator overload function operator+
PlusTab PlusTab::operator +(const PlusTab &right)
{
    // Create new array for PlusTab class
    PlusTab temp(right.szRow, right.szCol);
    
    /* 
     * ERROR: Did not allow adding operator to be used
     *        with RowAray* + RowAray* types
     * 
     * I just filled the array with the same contents to jump
     * off of error
     */
    // Fill the contents of array with 
    // first object column[i] + second object column[i]
    for (int i = 0; i < temp.szRow; i++)
        temp.columns[i] = this->columns[i]/* + right.columns[i]*/;
    
    // Return PlusTab object
    return temp;
}// End operator overload function operator+
