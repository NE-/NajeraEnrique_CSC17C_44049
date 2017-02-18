/*
 * File: Triangle.cpp
 * Author: Najera Enrique
 * Date: 01 March 2017
 * Purpose: Create a triangular array
 */

// User Libraries
#include "Triangle.h"
#include "Table.h"

// Start Constructor Triangle
Triangle::Triangle(int rows) 
{
    //Init Variables
    szRow = rows;
    
    // Dynamically allocate memory
    records = new RowAray*[szRow];
    
    // Fill the array
    for (int row = 0; row < szRow; row++)
        for (int col = 0; col < szRow; col++)
            records[row] = new RowAray(szRow);
}// End constructor Triangle

// Start method getData
int Triangle::getData(int row, int col)
{
    // Return variables in array
    for (int i = 0; i < szRow; ++i)
        return records[row]->getData(col);
}// End method getData

// Start Destructor Triangle
Triangle::~Triangle()
{
    // Delete rows
    for (int i = 0; i < szRow; i++)
        delete records[i];
    
    // Delete whole
    delete [] records;
}// End Destructor Triangle
