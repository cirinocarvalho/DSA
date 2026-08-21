
namespace DSA
{
    public class DepthFirstSearchExample
    {
        // Depth First Search = Pick a direction and go as far as you can
        //.                     if you hit a dead end, backtrack and try another path
        //                     Uses Stack (LIFO) data structure
        // Time Complexity = O(V + E) where V is vertices and E is edges

        public DepthFirstSearchExample()
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

            graph.DepthFirstSearch(3); // A B C D E

        }
    }
}