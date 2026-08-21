#include "Graph.h"

Graph::Graph(int vertices, bool useMatrix) : vertices(vertices), useMatrix(useMatrix)
{
    if (useMatrix)
    {
        adjMatrix.resize(vertices, std::vector<int>(vertices, 0));
    }
    else
    {
        adjList.resize(vertices);
    }
}

void Graph::addEdge(int src, int dest)
{
    if (src < 0 || src >= vertices || dest < 0 || dest >= vertices)
    {
        std::cout << "Invalid edge: (" << src << ", " << dest << ")\n";
        return;
    }

    if (useMatrix)
    {
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1; // For undirected graph
    }
    else
    {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src); // For undirected graph
    }
}

void Graph::removeEdge(int src, int dest)
{
    if (src < 0 || src >= vertices || dest < 0 || dest >= vertices)
    {
        std::cout << "Invalid edge: (" << src << ", " << dest << ")\n";
        return;
    }

    if (useMatrix)
    {
        adjMatrix[src][dest] = 0;
        adjMatrix[dest][src] = 0;
    }
    else
    {
        adjList[src].remove(dest);
        adjList[dest].remove(src);
    }
}

void Graph::printGraph() const
{
    if (useMatrix)
    {
        std::cout << "Adjacency Matrix:\n";
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
    else
    {
        std::cout << "Adjacency List:\n";
        for (int i = 0; i < vertices; i++)
        {
            std::cout << i << ": ";
            for (int neighbor : adjList[i])
            {
                std::cout << neighbor << " ";
            }
            std::cout << "\n";
        }
    }
}

const std::vector<std::list<int>> &Graph::getAdjList() const
{
    return adjList;
}

const std::vector<std::vector<int>> &Graph::getAdjMatrix() const
{
    return adjMatrix;
}

int Graph::getVertices() const
{
    return vertices;
}

bool Graph::isUsingMatrix() const
{
    return useMatrix;
}