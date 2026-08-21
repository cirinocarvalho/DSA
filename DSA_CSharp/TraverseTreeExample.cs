using System;

namespace DSA
{
    public class TraverseTreeExample
    {
        // Tree Traversal = a form of graph traversal and refers to the process of visiting (checking and/or updating) each node in a tree data structure, exactly once. Such traversals are classified by the order in which the nodes are visited.
        //                  1. Pre-order Traversal (Root, Left, Right)
        //                  2. In-order Traversal (Left, Root, Right)
        //                  3. Post-order Traversal (Left, Right, Root)
        //                  4. Level-order Traversal (Level by Level from Left to Right)

        public TraverseTreeExample()
        {
            Nodes root = new Nodes(1);
            root.left = new Nodes(2);
            root.right = new Nodes(3);
            root.left.left = new Nodes(4);
            root.left.right = new Nodes(5);
            root.right.left = new Nodes(6);
            root.right.right = new Nodes(7);
            Console.WriteLine("Pre-order Traversal:");
            PreOrder(root); // 1 2 4 5 3 6 7
            Console.WriteLine("\nIn-order Traversal:");
            InOrder(root); // 4 2 5 1 6 3
            Console.WriteLine("\nPost-order Traversal:");
            PostOrder(root); // 4 5 2 6 7 3
            Console.WriteLine("\nLevel-order Traversal:");
            LevelOrder(root); // 1 2 3 4 5 6 7

        }

        private void PreOrder(Nodes? root)
        {
            if (root == null) return;
            Console.WriteLine(root.data + " ");
            PreOrder(root.left);
            PreOrder(root.right);
        }

        private void InOrder(Nodes? root)
        {
            if (root == null) return;
            InOrder(root.left);
            Console.WriteLine(root.data + " ");
            InOrder(root.right);
        }
        private void PostOrder(Nodes? root)
        {
            if (root == null) return;
            PostOrder(root.left);
            PostOrder(root.right);
            Console.WriteLine(root.data + " ");
        }

        private void LevelOrder(Nodes? root)
        {
            if (root == null) return;
            Queue<Nodes> queue = new Queue<Nodes>();
            queue.Enqueue(root);
            while (queue.Count > 0)
            {
                Nodes current = queue.Dequeue();
                Console.WriteLine(current.data + " ");
                if (current.left != null) queue.Enqueue(current.left);
                if (current.right != null) queue.Enqueue(current.right);
            }
        }
    }
}