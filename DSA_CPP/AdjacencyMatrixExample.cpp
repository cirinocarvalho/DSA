#include "AdjacencyMatrixExample.h"
#include "Graph.h"

void AdjacencyMatrixExample::demonstrate()
{
    std::cout << "\n=== Adjacency Matrix Example ===\n";
    std::cout << "Adjacency Matrix: Graph representation using 2D matrix\n";
    std::cout << "Space Complexity: O(V²) where V = vertices\n";
    std::cout << "Time Complexity - Add/Remove/Search Edge: O(1)\n\n";

    // Create a graph with 5 vertices using adjacency matrix
    Graph graph(5, true); // true means use adjacency matrix

    std::cout << "Creating a graph with 5 vertices (0-4)\n";
    std::cout << "Graph representation: Adjacency Matrix\n\n";

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

    std::cout << "\n--- Adjacency Matrix Properties ---\n";
    std::cout << "✓ Fast edge lookup, addition, removal O(1)\n";
    std::cout << "✓ Simple implementation\n";
    std::cout << "✓ Good for dense graphs\n";
    std::cout << "✗ Uses O(V²) space even for sparse graphs\n";
    std::cout << "✗ Inefficient for graphs with few edges\n";

    std::cout << "\n--- Use Cases ---\n";
    std::cout << "• Dense graphs (many edges)\n";
    std::cout << "• When frequent edge queries are needed\n";
    std::cout << "• Mathematical graph operations\n";
    std::cout << "• Small graphs where space isn't critical\n";

    std::cout << "\nRemoving edge 1-4:\n";
    graph.removeEdge(1, 4);
    graph.printGraph();
}