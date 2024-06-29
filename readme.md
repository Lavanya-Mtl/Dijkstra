# Implementation of Dijkstra's algorithm

Dijkstra's algorithm is used to find the shortest distance (and path) from a starting vertex to all other vertices in a directed graph with positive edge weights.

This code implements and employs a min-heap and a graph in the form of adjacency lists.



The following is how data is structured:

### Graph
A graph in the form of an adjacency matrix is converted to an adjacency list. 
A graph object is represented by the class Graph.
The class graph consists of the implementation of Dijkstra's algorithm.


### GraphNode: Nodes of the graph

The nodes of the graph are represented as GraphNode objects.
Each GraphNode object represents its neighbouring nodes with its wieghts using Neighbour objects; which form a linked list.
A pointer prev represents the node previous to the node under consideration traversing through which the shortest distance from the start node to it was obtained. This poineter can be used to trace the shortest path from the node to the start node.


### Min-Heap
A min-heap heapifies nodes of the graph on the basis of lowest distance with respect to the start vertex represented as a data member 'dijkstra_distance'.
In Dijkstra's algorithm, a min-heap stores all unvisited nodes.
The class Heap implements min-heap.



## The algorithm

### Step 1
Initially, a path to no vertex is known, hence they are labeled as being at an infinite distance.

### Step 2
The start vertex's distance is set to zero, and all vertices are inserted into the set of all unvisited nodes which is represented by a min-heap.

### Step 3
The vertex with the least distance is extracted from the unvisited set(heap).

### Step 4
All unvisited neighbours of the extracted vertex are explored. The length of the path from the start node to the neighbour if it goes through the current node is calculated. If the newly calculated distance is shorter than the previously known distance, the distance is updated, and the heap property is restored again. The pointer to the previous node of the neighbour that had its distance updated is set to current node. This pointer can be used to trace back the path from itself to the start node.

### Step 5
Once all neighbours are considered, the current node is marked as visited.

### Step 6
Steps 3-5 are repeated until all the nodes have been visited, that is, the heap becomes empty. Every node will have its shortest distance from the start node stored.


