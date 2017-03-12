/*
 * File: RowAray.h
 * Author: Najera Enrique
 * Date: 14 March 2017
 * Purpose: Create and fill rows for table array
 */

#ifndef ROWARAY_H
#define ROWARAY_H

// System Libraries
#include <iostream>
#include <cstdlib> // rand()
#include <new>     // bad_alloc

// Start template class RowAray
template <class T>
class RowAray{
    public:
        // Constructor
        RowAray(int);
        
        // Destructor
        ~RowAray() {delete [] rowData;}
        
        // Accessor Functions
        // Return the size of the allocated array
        int getSize() const{return size;}
        
        // Returns data inside array
        T getData(int i) const{
            if (i >= 0 && i < size) return rowData[i];
            else return 0;
        }
    private:
        int size;   // Holds size of array
        T *rowData; // Contains data inside array
};// End template class RowAray

// Start constructor RowAray
// Creates dynamic memory for array, then fills with random numbers
template <class T>
RowAray<T>::RowAray(int row)
{
    // INIT variables
    size = row;

    // Try to allocate memory
    try
    {
        rowData = new T [size];
    } 
    catch (std::bad_alloc)
    {
        std::cout << "Cannot allocate memory!\n";
        exit(EXIT_FAILURE);
    }

    // Fill array with random numbers
    for (int i = 0; i < row; i++)
        *(rowData + i) = rand() % 90 + 10;
} // End constructor RowData

#endif /* ROWARAY_H */

