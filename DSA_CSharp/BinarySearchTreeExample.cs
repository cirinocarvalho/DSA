using System;

namespace DSA
{
    public class BinarySearchTreeExample
    {
        // Binary Search Tree (BST) = a node-based binary tree data structure which has the following properties:
        //                            The left subtree of a node contains only nodes with keys less than the node's key.
        //                            The right subtree of a node contains only nodes with keys greater than the node's key.
        //                            The left and right subtree each must also be a binary search tree.

        public BinarySearchTreeExample()
        {
            BinarySearchTree tree = new BinarySearchTree();

            tree.Insert(new Nodes(5));
            tree.Insert(new Nodes(1));
            tree.Insert(new Nodes(9));
            tree.Insert(new Nodes(2));
            tree.Insert(new Nodes(7));
            tree.Insert(new Nodes(3));
            tree.Insert(new Nodes(6));
            tree.Insert(new Nodes(4));
            tree.Insert(new Nodes(8));

            tree.Delete(10); // Value 10 not found in the tree.
            tree.display(); // 1 2 3 4 5 6 7 8 9
            Console.WriteLine(tree.Search(1)); // True



        }
    }

    internal class Nodes
    {
        public int data;
        public Nodes left;
        public Nodes right;

        public Nodes(int data)
        {
            this.data = data;
        }
    }

    internal class BinarySearchTree
    {
        public Nodes root;

        public void Insert(Nodes node)
        {
            root = InsertHelper(root, node);
        }
        private Nodes InsertHelper(Nodes root, Nodes node)
        {
            int data = node.data;
            if (root == null)
            {
                root = node;
                return root;
            }
            else if (data < root.data)
            {
                root.left = InsertHelper(root.left, node);
            }
            else if (data > root.data)
            {
                root.right = InsertHelper(root.right, node);
            }
            return root;
        }

        public void display()
        {
            displayHelper(root);
        }
        private void displayHelper(Nodes root)
        {
            if (root != null)
            {
                displayHelper(root.left);
                Console.WriteLine(root.data + " ");
                displayHelper(root.right);
            }
        }
        public bool Search(int data)
        {
            return SearchHelper(root, data);
        }
        private bool SearchHelper(Nodes root, int data)
        {
            if (root == null)
            {
                return false;
            }
            else if (data == root.data)
            {
                return true;
            }
            else if (data < root.data)
            {
                return SearchHelper(root.left, data);
            }
            else
            {
                return SearchHelper(root.right, data);
            }
        }
        public void Delete(int data)
        {
            if (Search(data))
            {
                DeleteHelper(root, data);
            }
            else
            {
                Console.WriteLine($"Value {data} not found in the tree.");
            }
        }
        private Nodes DeleteHelper(Nodes root, int data)
        {
            if (root == null)
            {
                return root;
            }

            else if (data < root.data)
            {
                root.left = DeleteHelper(root.left, data);
            }
            else if (data > root.data)
            {
                root.right = DeleteHelper(root.right, data);
            }
            else
            {

                if (root.left == null && root.right == null)
                {
                    root = null;
                }
                else if (root.right == null)
                {
                    root.data = Sucessor(root);
                    root.right = DeleteHelper(root.right, root.data);
                }
                else if (root.left == null)    //find successor
                {
                    root.data = Sucessor(root);
                    root.right = DeleteHelper(root.right, root.data);
                }
                else // find predecessor
                {
                    root.data = Predecessor(root);
                    root.left = DeleteHelper(root.left, root.data);
                }
            }
            return root;
        }

        // Find the minimum value in the right subtree
        private int Sucessor(Nodes root)
        {
            root = root.right;
            while (root.left != null)
            {
                root = root.left;
            }
            return root.data;
        }

        // Find the maximum value in the left subtree
        private int Predecessor(Nodes root)
        {
            root = root.left;
            while (root.right != null)
            {
                root = root.right;
            }
            return root.data;
        }

    }
}