#include "LinearSearchExample.h"
#include <vector>
#include <iostream>

void LinearSearchExample::demonstrate()
{
    std::cout << "\n=== Linear Search Example ===\n";
    std::cout << "Linear Search: Sequential search through array elements\n";
    std::cout << "Time Complexity: O(n) - Must check each element in worst case\n";
    std::cout << "Space Complexity: O(1) - No additional space needed\n\n";

    // Test array
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 42};

    std::cout << "Array: ";
    printArray(arr);

    // Test different search values
    std::vector<int> searchValues = {22, 90, 99, 12, 100, 64};

    std::cout << "\n--- Search Results ---\n";
    for (int target : searchValues)
    {
        int result = linearSearch(arr, target);
        if (result != -1)
        {
            std::cout << "Element " << target << " found at index " << result << std::endl;
        }
        else
        {
            std::cout << "Element " << target << " not found in array" << std::endl;
        }
    }

    // Demonstrate search with step-by-step process
    std::cout << "\n--- Step-by-step search for value 22 ---\n";
    linearSearchVerbose(arr, 22);

    std::cout << "\n--- Linear Search Properties ---\n";
    std::cout << "✓ Works on unsorted arrays\n";
    std::cout << "✓ Simple to implement and understand\n";
    std::cout << "✓ No preprocessing required\n";
    std::cout << "✓ Can find all occurrences easily\n";
    std::cout << "✗ Slow for large datasets O(n)\n";
    std::cout << "✗ Not efficient compared to other search methods\n";

    std::cout << "\n--- Use Cases ---\n";
    std::cout << "• Small datasets (< 100 elements)\n";
    std::cout << "• Unsorted data where sorting isn't feasible\n";
    std::cout << "• When simplicity is more important than speed\n";
    std::cout << "• Finding all occurrences of an element\n";
    std::cout << "• One-time searches on unsorted data\n";
}

int LinearSearchExample::linearSearch(const std::vector<int> &arr, int target)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
        {
            return i; // Return index where element is found
        }
    }
    return -1; // Element not found
}

void LinearSearchExample::linearSearchVerbose(const std::vector<int> &arr, int target)
{
    std::cout << "Searching for " << target << ":\n";

    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << "Step " << (i + 1) << ": Checking arr[" << i << "] = " << arr[i];

        if (arr[i] == target)
        {
            std::cout << " ✓ Found target!\n";
            std::cout << "Total comparisons: " << (i + 1) << std::endl;
            return;
        }
        else
        {
            std::cout << " ✗ Not a match\n";
        }
    }

    std::cout << "Element not found after " << arr.size() << " comparisons.\n";
}

std::vector<int> LinearSearchExample::findAllOccurrences(const std::vector<int> &arr, int target)
{
    std::vector<int> indices;

    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
        {
            indices.push_back(i);
        }
    }

    return indices;
}

void LinearSearchExample::printArray(const std::vector<int> &arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i];
        if (i < arr.size() - 1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}