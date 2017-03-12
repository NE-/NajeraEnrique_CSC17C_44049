/*
 * File: Table.h
 * Author: Najera Enrique
 * Date: 14 March 2017
 * Purpose: Create 2D array based on RowAray
 */

#ifndef TABLE_H
#define TABLE_H

// User Libraries
#include "RowAray.h"

template <class T>
class Table 
{
    public:
        // Constructor
        Table(unsigned int, unsigned int);
        
        // Copy constructor
        Table(const Table &);
        
        // Destructor
        /*
         * ERROR: Attempts to delete memory already deleted
         */
        ~Table(){
            for (int i = 0; i < getSzRow(); i++)
                delete columns[i];
            delete [] columns;
        }
        
        // SimpleVector functions
        void push_back(const T);
        void pop_off(const T);
        
        // Accessor methods
        int getSzRow()const {return szRow;}
        int getSzCol()const {return szCol;}
        T getData(int rows, int cols) const;
        
        // Overload Operators
        T &operator[](const int &);
        Table<T> operator+(const Table<T> &);
        
    private:
        int szRow;            // Holds number of rows
        int szCol;            // Holds number of columns
        RowAray<T> **columns; // Holds column data
};

// Start constructor Table
template <class T>
Table<T>::Table(unsigned int rows, unsigned int cols)
{
    // INIT variables
    szRow = rows;
    szCol = cols;
    
    // Allocate memory
    columns = new RowAray<T>*[szRow];
    
    // Fill array
    for (int i = 0; i < szRow; i++)
        columns[i] = new RowAray<T>(i + szCol);
} // End constructor Table

// Start copy constructor Table
template <class T>
Table<T>::Table(const Table &obj)
{
    // INIT variables
    szRow = obj.szRow;
    szCol = obj.szCol;
    
    // Allocate memory
    columns = new RowAray<T>*[szRow];
    
    // Copy elements
    for (int i = 0; i < szRow; i++)
        *(columns + i) = *(obj.columns + i);
    
} // End copy constructor Table

// Start accessor method getData
template <class T>
T Table<T>::getData(int rows, int cols) const
{
    // Return array elements
    return columns[rows]->getData(cols);
    
} // End accessor method getData

// Start operator overload+ method
template <class T>
Table<T> Table<T>::operator+(const Table<T> &right)
{
    // Create temporary Table object
    Table<T> temp(right.szRow, right.szCol);
    
    /*
     * error: invalid operands of types 'RowAray<float>*' and 
     *        'RowAray<float>*' to binary 'operator+'
     */
    for (int i = 0; i < 0; i++)
        temp.columns[i] = this->columns[i] /*+ right.columns[i]*/;
    
    return temp;
} // End operator overload+ method


// Start method push_back
template <class T>
void Table<T>::push_back(const T value)
{
    // Copy all the properties of current array
    Table<T> old = *this;
    
    // Delete to resize
    delete [] columns;
    
    // Allocate new memory + 1
    columns = new RowAray<T>*[szRow + 1];
    
    // make the final index = argument
    columns[szRow] = value;
    
    // Refill array
    for (int i = 0; i < szRow; i++)
        columns[i] = old->columns[i];
    
    // Increase size
    szRow++;
} // End method push_back

// Start method pop_off
template <class T>
void Table<T>::pop_off(const T value)
{
    /*
     * Not sure if pop off index or exact number
     * Going with exact number in this case
     */
    // First check if value actually in array
    for (int i = 0; i < szRow; i++)
    {
        if (columns[i] == value)
        {
            // Copy all the properties of current array
            Table<T> old = *this;

            // Delete to resize
            delete [] columns;
            
            // Increment row size
            szRow--;

            // Allocate new memory + 1
            columns = new RowAray<T>*[szRow];

            // Refill array without value
            for (int i = 0; i < szRow; i++)
            {
                // If value, go to next value
                if (old->columns[i] == value)
                    columns[i] = old->columns[i+1];
                // Else fill normally
                else
                    columns[i] = old->columns[i];
            }
        }
        // If value not found, leave
        else
            return ;
    }
} // End method pop_off

#endif /* TABLE_H */
