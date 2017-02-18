/*
 * File: Table.cpp
 * Author: Najera Enrique
 * Date: 01 March 2017
 * Purpose: Create a table upon RowAray
 */

// User Libraries
#include "Table.h"

// Start Constructor Table
Table::Table(int rows, int cols)
{
    // Init Variables
    szRow = rows;
    szCol = cols;
    
    // Dynamically allocate memory
    records = new RowAray*[szRow];
    
    // Fill the Array
    for (int row = 0; row < szRow; row++)
        for (int col = 0; col < szCol; col++)
            records[row] = new RowAray(szCol);
    
}// End Constructor Table

// Start method getData
Table::getData(int row, int col)
{
    // Returns variables in array
    for (int i = 0; i < szRow; i++)
        for (int j = 0; j < szCol; j++)
            return records[row]->getData(col);
}// End method getData

// Start Destructor Table
Table::~Table() 
{
    // Delete rows
    for (int i = 0; i < szRow; i++)
        delete records[i];
        
    // Delete whole
    delete [] records;
}// End Destructor Table
