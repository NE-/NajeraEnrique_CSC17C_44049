/*
 * File: Table.cpp
 * Author: Najera Enrique
 * Date: 06 March 2017
 * Purpose: Creates Array Table 
 */

// User Libraries
#include "Table.h"

// Start constructor Table
Table::Table(unsigned int row, unsigned int col)
{
    // Init variables
    szRow = row;
    szCol = col;
    
    // Allocate memory for array
    columns = new RowAray*[szRow];
    
    // Creates dummy 2D array
    for (int i = 0; i < row; i++)
    {
        columns[i] = new RowAray(i+col);
    }
}// End constructor Table

// Start copy constructor Table
Table::Table(const Table&obj)
{
    // Init variables
    szRow = obj.szRow;
    szCol = obj.szCol;
    
    // Allocate memory for array
    columns = new RowAray*[szRow];
    
    // Set content values of previous array to new copied array
    for (int i = 0; i < szRow; i++)
    {
        columns[i] = obj.columns[i];
    }
}// End copy constructor Table

// Start accessor method getData
int Table::getData(int rows, int cols) const
{
    // Returns contents of array
    return columns[rows]->getData(cols);
}// End accessor method  getData

// Start destructor Table
Table::~Table() 
{
    /*
     * ERROR: Deletes allocated memory of columns tab1 (main.cpp)
     *        then columns tab2 (main.cpp) for copy constructor
     *        so throws error that columns memory can't be accessed
     * 
     * Commenting the deletion process stops throwing error
     * but leaks memory
     */
    // Delete individual contents (Half of array)
    for (int i = 0; i < getSzRow(); i++)
    {
        delete columns[i];
    }
    
    // Delete the array itself (Other half)
    delete [] columns;
}// End destructor Table
