#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
public:
    T data;
    Node *next;
    Node *prev;  // For doubly linked lists
    Node *left;  // For binary trees
    Node *right; // For binary trees

    // Constructors
    Node();
    Node(T data);
    Node(T data, Node *next);
    Node(T data, Node *left, Node *right);

    // Destructor
    ~Node();
};

// Template implementation must be in header file
template <typename T>
Node<T>::Node() : data(T{}), next(nullptr), prev(nullptr), left(nullptr), right(nullptr) {}

template <typename T>
Node<T>::Node(T data) : data(data), next(nullptr), prev(nullptr), left(nullptr), right(nullptr) {}

template <typename T>
Node<T>::Node(T data, Node *next) : data(data), next(next), prev(nullptr), left(nullptr), right(nullptr) {}

template <typename T>
Node<T>::Node(T data, Node *left, Node *right) : data(data), next(nullptr), prev(nullptr), left(left), right(right) {}

template <typename T>
Node<T>::~Node()
{
    // Destructor - memory cleanup handled by the data structure implementations
}

#endif // NODE_H