/* 
 * File:   RowAray.cpp
 * Author: Najera Enrique
 * Date: 01 March 2017
 * Purpose: Create 1D array of random numbers 10 - 90  
 */

// User Libraries
#include "RowAray.h"

// Start Constructor RowAray
RowAray::RowAray(int cols)
{
    // Init variables
    size = cols;
    
    // Dynamically allocate memory
    rowData = new int[size];
    
    // Fill Array
    for (int i = 0; i < size; i++)
        rowData[i] = rand() % 90 + 10;
    
}// End Constructor RowAray

// Start Destructor RowAray
RowAray::~RowAray()
{
    // Free allocated memory
    delete [] rowData;
}// End Destructor RowAray
