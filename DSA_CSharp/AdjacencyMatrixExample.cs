using System;

namespace DSA
{
    public class AdjacencyMatrixExample
    {
        // Adjacency Matrix = a 2D array of VxV size where V is the number of vertices in a graph.
        //                    Used to represent a finite graph.
        //                    If there is an edge between vertex i and vertex j, then matrix[i][j] = 1, otherwise 0.
        //                    Can be used for both directed and undirected graphs.
        //                    Space complexity is O(V^2), which can be inefficient for large, sparse graphs.
        //                    Allows for quick edge lookups, making it efficient for dense graphs.

        public AdjacencyMatrixExample()
        {
            Graph graph = new Graph(5, Graph.GraphType.AdjacencyMatrix);

            graph.AddNode(new Node('A'));
            graph.AddNode(new Node('B'));
            graph.AddNode(new Node('C'));
            graph.AddNode(new Node('D'));
            graph.AddNode(new Node('E'));

            graph.AddEdge(0, 1);
            graph.AddEdge(1, 2);
            graph.AddEdge(1, 4);
            graph.AddEdge(2, 3);
            graph.AddEdge(2, 4);
            graph.AddEdge(4, 0);
            graph.AddEdge(4, 2);

            graph.Print();

            Console.WriteLine($"Edge between A and B: {graph.CheckEdge(0, 1)}"); // True

        }

    }

}