#include "TraverseTreeExample.h"

void TraverseTreeExample::demonstrate()
{
    std::cout << "\n=== Tree Traversal Example ===\n";
    std::cout << "Tree traversal algorithms for binary trees\n";
    std::cout << "Time Complexity: O(n) for all traversals\n";
    std::cout << "Space Complexity: O(h) where h is the height of the tree\n\n";

    // Create a sample binary tree
    //       1
    //      / \
    //     2   3
    //    / \   \
    //   4   5   6
    Node<int> *root = createSampleTree();

    std::cout << "Sample Binary Tree Structure:\n";
    std::cout << "       1\n";
    std::cout << "      / \\\n";
    std::cout << "     2   3\n";
    std::cout << "    / \\   \\\n";
    std::cout << "   4   5   6\n\n";

    std::cout << "In-Order Traversal (Left, Root, Right): ";
    inOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "Pre-Order Traversal (Root, Left, Right): ";
    preOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "Post-Order Traversal (Left, Right, Root): ";
    postOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "\nTraversal Applications:\n";
    std::cout << "- In-Order: Get sorted sequence in BST\n";
    std::cout << "- Pre-Order: Copy/serialize tree structure\n";
    std::cout << "- Post-Order: Delete tree nodes safely\n";

    // Clean up memory
    deleteTree(root);
}

Node<int> *TraverseTreeExample::createSampleTree()
{
    // Create nodes
    Node<int> *root = new Node<int>(1);
    root->left = new Node<int>(2);
    root->right = new Node<int>(3);
    root->left->left = new Node<int>(4);
    root->left->right = new Node<int>(5);
    root->right->right = new Node<int>(6);

    return root;
}

void TraverseTreeExample::inOrderTraversal(Node<int> *node)
{
    if (node == nullptr)
    {
        return;
    }

    inOrderTraversal(node->left);   // Visit left subtree
    std::cout << node->data << " "; // Visit root
    inOrderTraversal(node->right);  // Visit right subtree
}

void TraverseTreeExample::preOrderTraversal(Node<int> *node)
{
    if (node == nullptr)
    {
        return;
    }

    std::cout << node->data << " "; // Visit root
    preOrderTraversal(node->left);  // Visit left subtree
    preOrderTraversal(node->right); // Visit right subtree
}

void TraverseTreeExample::postOrderTraversal(Node<int> *node)
{
    if (node == nullptr)
    {
        return;
    }

    postOrderTraversal(node->left);  // Visit left subtree
    postOrderTraversal(node->right); // Visit right subtree
    std::cout << node->data << " ";  // Visit root
}

void TraverseTreeExample::deleteTree(Node<int> *node)
{
    if (node == nullptr)
    {
        return;
    }

    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}