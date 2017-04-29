/*
 * File: main.cpp
 * Author: Najera Enrique
 * Date: 03 May 2017
 * Purpose: Compare heap, merge, and quicksort.
 *          Prove the Big-O characteristics by 
 *          a timing or operational comparison.
 */

// System Libraries
#include <iostream>
#include <cstdlib>   // rand()
#include <ctime>     // time()

using namespace std;

// Function Prototypes
int *fillAry(int);          // Fills the array
void printAry(int [], int); // Prints array contents
void cleanup(int []);       // Deallocates memory

void heapSort(int *, int);
void heapify(int *, int, int);
void mergeSort(int *, int, int);
void merge(int *, int, int, int);
void quickSort(int *, int, int);

void printAnalysis(); // Outputs operational analysis

// Start method main
int main(int argc, char *argv[]){
    // Random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    // Declare Variables
    int size = 2e7; // Size of the array
    int *array = fillAry(size);
    int *heapAry  = array; // Unsorted array for heap sort
    int *mergeAry = array; // Unsorted array for merge sort
    int *quickAry = array; // Unsorted array for quick sort
    
    // Print unsorted arrays
    //cout << "Initial array: ";printAry(array, size);
    /*printAry(heapAry, size);
    printAry(mergeAry, size);
    printAry(quickAry, size);*/
    
    // Start sorting and timing
    int beg = time(0);
    heapSort(heapAry, size);
    int end = time(0);
    cout << "Heap sort timing with " << size << " elements : "
         << end - beg << " seconds" << endl;
    
    cout << "Merge sort crashes with large array sizes\n";
    
    /*
     * Merge Sorting crashes with large array sizes
     * Smallest working size was 10000, but the timing turned 
     * out to be 0 seconds.
    beg = time(0);
    mergeSort(mergeAry, 1, size);
    end = time(0);
    cout << "Merge sort timing with " << size << " elements : "
         << end - beg << " seconds" << endl;*/
    
    beg = time(0);
    quickSort(quickAry, 0 ,size);
    end = time(0);
    cout << "Quick sort timing with " << size << " elements : "
         << end - beg << " seconds" << endl;
    
    // Print analysis
    printAnalysis();
    
    
    // Print sorted arrays
    /*
     *       Arrays too long to print
    
     * cout << "\nHeap sort: "; printAry(heapAry, size);
     * cout << "\nMerge sort: ";printAry(mergeAry, size);
     * cout << "\nQuick sort: ";printAry(quickAry, size);
     */
    
    // Deallocate memory
    cleanup(array);
    // Causes program crashing
    // Also crashes when using delete heapAry; etc.
    //cleanup(heapAry);
    //cleanup(mergeAry);
    //cleanup(quickAry);
    
    // SYS_EXIT
    return 0;
}// End method main

        /***** Array Functions *****/

// Start method fillAry
int *fillAry(int size){
    // Allocate memory
    int *a = new int[size];
    
    // Fill with random numbers
    for(int i = 0; i < size; i++)
        a[i] = rand();
    
    return a;
}// End method fillAry

// Start method printAry
void printAry(int a[], int size){
    cout << endl;
    for(int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}// End method printAry

// Start method destroy
void cleanup(int *a){
    delete [] a;
}// End method destroy

        /***** Sort Functions *****/

// Start method heapSort
void heapSort(int *a, int size){
    for (int i = size/2-1; i>=0; i--)
        heapify(a, size, i);
    for (int i = size-1; i >= 0; i--){
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}// End method heapSort

// Start method heapify
void heapify(int *a, int size, int i){
    // Declare Variables
    int largest = i;
    int left  = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < size  && a[left] > a[largest])
        largest = left;
    if (right < size && a[right] > a[largest])
        largest = right;
    if (largest != i){
        swap(a[i], a[largest]);
        heapify(a, size, largest);
    }
        
}// End method heapify

// Start method mergeSort
void mergeSort(int *a, int low, int high){
    int mid;
    if (low < high){
        mid = (low + high) / 2;
        
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}// End method mergeSort

// Start method merge
void merge(int *a, int low, int mid, int high){
    // Declare Variables
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1+1];
    int R[n2+1];
    
    for (int i = 1; i <= n1; i++)
        L[i] = a[low + i - 1];
    for (int j = 1; j <= n2; j++)
        R[j] = a[mid + j];
    L[n1+1]=999;
    R[n2+1]=999;
    int i = 1, j = 1;
    for (int k = low; k <= high; k++){
        if (L[i]<=R[j]){
            a[k] = L[i];
            i = i + 1;
        }
        else {
            a[k] = R[j];
            j = j + 1;
        }
    }
}// End method merge

// Start method quickSort
void quickSort(int *a, int left, int right){
    // Declare Variables
    int i = left, j = right;
    int temp;
    int pivot = a[(left + right) / 2];
    
    while (i <= j){
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i <= j){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    
    if (left < j)
        quickSort(a, left, j);
    if (i < right)
        quickSort(a, i , right);
}// End method quickSort

void printAnalysis(){
    cout << "\nHeap sort's 'heapify' is called once,"
         << " and it's O(n),\nheapSort is O(log(n))"
         << " called n times,\ntherefore it is"
         << " O(n + n * log(n)) = O(n * log(n))\n";
    
    cout << "\nQuick sort divides the array into 2"
         << " which makes recursion\ncalling halved."
         << " The depth of the log tree is then log(n)"
         << " and every level is\nan O(n), therefore"
         << " o(n * log(n))\n";
    cout << "\nMerge sort is repeatedly halved,"
         << " so it is O(log n),\nbut it is also"
         << " iterated n items, log(n) times,"
         << " therefore O(n * log(n))\n";
}