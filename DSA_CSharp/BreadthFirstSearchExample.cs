using System;

namespace DSA
{
    public class BreadthFirstSearchExample
    {
        // BFS = an algorithm for traversing or searching tree or graph data structures
        //.      starts at the tree root (or some arbitrary node of a graph)
        //.      explores the neighbor nodes at the present depth prior to moving on to the nodes at the next depth level
        //.      uses a queue to keep track of nodes to visit next
        public BreadthFirstSearchExample()
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

            //Console.WriteLine($"Edge between A and B: {graph.CheckEdge(0, 1)}"); // True

            graph.BreadthFirstSearch(1); // A B C D E


            //Where is BFS useful?
            //1. Finding the shortest path in an unweighted graph
            //2. Crawling social networks
            //3. Finding all nodes within one connected component
        }
    }
}