#include "LinkedListExample.h"
#include "Node.h"
#include <iostream>

void LinkedListExample::demonstrate()
{
    std::cout << "\n=== Linked List Example ===\n";
    std::cout << "Linked List: Dynamic linear data structure\n";
    std::cout << "Time Complexity - Insert/Delete at head: O(1), Search: O(n)\n";
    std::cout << "Space Complexity: O(n)\n\n";

    // Create a simple singly linked list
    std::cout << "Creating a singly linked list with integers:\n";

    // Create nodes
    Node<int> *head = new Node<int>(10);
    head->next = new Node<int>(20);
    head->next->next = new Node<int>(30);
    head->next->next->next = new Node<int>(40);
    head->next->next->next->next = new Node<int>(50);

    std::cout << "Initial list: ";
    printList(head);

    // Insert at beginning
    std::cout << "\nInserting 5 at the beginning:\n";
    head = insertAtBeginning(head, 5);
    std::cout << "List after insertion: ";
    printList(head);

    // Insert at end
    std::cout << "\nInserting 60 at the end:\n";
    head = insertAtEnd(head, 60);
    std::cout << "List after insertion: ";
    printList(head);

    // Search for an element
    std::cout << "\nSearching for element 30:\n";
    if (search(head, 30))
    {
        std::cout << "Element 30 found in the list\n";
    }
    else
    {
        std::cout << "Element 30 not found in the list\n";
    }

    // Delete an element
    std::cout << "\nDeleting element 20:\n";
    head = deleteElement(head, 20);
    std::cout << "List after deletion: ";
    printList(head);

    std::cout << "\n--- Linked List Properties ---\n";
    std::cout << "✓ Dynamic size\n";
    std::cout << "✓ Efficient insertion/deletion at beginning O(1)\n";
    std::cout << "✓ Memory allocated as needed\n";
    std::cout << "✗ No random access O(n) to reach any element\n";
    std::cout << "✗ Extra memory for storing pointers\n";

    std::cout << "\n--- Use Cases ---\n";
    std::cout << "• Implementing stacks and queues\n";
    std::cout << "• When frequent insertions/deletions are needed\n";
    std::cout << "• When the size of data is unknown\n";
    std::cout << "• Undo functionality in applications\n";

    // Clean up memory
    deleteList(head);
}

void LinkedListExample::printList(Node<int> *head)
{
    Node<int> *current = head;
    while (current != nullptr)
    {
        std::cout << current->data;
        if (current->next != nullptr)
        {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << " -> NULL\n";
}

Node<int> *LinkedListExample::insertAtBeginning(Node<int> *head, int data)
{
    Node<int> *newNode = new Node<int>(data);
    newNode->next = head;
    return newNode;
}

Node<int> *LinkedListExample::insertAtEnd(Node<int> *head, int data)
{
    Node<int> *newNode = new Node<int>(data);

    if (head == nullptr)
    {
        return newNode;
    }

    Node<int> *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

bool LinkedListExample::search(Node<int> *head, int data)
{
    Node<int> *current = head;
    while (current != nullptr)
    {
        if (current->data == data)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

Node<int> *LinkedListExample::deleteElement(Node<int> *head, int data)
{
    if (head == nullptr)
    {
        return head;
    }

    // If head node contains the data to be deleted
    if (head->data == data)
    {
        Node<int> *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // Search for the node to be deleted
    Node<int> *current = head;
    while (current->next != nullptr && current->next->data != data)
    {
        current = current->next;
    }

    // If node found, delete it
    if (current->next != nullptr)
    {
        Node<int> *temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    return head;
}

void LinkedListExample::deleteList(Node<int> *head)
{
    while (head != nullptr)
    {
        Node<int> *temp = head;
        head = head->next;
        delete temp;
    }
}