#include "PriorityQueueExample.h"
#include <iostream>
#include <queue>
#include <vector>
#include <functional>

void PriorityQueueExample::demonstrate()
{
    std::cout << "\n=== Priority Queue Example ===\n";
    std::cout << "Abstract data type where elements have priorities\n";
    std::cout << "Implementation: Usually binary heap (complete binary tree)\n";
    std::cout << "Time Complexity: Insert O(log n), Extract-Max/Min O(log n), Peek O(1)\n";
    std::cout << "Space Complexity: O(n)\n\n";

    // Basic max-heap (default behavior in C++)
    std::cout << "--- Max Priority Queue (Max-Heap) ---\n";
    std::priority_queue<int> maxHeap;

    std::cout << "Inserting elements: 10, 30, 20, 5, 1, 40, 15\n";
    std::vector<int> elements = {10, 30, 20, 5, 1, 40, 15};

    for (int elem : elements)
    {
        maxHeap.push(elem);
        std::cout << "Inserted " << elem << " - Top element: " << maxHeap.top() << " (Size: " << maxHeap.size() << ")" << std::endl;
    }

    std::cout << "\nExtracting all elements (highest priority first):\n";
    while (!maxHeap.empty())
    {
        std::cout << "Extracted: " << maxHeap.top() << " (Remaining size: " << (maxHeap.size() - 1) << ")" << std::endl;
        maxHeap.pop();
    }

    // Min-heap
    std::cout << "\n--- Min Priority Queue (Min-Heap) ---\n";
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    std::cout << "Inserting same elements into min-heap:\n";
    for (int elem : elements)
    {
        minHeap.push(elem);
        std::cout << "Inserted " << elem << " - Top element: " << minHeap.top() << " (Size: " << minHeap.size() << ")" << std::endl;
    }

    std::cout << "\nExtracting all elements (lowest priority first):\n";
    while (!minHeap.empty())
    {
        std::cout << "Extracted: " << minHeap.top() << " (Remaining size: " << (minHeap.size() - 1) << ")" << std::endl;
        minHeap.pop();
    }

    // Custom priority with structs
    std::cout << "\n--- Custom Priority: Task Scheduling ---\n";
    std::priority_queue<Task> taskQueue;

    std::cout << "Adding tasks with different priorities:\n";
    taskQueue.push({"Email", 2});
    taskQueue.push({"Emergency Fix", 5});
    taskQueue.push({"Documentation", 1});
    taskQueue.push({"Code Review", 4});
    taskQueue.push({"Meeting", 3});

    std::cout << "\nProcessing tasks in priority order:\n";
    while (!taskQueue.empty())
    {
        Task task = taskQueue.top();
        taskQueue.pop();
        std::cout << "Processing: " << task.name << " (Priority: " << task.priority << ")" << std::endl;
    }

    // Patient priority queue
    std::cout << "\n--- Hospital Emergency Room Simulation ---\n";
    std::priority_queue<Patient> emergencyRoom;

    emergencyRoom.push({"John Doe", 2, "Broken arm"});
    emergencyRoom.push({"Jane Smith", 5, "Heart attack"});
    emergencyRoom.push({"Bob Johnson", 1, "Minor cut"});
    emergencyRoom.push({"Alice Brown", 4, "Difficulty breathing"});
    emergencyRoom.push({"Charlie Wilson", 3, "Severe headache"});

    std::cout << "Treating patients in priority order:\n";
    while (!emergencyRoom.empty())
    {
        Patient patient = emergencyRoom.top();
        emergencyRoom.pop();
        std::cout << "Treating: " << patient.name << " - " << patient.condition
                  << " (Urgency: " << patient.urgency << ")" << std::endl;
    }

    // Demonstrate custom MinHeap implementation
    std::cout << "\n--- Custom Min-Heap Implementation ---\n";
    MinHeap minHeapCustom;

    std::cout << "Inserting: 15, 10, 20, 8, 25, 30, 12\n";
    std::vector<int> heapElements = {15, 10, 20, 8, 25, 30, 12};

    for (int elem : heapElements)
    {
        minHeapCustom.insert(elem);
        std::cout << "Inserted " << elem << " - Min element: " << minHeapCustom.getMin() << std::endl;
        minHeapCustom.printHeap();
    }

    std::cout << "\nExtracting minimum elements:\n";
    while (!minHeapCustom.isEmpty())
    {
        int min = minHeapCustom.extractMin();
        std::cout << "Extracted: " << min << std::endl;
        if (!minHeapCustom.isEmpty())
        {
            std::cout << "New min: " << minHeapCustom.getMin() << std::endl;
            minHeapCustom.printHeap();
        }
    }

    // Heap sort demonstration
    std::cout << "\n--- Heap Sort Using Priority Queue ---\n";
    std::vector<int> unsorted = {64, 34, 25, 12, 22, 11, 90};
    std::cout << "Original array: ";
    printVector(unsorted);

    std::vector<int> heapSorted = heapSort(unsorted);
    std::cout << "Heap sorted: ";
    printVector(heapSorted);

    // k largest elements
    std::cout << "\n--- Find K Largest Elements ---\n";
    std::vector<int> numbers = {1, 23, 12, 9, 30, 2, 50};
    int k = 3;
    std::cout << "Array: ";
    printVector(numbers);

    std::vector<int> kLargest = findKLargest(numbers, k);
    std::cout << k << " largest elements: ";
    printVector(kLargest);

    // Dijkstra's algorithm setup (conceptual)
    std::cout << "\n--- Priority Queue in Algorithms ---\n";
    std::cout << "Common uses:\n";
    std::cout << "• Dijkstra's shortest path algorithm\n";
    std::cout << "• Prim's minimum spanning tree\n";
    std::cout << "• A* pathfinding algorithm\n";
    std::cout << "• Huffman coding\n";
    std::cout << "• Operating system task scheduling\n";
    std::cout << "• Event simulation\n";

    std::cout << "\n--- Heap vs Other Data Structures ---\n";
    std::cout << "Priority Queue (Heap):\n";
    std::cout << "✓ Efficient insert/extract: O(log n)\n";
    std::cout << "✓ Space efficient: O(n)\n";
    std::cout << "✓ Can be implemented as array\n";
    std::cout << "✗ No arbitrary deletion\n";
    std::cout << "✗ Not sorted order traversal\n";

    std::cout << "\nSorted Array:\n";
    std::cout << "✓ Extract min/max: O(1)\n";
    std::cout << "✗ Insert: O(n)\n";
    std::cout << "✗ Maintain sorted order expensive\n";

    std::cout << "\nUnsorted Array:\n";
    std::cout << "✓ Insert: O(1)\n";
    std::cout << "✗ Extract min/max: O(n)\n";

    std::cout << "\n--- Use Cases ---\n";
    std::cout << "• Task scheduling systems\n";
    std::cout << "• Graph algorithms (shortest path)\n";
    std::cout << "• Event-driven simulations\n";
    std::cout << "• Operating system process scheduling\n";
    std::cout << "• Data compression algorithms\n";
    std::cout << "• Finding k largest/smallest elements\n";
}

std::vector<int> PriorityQueueExample::heapSort(std::vector<int> arr)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    // Insert all elements into min-heap
    for (int elem : arr)
    {
        minHeap.push(elem);
    }

    // Extract elements in sorted order
    std::vector<int> sorted;
    while (!minHeap.empty())
    {
        sorted.push_back(minHeap.top());
        minHeap.pop();
    }

    return sorted;
}

std::vector<int> PriorityQueueExample::findKLargest(const std::vector<int> &arr, int k)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    for (int elem : arr)
    {
        if (minHeap.size() < k)
        {
            minHeap.push(elem);
        }
        else if (elem > minHeap.top())
        {
            minHeap.pop();
            minHeap.push(elem);
        }
    }

    std::vector<int> result;
    while (!minHeap.empty())
    {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    return result;
}

void PriorityQueueExample::printVector(const std::vector<int> &vec)
{
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i];
        if (i < vec.size() - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// MinHeap implementation methods
void PriorityQueueExample::MinHeap::insert(int value)
{
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

int PriorityQueueExample::MinHeap::extractMin()
{
    if (isEmpty())
    {
        throw std::runtime_error("Heap is empty");
    }

    int min = heap[0];
    heap[0] = heap.back();
    heap.pop_back();

    if (!isEmpty())
    {
        heapifyDown(0);
    }

    return min;
}

int PriorityQueueExample::MinHeap::getMin() const
{
    if (isEmpty())
    {
        throw std::runtime_error("Heap is empty");
    }
    return heap[0];
}

void PriorityQueueExample::MinHeap::heapifyUp(int index)
{
    if (index == 0)
        return;

    int parentIndex = (index - 1) / 2;
    if (heap[index] < heap[parentIndex])
    {
        std::swap(heap[index], heap[parentIndex]);
        heapifyUp(parentIndex);
    }
}

void PriorityQueueExample::MinHeap::heapifyDown(int index)
{
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    if (leftChild < heap.size() && heap[leftChild] < heap[smallest])
    {
        smallest = leftChild;
    }

    if (rightChild < heap.size() && heap[rightChild] < heap[smallest])
    {
        smallest = rightChild;
    }

    if (smallest != index)
    {
        std::swap(heap[index], heap[smallest]);
        heapifyDown(smallest);
    }
}

void PriorityQueueExample::MinHeap::printHeap() const
{
    std::cout << "Heap: [";
    for (size_t i = 0; i < heap.size(); i++)
    {
        std::cout << heap[i];
        if (i < heap.size() - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}