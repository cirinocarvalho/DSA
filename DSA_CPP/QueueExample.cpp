#include "QueueExample.h"

void QueueExample::demonstrate()
{
    std::cout << "\n=== Queue Example ===\n";
    std::cout << "Queue: FIFO (First In, First Out) data structure\n";
    std::cout << "Time Complexity - Enqueue: O(1), Dequeue: O(1)\n";
    std::cout << "Space Complexity: O(n)\n\n";

    basicQueueOperations();
}

void QueueExample::basicQueueOperations()
{
    std::cout << "--- Using STL Queue ---\n";
    std::queue<int> queue;

    // Enqueue elements
    std::cout << "Enqueuing elements: 10, 20, 30, 40, 50\n";
    for (int i = 1; i <= 5; i++)
    {
        queue.push(i * 10);
        std::cout << "Enqueued: " << (i * 10) << ", Size: " << queue.size() << std::endl;
    }

    std::cout << "\nFront element: " << queue.front() << std::endl;
    std::cout << "Back element: " << queue.back() << std::endl;

    // Dequeue elements
    std::cout << "\nDequeuing all elements:\n";
    while (!queue.empty())
    {
        std::cout << "Dequeued: " << queue.front() << ", Size: " << queue.size() - 1 << std::endl;
        queue.pop();
    }

    std::cout << "Queue is " << (queue.empty() ? "empty" : "not empty") << std::endl;
}

void QueueExample::customQueueImplementation()
{
    // Custom implementation would go here
}