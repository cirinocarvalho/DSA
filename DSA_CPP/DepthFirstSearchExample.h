#ifndef DEPTHFIRSTSEARCHEXAMPLE_H
#define DEPTHFIRSTSEARCHEXAMPLE_H
#include <iostream>
#include <vector>
#include <algorithm>

class Graph; // Forward declaration

class DepthFirstSearchExample
{
public:
    void demonstrate();

private:
    void dfsRecursive(const Graph &graph, int vertex, std::vector<bool> &visited);
    void dfsIterative(const Graph &graph, int startVertex);
    bool findPathDFS(const Graph &graph, int source, int destination,
                     std::vector<bool> &visited, std::vector<int> &path);
};
#endif