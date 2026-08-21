#include "BinarySearchTreeExample.h"
#include "Node.h"
#include <iostream>

void BinarySearchTreeExample::demonstrate()
{
    std::cout << "\n=== Binary Search Tree Example ===\n";
    std::cout << "BST: Binary tree where left child < parent < right child\n";
    std::cout << "Time Complexity - Search/Insert/Delete: O(log n) average, O(n) worst\n";
    std::cout << "Space Complexity: O(n)\n\n";

    std::cout << "Building BST with values: 50, 30, 20, 40, 70, 60, 80\n";

    Node<int> *root = nullptr;

    // Insert values
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    std::cout << "\nBST Structure:\n";
    std::cout << "        50\n";
    std::cout << "       /  \\\n";
    std::cout << "      30   70\n";
    std::cout << "     / \\   / \\\n";
    std::cout << "    20 40 60 80\n\n";

    std::cout << "In-order traversal (sorted): ";
    inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Pre-order traversal: ";
    preorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Post-order traversal: ";
    postorderTraversal(root);
    std::cout << std::endl;

    // Search operations
    std::cout << "\n--- Search Operations ---\n";
    int searchValues[] = {40, 25, 70, 90};
    for (int val : searchValues)
    {
        if (search(root, val))
        {
            std::cout << "Found " << val << " in the BST\n";
        }
        else
        {
            std::cout << "Value " << val << " not found in BST\n";
        }
    }

    // Find min and max
    std::cout << "\nMinimum value: " << findMin(root)->data << std::endl;
    std::cout << "Maximum value: " << findMax(root)->data << std::endl;

    // Delete operations
    std::cout << "\n--- Delete Operations ---\n";
    std::cout << "Deleting 20 (leaf node):\n";
    root = deleteNode(root, 20);
    std::cout << "In-order after deletion: ";
    inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "\nDeleting 30 (node with two children):\n";
    root = deleteNode(root, 30);
    std::cout << "In-order after deletion: ";
    inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "\n--- BST Properties ---\n";
    std::cout << "✓ Efficient searching O(log n) average case\n";
    std::cout << "✓ In-order traversal gives sorted sequence\n";
    std::cout << "✓ Dynamic size - can grow and shrink\n";
    std::cout << "✓ No memory waste (only allocates needed nodes)\n";
    std::cout << "✗ Can become unbalanced (O(n) worst case)\n";
    std::cout << "✗ No constant time access to elements\n";

    std::cout << "\n--- Use Cases ---\n";
    std::cout << "• Maintaining sorted data with frequent insertions/deletions\n";
    std::cout << "• Database indexing systems\n";
    std::cout << "• Expression parsing (syntax trees)\n";
    std::cout << "• File system hierarchies\n";

    // Clean up memory
    deleteTree(root);
}

Node<int> *BinarySearchTreeExample::insert(Node<int> *root, int data)
{
    // Base case: create new node
    if (root == nullptr)
    {
        return new Node<int>(data);
    }

    // Recursive case: insert in appropriate subtree
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    // Equal values are ignored (no duplicates)

    return root;
}

bool BinarySearchTreeExample::search(Node<int> *root, int data)
{
    // Base case: empty tree or value not found
    if (root == nullptr)
    {
        return false;
    }

    // Value found
    if (root->data == data)
    {
        return true;
    }

    // Search in appropriate subtree
    if (data < root->data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}

Node<int> *BinarySearchTreeExample::deleteNode(Node<int> *root, int data)
{
    // Base case: empty tree
    if (root == nullptr)
    {
        return root;
    }

    // Find the node to delete
    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        // Node to be deleted found

        // Case 1: Node with only right child or no child
        if (root->left == nullptr)
        {
            Node<int> *temp = root->right;
            delete root;
            return temp;
        }
        // Case 2: Node with only left child
        else if (root->right == nullptr)
        {
            Node<int> *temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Node with two children
        // Get inorder successor (smallest in right subtree)
        Node<int> *temp = findMin(root->right);

        // Replace root's data with successor's data
        root->data = temp->data;

        // Delete the successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

Node<int> *BinarySearchTreeExample::findMin(Node<int> *root)
{
    while (root && root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

Node<int> *BinarySearchTreeExample::findMax(Node<int> *root)
{
    while (root && root->right != nullptr)
    {
        root = root->right;
    }
    return root;
}

void BinarySearchTreeExample::inorderTraversal(Node<int> *root)
{
    if (root != nullptr)
    {
        inorderTraversal(root->left);
        std::cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

void BinarySearchTreeExample::preorderTraversal(Node<int> *root)
{
    if (root != nullptr)
    {
        std::cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void BinarySearchTreeExample::postorderTraversal(Node<int> *root)
{
    if (root != nullptr)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        std::cout << root->data << " ";
    }
}

void BinarySearchTreeExample::deleteTree(Node<int> *root)
{
    if (root != nullptr)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}