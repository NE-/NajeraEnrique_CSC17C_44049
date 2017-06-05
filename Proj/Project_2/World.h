/*
 * File: World.h
 * Author: Najera Enrique
 * Date Due: 07 June 2017
 * Purpose: Graph that displays the world
 *          and its lengths/path weights
 */

/*
 * Credits: http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
 */

#ifndef WORLD_H
#define WORLD_H

// Start class World
class World {
    public:
        // Constructor and Destructor
        World();
        ~World();
        
        // Function Prototypes
        void dispWorld(); // Displays world
    private:
        // Declare Variables
        int **graph; // 2D array for holding weights between vertices
        
        // Function Prototypes
        int findMinDist(int *, bool *); // Find minimum distance between vertexes
        void dispWorld(int *, int);   // Output results
        
        void dijkstraAlgo(int **, int); // Finds length 
}; // End class World

#endif /* WORLD_H */

