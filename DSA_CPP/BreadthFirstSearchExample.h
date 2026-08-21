#ifndef BREADTHFIRSTSEARCHEXAMPLE_H
#define BREADTHFIRSTSEARCHEXAMPLE_H
#include <iostream>
#pragma once
#include <vector>

class Graph; // Forward declaration

class BreadthFirstSearchExample
{
public:
    static void demonstrate();

private:
    static void bfs(const Graph &graph, int startVertex);
    static std::vector<int> findShortestPath(const Graph &graph, int source, int destination);
    static void bfsLevelOrder(const Graph &graph, int startVertex);
};
#endif