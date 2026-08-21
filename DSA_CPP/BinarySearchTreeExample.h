#ifndef BINARYSEARCHTREEEXAMPLE_H
#define BINARYSEARCHTREEEXAMPLE_H
#include <iostream>

template <typename T>
class Node; // Forward declaration

class BinarySearchTreeExample
{
public:
    void demonstrate();

private:
    Node<int> *insert(Node<int> *root, int data);
    bool search(Node<int> *root, int data);
    Node<int> *deleteNode(Node<int> *root, int data);
    Node<int> *findMin(Node<int> *root);
    Node<int> *findMax(Node<int> *root);
    void inorderTraversal(Node<int> *root);
    void preorderTraversal(Node<int> *root);
    void postorderTraversal(Node<int> *root);
    void deleteTree(Node<int> *root);
};
#endif