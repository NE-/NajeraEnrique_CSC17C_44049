/*
 * File: RowAray.cpp
 * Author: Najera Enrique
 * Date: 06 March 2017
 * Purpose: Implementation for AbsTabl
 */

// User Libraries
#include "RowAray.h"

// System Libraries
#include <cstdlib> // rand()

// Start constructor RowAray
RowAray::RowAray(unsigned int row)
{
    // INIT variables
    size = row;
    
    // Allocate memory for row data
    rowData = new int[row];
    
    // Fill rows with random numbers 
    for (int i = 0; i < row; i++)
    {
        rowData[i] = rand()%90+10;
    }
}// End constructor RowAray

// Start mutator setData
void RowAray::setData(int rows, int cols)
{
    // Prevents SEGFAULT errors (going over bounds)
    size = rows * cols;
}// End mutator setData

// Start destructor RowAray
RowAray::~RowAray()
{
    delete [] rowData;
}// End destructor RowAray
