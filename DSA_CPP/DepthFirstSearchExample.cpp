#include "DepthFirstSearchExample.h"
#include "Graph.h"
#include <iostream>
#include <vector>
#include <stack>

void DepthFirstSearchExample::demonstrate()
{
    std::cout << "\n=== Depth-First Search Example ===\n";
    std::cout << "DFS: Graph traversal using stack (LIFO) - explores as far as possible\n";
    std::cout << "Time Complexity: O(V + E) where V = vertices, E = edges\n";
    std::cout << "Space Complexity: O(V) for visited array and recursion/stack\n\n";

    // Create a sample graph
    Graph graph(6, false); // Using adjacency list

    std::cout << "Creating graph with 6 vertices (0-5):\n";
    std::cout << "Adding edges to form this structure:\n";
    std::cout << "    0 --- 1 --- 3\n";
    std::cout << "    |     |     |\n";
    std::cout << "    2 --- 4 --- 5\n\n";

    // Add edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);

    std::cout << "Graph adjacency list:\n";
    graph.printGraph();

    // DFS from different starting vertices
    std::cout << "\n--- Recursive DFS Traversals ---\n";

    for (int startVertex = 0; startVertex <= 2; startVertex++)
    {
        std::cout << "DFS starting from vertex " << startVertex << ": ";
        std::vector<bool> visited(graph.getVertices(), false);
        dfsRecursive(graph, startVertex, visited);
        std::cout << std::endl;
    }

    std::cout << "\n--- Iterative DFS Traversals ---\n";

    for (int startVertex = 0; startVertex <= 2; startVertex++)
    {
        std::cout << "DFS starting from vertex " << startVertex << ": ";
        dfsIterative(graph, startVertex);
        std::cout << std::endl;
    }

    // Demonstrate path finding
    std::cout << "\n--- Path Finding using DFS ---\n";
    std::vector<std::pair<int, int>> pathQueries = {{0, 5}, {1, 2}, {0, 3}};

    for (auto &query : pathQueries)
    {
        int source = query.first;
        int destination = query.second;

        std::vector<int> path;
        std::vector<bool> visited(graph.getVertices(), false);

        if (findPathDFS(graph, source, destination, visited, path))
        {
            std::cout << "Path from " << source << " to " << destination << ": ";
            for (size_t i = 0; i < path.size(); i++)
            {
                std::cout << path[i];
                if (i < path.size() - 1)
                    std::cout << " -> ";
            }
            std::cout << std::endl;
        }
        else
        {
            std::cout << "No path found from " << source << " to " << destination << std::endl;
        }
    }

    std::cout << "\n--- DFS Properties ---\n";
    std::cout << "✓ Uses less memory than BFS\n";
    std::cout << "✓ Can be implemented recursively (natural)\n";
    std::cout << "✓ Good for detecting cycles\n";
    std::cout << "✓ Useful for topological sorting\n";
    std::cout << "✗ May not find shortest path\n";
    std::cout << "✗ Can get stuck in deep branches\n";
    std::cout << "✗ Stack overflow risk with deep recursion\n";

    std::cout << "\n--- Use Cases ---\n";
    std::cout << "• Maze solving and pathfinding\n";
    std::cout << "• Cycle detection in graphs\n";
    std::cout << "• Topological sorting\n";
    std::cout << "• Connected components detection\n";
    std::cout << "• Tree/graph copying\n";
}

void DepthFirstSearchExample::dfsRecursive(const Graph &graph, int vertex, std::vector<bool> &visited)
{
    visited[vertex] = true;
    std::cout << vertex << " ";

    // Visit all unvisited adjacent vertices
    const auto &adjList = graph.getAdjList();
    for (int neighbor : adjList[vertex])
    {
        if (!visited[neighbor])
        {
            dfsRecursive(graph, neighbor, visited);
        }
    }
}

void DepthFirstSearchExample::dfsIterative(const Graph &graph, int startVertex)
{
    std::vector<bool> visited(graph.getVertices(), false);
    std::stack<int> stack;

    stack.push(startVertex);

    while (!stack.empty())
    {
        int vertex = stack.top();
        stack.pop();

        if (!visited[vertex])
        {
            visited[vertex] = true;
            std::cout << vertex << " ";

            // Add all unvisited neighbors to stack
            // Note: We add in reverse order to maintain left-to-right traversal
            const auto &adjList = graph.getAdjList();
            std::vector<int> neighbors(adjList[vertex].begin(), adjList[vertex].end());

            // Sort neighbors to ensure consistent order
            std::sort(neighbors.rbegin(), neighbors.rend());

            for (int neighbor : neighbors)
            {
                if (!visited[neighbor])
                {
                    stack.push(neighbor);
                }
            }
        }
    }
}

bool DepthFirstSearchExample::findPathDFS(const Graph &graph, int source, int destination,
                                          std::vector<bool> &visited, std::vector<int> &path)
{
    visited[source] = true;
    path.push_back(source);

    // If we reached the destination
    if (source == destination)
    {
        return true;
    }

    // Try all adjacent vertices
    const auto &adjList = graph.getAdjList();
    for (int neighbor : adjList[source])
    {
        if (!visited[neighbor])
        {
            if (findPathDFS(graph, neighbor, destination, visited, path))
            {
                return true;
            }
        }
    }

    // Backtrack if no path found through this vertex
    path.pop_back();
    return false;
}