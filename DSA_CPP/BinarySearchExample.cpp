#include "BinarySearchExample.h"

void BinarySearchExample::demonstrate()
{
    std::cout << "\n=== Binary Search Example ===\n";
    std::cout << "Binary Search: Efficient search algorithm for sorted arrays\n";
    std::cout << "Time Complexity: O(log n)\n";
    std::cout << "Space Complexity: O(1) iterative, O(log n) recursive\n\n";

    // Create a sorted array
    std::vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78};
    printArray(arr, "Sorted Array");

    // Test cases
    std::vector<int> targets = {23, 5, 78, 1, 100, 45};

    std::cout << "\n--- Iterative Binary Search ---\n";
    for (int target : targets)
    {
        int result = binarySearch(arr, target);
        if (result != -1)
        {
            std::cout << "Element " << target << " found at index " << result << std::endl;
        }
        else
        {
            std::cout << "Element " << target << " not found in array" << std::endl;
        }
    }

    std::cout << "\n--- Recursive Binary Search ---\n";
    for (int target : targets)
    {
        int result = binarySearchRecursive(arr, target, 0, arr.size() - 1);
        if (result != -1)
        {
            std::cout << "Element " << target << " found at index " << result << std::endl;
        }
        else
        {
            std::cout << "Element " << target << " not found in array" << std::endl;
        }
    }
}

int BinarySearchExample::binarySearch(const std::vector<int> &arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2; // Avoid overflow

        if (arr[mid] == target)
        {
            return mid;
        }

        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1; // Element not found
}

int BinarySearchExample::binarySearchRecursive(const std::vector<int> &arr, int target, int left, int right)
{
    if (left > right)
    {
        return -1; // Base case: element not found
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
    {
        return mid;
    }

    if (arr[mid] < target)
    {
        return binarySearchRecursive(arr, target, mid + 1, right);
    }
    else
    {
        return binarySearchRecursive(arr, target, left, mid - 1);
    }
}

void BinarySearchExample::printArray(const std::vector<int> &arr, const std::string &message)
{
    std::cout << message << ": ";
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i];
        if (i < arr.size() - 1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}