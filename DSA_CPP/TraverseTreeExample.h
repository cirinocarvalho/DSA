#ifndef TRAVERSETREEEXAMPLE_H
#define TRAVERSETREEEXAMPLE_H

#include <iostream>
#include "Node.h"

class TraverseTreeExample
{
public:
    void demonstrate();

private:
    Node<int> *createSampleTree();
    void inOrderTraversal(Node<int> *node);
    void preOrderTraversal(Node<int> *node);
    void postOrderTraversal(Node<int> *node);
    void deleteTree(Node<int> *node);
};

#endif // TRAVERSETREEEXAMPLE_H