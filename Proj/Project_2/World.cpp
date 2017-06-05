/*
 * File: World.cpp
 * Author: Najera Enrique
 * Date Due: 07 June 2017
 * Purpose: Graph that displays the world
 *          and its lengths/path weights
 */

/*
 * Credits: http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
 */

// System Libraries
#include <iostream>
using namespace std;

// User Libraries
#include "World.h"

// Start constructor World
World::World(){
    // Allocate memory for 7 vertices
    graph = new int *[7];
    for (int i = 0; i < 7; ++i)
        graph[i] = new int[7];
        
    // INIT all to 0 to skip hard code initialization
    // of unreachable weights or going to itself
    for (int i = 0; i < 7; ++i){
        for (int j = 0; j < 7; ++j)
            graph[i][j] = 0;
    }
        
    // Fill the array with vertices weight
    /*
     * 0 = Amaranth
     * 1 = Eburnean
     * 2 = Xanadu
     * 3 = Wenge
     * 4 = Glaucous
     * 5 = Mikado
     * 6 = Sarcoline
     */
    graph[0][1] =  476; // Amaranth -> Eburnean
    graph[0][2] =  136; // Amaranth -> Xanadu
    graph[0][3] = 5376; // Amaranth -> Wenge
    graph[0][5] = 1835; // Amaranth -> Mikado
    
    graph[1][0] =  476; // Eburnean -> Amaranth
    graph[1][2] = 1847; // Eburnean -> Xanadu
    graph[1][4] = 1463; // Eburnean -> Glaucous
    graph[1][6] = 4062; // Eburnean -> Sarcoline
    
    graph[2][0] =  136; // Xanadu -> Amaranth
    graph[2][1] = 1847; // Xanadu -> Eburnean
    graph[2][3] =  741; // Xanadu -> Wenge
    graph[2][4] =  801; // Xanadu -> Glaucous
    
    graph[3][0] = 5376; // Wenge -> Amaranth
    graph[3][2] =  741; // Wenge -> Xanadu
    graph[3][5] = 1091; // Wenge -> Mikado
    
    graph[4][1] = 1463; // Glaucous -> Eburnean
    graph[4][2] =  801; // Glaucous -> Xanadu
    graph[4][5] = 1122; // Glaucous -> Mikado
    graph[4][6] = 1337; // Glaucous -> Sarcoline
    
    graph[5][0] = 1835; // Mikado -> Amaranth
    graph[5][3] = 1091; // Mikado -> Wenge
    graph[5][4] = 1122; // Mikado -> Glaucous
    graph[5][6] = 2341; // Mikado -> Sarcoline
    
    graph[6][1] = 4062; // Sarcoline -> Eburnean
    graph[6][4] = 1337; // Sarcoline -> Glaucous
    graph[6][5] = 2341; // Sarcoline -> Mikado
} // End constructor World

// Start destructor World
World::~World(){
    // Deallocate memory
    for (int i = 0; i < 7; ++i)
        delete [] graph[i];
    delete [] graph;
} // End destructor World

// Start public method dispResults
void World::dispWorld(){
    dijkstraAlgo(graph, 0);
} // End method dispResults

// Start private method dispResults
void World::dispWorld(int *dist, int n){
    // Output distances
    cout << "\nAmaranth -> Eburnean " << graph[0][1] << endl;
    cout << "Amaranth -> Xanadu    " << graph[0][2] << endl;
    cout << "Amaranth -> Wenge    " << graph[0][3] << endl;
    cout << "Amaranth -> Mikado   " << graph[0][5] << endl;
    cout << endl;
    cout << "Eburnean -> Amaranth   "<< graph[1][0] << endl;
    cout << "Eburnean -> Xanadu    " << graph[1][2] << endl;
    cout << "Eburnean -> Glaucous  " << graph[1][4] << endl;
    cout << "Eburnean -> Sarcoline " << graph[1][6] << endl;
    cout << endl;
    cout << "Xanadu -> Amaranth  " << graph[2][0] << endl;
    cout << "Xanadu -> Eburnean "  << graph[2][1] << endl;
    cout << "Xanadu -> Wenge     " << graph[2][3] << endl;
    cout << "Xanadu -> Glaucous  " << graph[2][4] << endl;
    cout << endl;
    cout << "Wenge -> Amaranth " << graph[3][0] << endl;
    cout << "Wenge -> Xanadu    "<< graph[3][2] << endl;
    cout << "Wenge -> Mikado   " << graph[3][5] << endl;
    cout << endl;
    cout << "Glaucous -> Eburnean  " << graph[4][1] << endl;
    cout << "Glaucous -> Xanadu     "<< graph[4][2] << endl;
    cout << "Glaucous -> Mikado    " << graph[4][5] << endl;
    cout << "Glaucous -> Sarcoline " << graph[4][6] << endl;
    cout << endl;
    cout << "Mikado -> Amaranth  " << graph[5][0] << endl;
    cout << "Mikado -> Wenge     " << graph[5][3] << endl;
    cout << "Mikado -> Glaucous  " << graph[5][4] << endl;
    cout << "Mikado -> Sarcoline " << graph[5][6] << endl;
    cout << endl;
    cout << "Sarcoline -> Eburnean " << graph[6][1] << endl;
    cout << "Sarcoline -> Glaucous " << graph[6][4] << endl;
    cout << "Sarcoline -> Mikado   " << graph[6][5] << endl;
    cout << endl;
    
    // Output minimum spanning tree
    cout << "\nLocation     Shortest distance from you (Amaranth Town)\n";
    // Could be done with map -> string vertex : int weight
    for (int i = 0; i < 7; i++){
        if (i == 0) ;
        if (i == 1) cout << "Eburnean  " << "\t\t "  << dist[i] << endl;
        if (i == 2) cout << "Xanadu    " << "\t\t "  << dist[i] << endl;
        if (i == 3) cout << "Wenge     " << "\t\t "  << dist[i] << endl;
        if (i == 4) cout << "Glaucous  " << "\t\t "  << dist[i] << endl;
        if (i == 5) cout << "Mikado    " << "\t\t"   << dist[i] << endl;
        if (i == 6) cout << "Sarcoline " << "\t\t"   << dist[i] << endl;
    }
        
} // End method dispResults

// Start method findMinDistance
int World::findMinDist(int *dist, bool *set){
    // Declare Variables
    int min = 0x7FFFFFFFL; // Max value of an int
    int minIndex = 0;
    
    for (int i = 0; i < 7; i++){
        if (set[i] == false && dist[i] <= min)
            min = dist[i], minIndex = i;
    }
    
    return minIndex;
} // End method findMinDistance

// Start method dijkstraAlgo
void World::dijkstraAlgo(int **graph, int src)
{
     int dist[7]; // Holds shortest distance
  
     bool sptSet[7]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized
  
     // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 0; i < 7; i++)
        dist[i] = 0x7FFFFFFFL, sptSet[i] = false;
  
     // Distance of source vertex from itself is always 0
     dist[src] = 0;
  
     // Find shortest path for all vertices
     for (int count = 0; count < 7-1; count++)
     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in first iteration.
       int u = findMinDist(dist, sptSet);
  
       // Mark the picked vertex as processed
       sptSet[u] = true;
  
       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < 7; v++)
  
         // Update dist[v] only if is not in sptSet, there is an edge from 
         // u to v, and total weight of path from src to  v through u is 
         // smaller than current value of dist[v]
         if (!sptSet[v] && graph[u][v] && dist[u] != 0x7FFFFFFFL 
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }
  
     // print the constructed distance array
     dispWorld(dist, 7);
} // End method dijkstraAlgo
