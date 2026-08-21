#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
#include <iostream>

class Graph
{
private:
    int vertices;
    std::vector<std::list<int>> adjList;
    std::vector<std::vector<int>> adjMatrix;
    bool useMatrix;

public:
    // Constructors
    Graph(int vertices, bool useMatrix = false);

    // Add edge
    void addEdge(int src, int dest);

    // Remove edge
    void removeEdge(int src, int dest);

    // Print graph
    void printGraph() const;

    // Get adjacency list
    const std::vector<std::list<int>> &getAdjList() const;

    // Get adjacency matrix
    const std::vector<std::vector<int>> &getAdjMatrix() const;

    // Get number of vertices
    int getVertices() const;

    // Check if using matrix representation
    bool isUsingMatrix() const;
};

#endif // GRAPH_H