using System;
using System.ComponentModel;

namespace DSA
{
    public class Graph
    {
        List<Node> nodes = new List<Node>();
        int[,] matrix;
        List<LinkedList<Node>> adjList;

        public enum GraphType
        {
            AdjacencyMatrix,
            AdjacencyList
        }
        GraphType graphType;

        public Graph(int size, GraphType graphType)
        {
            matrix = new int[size, size];
            adjList = new List<LinkedList<Node>>();
            this.graphType = graphType;
        }

        public void AddNode(Node node)
        {

            if (graphType == GraphType.AdjacencyList)
            {
                LinkedList<Node> currentList = new LinkedList<Node>();
                currentList.AddLast(node);
                adjList.Add(currentList);
            }
            else if (graphType == GraphType.AdjacencyMatrix)
            {
                nodes.Add(node);
            }

        }

        // The head of each adjacency list is the vertex itself, added by AddNode.
        private Node HeadOf(int index)
        {
            LinkedListNode<Node>? head = adjList[index].First;
            if (head is null)
            {
                throw new InvalidOperationException($"Vertex {index} has no adjacency list. Call AddNode first.");
            }
            return head.Value;
        }

        public void AddEdge(int src, int dst)
        {
            if (graphType == GraphType.AdjacencyList)
            {
                LinkedList<Node> currentList = adjList[src];
                Node dstNode = HeadOf(dst);
                currentList.AddLast(dstNode);
            }
            else if (graphType == GraphType.AdjacencyMatrix)
            {
                matrix[src, dst] = 1;
            }
        }

        public bool CheckEdge(int src, int dst)
        {
            if (graphType == GraphType.AdjacencyList)
            {
                LinkedList<Node> currentList = adjList[src];
                Node dstNode = HeadOf(dst);
                foreach (var item in currentList)
                {
                    if (item == dstNode)
                    {
                        return true;
                    }
                }
                return false;
            }
            else if (graphType == GraphType.AdjacencyMatrix)
            {
                if (matrix[src, dst] == 1)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }

            return false;
        }

        public void Print()
        {
            if (graphType == GraphType.AdjacencyList)
            {
                foreach (LinkedList<Node> currentList in adjList)
                {
                    foreach (Node node in currentList)
                    {
                        Console.Write(node.data + "  -> ");
                    }
                    Console.WriteLine();
                }
            }
            else if (graphType == GraphType.AdjacencyMatrix)
            {
                Console.Write("  ");
                foreach (var node in nodes)
                {
                    Console.Write(node.data + " ");
                }
                Console.WriteLine();

                for (int i = 0; i < matrix.GetLength(0); i++)
                {
                    Console.Write(nodes[i].data + " ");
                    for (int j = 0; j < matrix.GetLength(1); j++)
                    {
                        Console.Write(matrix[i, j] + " ");
                    }
                    Console.WriteLine();
                }
            }

        }

        public void DepthFirstSearch(int src)
        {
            bool[] visited = new bool[matrix.GetLength(0)];
            DepthFirstSearchHelper(src, visited);

        }

        private void DepthFirstSearchHelper(int src, bool[] visited)
        {
            if (visited[src] == true)
            {
                return;
            }
            else
            {
                visited[src] = true;
                Console.WriteLine(nodes[src].data + "  => Visited");
            }
            for (int i = 0; i < matrix.GetLength(1); i++)
            {
                if (matrix[src, i] == 1)
                {
                    DepthFirstSearchHelper(i, visited);
                }
            }
            return;
        }

        public void BreadthFirstSearch(int src)
        {

            Queue<int> queue = new Queue<int>();
            bool[] visited = new bool[matrix.GetLength(0)];

            queue.Enqueue(src);
            visited[src] = true;

            while (queue.Count > 0)
            {
                int current = queue.Dequeue();
                Console.WriteLine(nodes[current].data + "  => Visited");

                for (int i = 0; i < matrix.GetLength(1); i++)
                {
                    if (matrix[current, i] == 1 && !visited[i])
                    {
                        queue.Enqueue(i);
                        visited[i] = true;
                    }
                }
            }
        }

    }
}