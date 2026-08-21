#ifndef PRIORITYQUEUEEXAMPLE_H
#define PRIORITYQUEUEEXAMPLE_H

#include <iostream>

#pragma once
#include <vector>
#include <string>
#include <iostream>

struct Task
{
    std::string name;
    int priority;

    // For max-heap (higher priority value = higher priority)
    bool operator<(const Task &other) const
    {
        return priority < other.priority;
    }
};

struct Patient
{
    std::string name;
    int urgency; // 1 = low, 5 = critical
    std::string condition;

    // For max-heap (higher urgency = higher priority)
    bool operator<(const Patient &other) const
    {
        return urgency < other.urgency;
    }
};

class PriorityQueueExample
{
public:
    static void demonstrate();

    // Custom MinHeap implementation
    class MinHeap
    {
    private:
        std::vector<int> heap;

        void heapifyUp(int index);
        void heapifyDown(int index);

    public:
        void insert(int value);
        int extractMin();
        int getMin() const;
        bool isEmpty() const { return heap.empty(); }
        size_t size() const { return heap.size(); }
        void printHeap() const;
    };

private:
    static std::vector<int> heapSort(std::vector<int> arr);
    static std::vector<int> findKLargest(const std::vector<int> &arr, int k);
    static void printVector(const std::vector<int> &vec);
};

#endif