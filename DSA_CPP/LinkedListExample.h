#ifndef LINKEDLISTEXAMPLE_H
#define LINKEDLISTEXAMPLE_H
#include <iostream>

template <typename T>
class Node; // Forward declaration

class LinkedListExample
{
public:
    void demonstrate();

private:
    void printList(Node<int> *head);
    Node<int> *insertAtBeginning(Node<int> *head, int data);
    Node<int> *insertAtEnd(Node<int> *head, int data);
    bool search(Node<int> *head, int data);
    Node<int> *deleteElement(Node<int> *head, int data);
    void deleteList(Node<int> *head);
};

#endif
