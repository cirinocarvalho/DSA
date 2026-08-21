#include "BreadthFirstSearchExample.h"
#include "Graph.h"
#include <iostream>
#include <vector>
#include <queue>

void BreadthFirstSearchExample::demonstrate()
{
    std::cout << "\n=== Breadth-First Search Example ===\n";
    std::cout << "BFS: Graph traversal using queue (FIFO) - explores level by level\n";
    std::cout << "Time Complexity: O(V + E) where V = vertices, E = edges\n";
    std::cout << "Space Complexity: O(V) for visited array and queue\n\n";

    // Create a sample graph
    Graph graph(6, false); // Using adjacency list

    std::cout << "Creating graph with 6 vertices (0-5):\n";
    std::cout << "Graph structure:\n";
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

    // BFS from different starting vertices
    std::cout << "\n--- BFS Traversals ---\n";

    for (int startVertex = 0; startVertex <= 2; startVertex++)
    {
        std::cout << "BFS starting from vertex " << startVertex << ": ";
        bfs(graph, startVertex);
        std::cout << std::endl;
    }

    // Demonstrate shortest path finding (BFS property)
    std::cout << "\n--- Shortest Path Finding using BFS ---\n";
    std::vector<std::pair<int, int>> pathQueries = {{0, 5}, {1, 2}, {0, 3}};

    for (auto &query : pathQueries)
    {
        int source = query.first;
        int destination = query.second;

        std::vector<int> path = findShortestPath(graph, source, destination);

        if (!path.empty())
        {
            std::cout << "Shortest path from " << source << " to " << destination << " (distance " << (path.size() - 1) << "): ";
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

    // Demonstrate level-by-level traversal
    std::cout << "\n--- Level-by-Level BFS ---\n";
    bfsLevelOrder(graph, 0);

    std::cout << "\n--- BFS vs DFS Comparison ---\n";
    std::cout << "BFS Properties:\n";
    std::cout << "✓ Finds shortest path (unweighted graphs)\n";
    std::cout << "✓ Explores level by level (breadth-first)\n";
    std::cout << "✓ Good for finding nearby solutions\n";
    std::cout << "✓ Guarantees minimum steps to target\n";
    std::cout << "✗ Uses more memory (queue can be large)\n";
    std::cout << "✗ May explore many unnecessary nodes\n";

    std::cout << "\nDFS Properties:\n";
    std::cout << "✓ Uses less memory (stack-based)\n";
    std::cout << "✓ Good for exploring deep structures\n";
    std::cout << "✗ May not find shortest path\n";
    std::cout << "✗ Can get stuck in deep branches\n";

    std::cout << "\n--- Use Cases ---\n";
    std::cout << "• Finding shortest path in unweighted graphs\n";
    std::cout << "• Level-order tree traversal\n";
    std::cout << "• Social networking (find connections)\n";
    std::cout << "• Web crawling (breadth-first crawling)\n";
    std::cout << "• GPS navigation systems\n";
}

void BreadthFirstSearchExample::bfs(const Graph &graph, int startVertex)
{
    std::vector<bool> visited(graph.getVertices(), false);
    std::queue<int> queue;

    queue.push(startVertex);
    visited[startVertex] = true;

    while (!queue.empty())
    {
        int vertex = queue.front();
        queue.pop();
        std::cout << vertex << " ";

        // Add all unvisited neighbors to queue
        const auto &adjList = graph.getAdjList();
        for (int neighbor : adjList[vertex])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                queue.push(neighbor);
            }
        }
    }
}

std::vector<int> BreadthFirstSearchExample::findShortestPath(const Graph &graph, int source, int destination)
{
    std::vector<bool> visited(graph.getVertices(), false);
    std::vector<int> parent(graph.getVertices(), -1);
    std::queue<int> queue;

    queue.push(source);
    visited[source] = true;

    bool found = false;

    while (!queue.empty() && !found)
    {
        int vertex = queue.front();
        queue.pop();

        if (vertex == destination)
        {
            found = true;
            break;
        }

        const auto &adjList = graph.getAdjList();
        for (int neighbor : adjList[vertex])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                parent[neighbor] = vertex;
                queue.push(neighbor);
            }
        }
    }

    // Reconstruct path
    std::vector<int> path;
    if (found)
    {
        int current = destination;
        while (current != -1)
        {
            path.push_back(current);
            current = parent[current];
        }
        std::reverse(path.begin(), path.end());
    }

    return path;
}

void BreadthFirstSearchExample::bfsLevelOrder(const Graph &graph, int startVertex)
{
    std::vector<bool> visited(graph.getVertices(), false);
    std::queue<int> queue;

    queue.push(startVertex);
    visited[startVertex] = true;

    int level = 0;

    while (!queue.empty())
    {
        int levelSize = queue.size();
        std::cout << "Level " << level << ": ";

        for (int i = 0; i < levelSize; i++)
        {
            int vertex = queue.front();
            queue.pop();
            std::cout << vertex << " ";

            const auto &adjList = graph.getAdjList();
            for (int neighbor : adjList[vertex])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    queue.push(neighbor);
                }
            }
        }

        std::cout << std::endl;
        level++;
    }
}