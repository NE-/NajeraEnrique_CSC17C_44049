/* 
 * File:   RowAray.h
 * Author: Dr. Mark E. Lehr
 * Created on September 1, 2016, 8:36 PM
 * Specification for the RowAray
 */

#ifndef ROWARAY_H
#define	ROWARAY_H

#include <cstdlib> // rand())

class RowAray{
    private:
        int size;
        int *rowData;
    public:
        RowAray(int);
        ~RowAray();
        int getSize(){return size;}
        int getData(int i){return rowData[i];}
};

#endif	/* ROWARAY_H */