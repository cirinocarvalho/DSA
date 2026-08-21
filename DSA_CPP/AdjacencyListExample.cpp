#include "AdjacencyListExample.h"
#include "Graph.h"

void AdjacencyListExample::demonstrate()
{
    std::cout << "\n=== Adjacency List Example ===\n";
    std::cout << "Adjacency List: Graph representation using lists\n";
    std::cout << "Space Complexity: O(V + E) where V = vertices, E = edges\n";
    std::cout << "Time Complexity - Add Edge: O(1), Remove Edge: O(V), Search: O(V)\n\n";

    // Create a graph with 5 vertices using adjacency list
    Graph graph(5, false); // false means use adjacency list

    std::cout << "Creating a graph with 5 vertices (0-4)\n";
    std::cout << "Graph representation: Adjacency List\n\n";

    // Add edges to create a sample graph
    std::cout << "Adding edges:\n";
    std::cout << "0 -- 1\n";
    std::cout << "0 -- 4\n";
    std::cout << "1 -- 2\n";
    std::cout << "1 -- 3\n";
    std::cout << "1 -- 4\n";
    std::cout << "2 -- 3\n";
    std::cout << "3 -- 4\n\n";

    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    std::cout << "Current graph structure:\n";
    graph.printGraph();

    std::cout << "\n--- Adjacency List Properties ---\n";
    std::cout << "✓ Memory efficient for sparse graphs\n";
    std::cout << "✓ Fast edge insertion O(1)\n";
    std::cout << "✓ Easy to iterate over neighbors\n";
    std::cout << "✗ Slower edge lookup O(V) in worst case\n";
    std::cout << "✗ More complex than adjacency matrix\n";

    std::cout << "\n--- Use Cases ---\n";
    std::cout << "• Social networks (sparse connections)\n";
    std::cout << "• Web page links\n";
    std::cout << "• Transportation networks\n";
    std::cout << "• Dependency graphs\n";

    std::cout << "\nRemoving edge 1-4:\n";
    graph.removeEdge(1, 4);
    graph.printGraph();
}