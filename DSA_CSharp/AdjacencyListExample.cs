using System;

namespace DSA
{
    public class AdjacencyListExample
    {
        // Adjacency List = a collection of unordered lists used to represent a finite graph.
        //                  Each list describes the set of neighbors of a vertex in the graph.
        //                  More space efficient for sparse graphs compared to adjacency matrix.
        //                  Space complexity is O(V + E) where V is the number of vertices and E is the number of edges.

        public AdjacencyListExample()
        {
            Graph graph = new Graph(5, Graph.GraphType.AdjacencyList);

            graph.AddNode(new Node('A'));
            graph.AddNode(new Node('B'));
            graph.AddNode(new Node('C'));
            graph.AddNode(new Node('D'));
            graph.AddNode(new Node('E'));

            graph.AddEdge(0, 1);
            graph.AddEdge(1, 2);
            graph.AddEdge(2, 3);
            graph.AddEdge(2, 4);
            graph.AddEdge(4, 0);
            graph.AddEdge(4, 2);

            graph.Print();

            Console.WriteLine($"Edge between A and B: {graph.CheckEdge(0, 1)}"); // True

        }

    }

}