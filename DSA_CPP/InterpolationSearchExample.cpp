#include "InterpolationSearchExample.h"
#include <iostream>
#include <vector>
#include <random>
#include <chrono>

void InterpolationSearchExample::demonstrate()
{
    std::cout << "\n=== Interpolation Search Example ===\n";
    std::cout << "Enhanced binary search for uniformly distributed sorted data\n";
    std::cout << "Best Case: O(log log n), Average Case: O(log log n), Worst Case: O(n)\n";
    std::cout << "Space Complexity: O(1)\n";
    std::cout << "Requirements: Sorted array with uniformly distributed values\n\n";

    // Create different types of arrays for testing
    std::cout << "--- Testing with Uniformly Distributed Data ---\n";
    std::vector<int> uniformArray = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    std::cout << "Uniform array: ";
    printArray(uniformArray);

    // Test searches
    std::vector<int> searchValues = {30, 70, 100, 5, 95};

    for (int value : searchValues)
    {
        std::cout << "\nSearching for " << value << ":\n";

        // Interpolation Search
        int interpResult = interpolationSearch(uniformArray, value);
        std::cout << "Interpolation Search: ";
        if (interpResult != -1)
        {
            std::cout << "Found at index " << interpResult << std::endl;
        }
        else
        {
            std::cout << "Not found" << std::endl;
        }

        // Binary Search for comparison
        int binaryResult = binarySearch(uniformArray, value);
        std::cout << "Binary Search: ";
        if (binaryResult != -1)
        {
            std::cout << "Found at index " << binaryResult << std::endl;
        }
        else
        {
            std::cout << "Not found" << std::endl;
        }
    }

    // Test with non-uniform data
    std::cout << "\n--- Testing with Non-Uniform Data ---\n";
    std::vector<int> nonUniformArray = {1, 2, 3, 100, 200, 300, 400, 10000, 20000, 30000};

    std::cout << "Non-uniform array: ";
    printArray(nonUniformArray);

    std::cout << "\nNote: Interpolation search may perform poorly on non-uniform data\n";

    int testValue = 300;
    std::cout << "\nSearching for " << testValue << ":\n";

    int interpResult = interpolationSearch(nonUniformArray, testValue);
    std::cout << "Interpolation Search: ";
    if (interpResult != -1)
    {
        std::cout << "Found at index " << interpResult << std::endl;
    }
    else
    {
        std::cout << "Not found" << std::endl;
    }

    // Performance comparison with larger dataset
    std::cout << "\n--- Performance Comparison ---\n";
    std::cout << "Creating large uniform dataset (10,000 elements)...\n";

    std::vector<int> largeArray;
    for (int i = 1; i <= 10000; i++)
    {
        largeArray.push_back(i * 10); // Uniform distribution: 10, 20, 30, ..., 100000
    }

    int targetValue = 50000; // Should be at index 4999

    std::cout << "Searching for " << targetValue << " in array of " << largeArray.size() << " elements:\n";

    // Time Interpolation Search
    auto start = std::chrono::high_resolution_clock::now();
    int interpIndex = interpolationSearch(largeArray, targetValue);
    auto end = std::chrono::high_resolution_clock::now();
    auto interpTime = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    // Time Binary Search
    start = std::chrono::high_resolution_clock::now();
    int binaryIndex = binarySearch(largeArray, targetValue);
    end = std::chrono::high_resolution_clock::now();
    auto binaryTime = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    std::cout << "Interpolation Search: Found at index " << interpIndex << " (Time: " << interpTime.count() << " ns)" << std::endl;
    std::cout << "Binary Search: Found at index " << binaryIndex << " (Time: " << binaryTime.count() << " ns)" << std::endl;

    if (interpTime < binaryTime)
    {
        std::cout << "✓ Interpolation search was faster!" << std::endl;
    }
    else
    {
        std::cout << "• Binary search was faster (possibly due to small dataset or overhead)" << std::endl;
    }

    // Demonstrate step-by-step interpolation
    std::cout << "\n--- Step-by-Step Interpolation Search ---\n";
    std::vector<int> demoArray = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    std::cout << "Array: ";
    printArray(demoArray);
    std::cout << "\nSearching for 70 with detailed steps:\n";
    interpolationSearchVerbose(demoArray, 70);

    std::cout << "\n--- Algorithm Comparison ---\n";
    std::cout << "Linear Search:\n";
    std::cout << "• Time: O(n)\n";
    std::cout << "• Works on unsorted data\n";
    std::cout << "• Simple implementation\n";

    std::cout << "\nBinary Search:\n";
    std::cout << "• Time: O(log n)\n";
    std::cout << "• Requires sorted data\n";
    std::cout << "• Consistent performance\n";

    std::cout << "\nInterpolation Search:\n";
    std::cout << "• Time: O(log log n) best/average, O(n) worst\n";
    std::cout << "• Requires sorted, uniformly distributed data\n";
    std::cout << "• Can be much faster than binary search\n";
    std::cout << "• Performance depends on data distribution\n";

    std::cout << "\n--- Use Cases ---\n";
    std::cout << "• Large datasets with uniform distribution\n";
    std::cout << "• Numerical data (ages, scores, measurements)\n";
    std::cout << "• Time series data with regular intervals\n";
    std::cout << "• When binary search is too slow for very large datasets\n";
    std::cout << "• Database indexing with uniform key distribution\n";
}

int InterpolationSearchExample::interpolationSearch(const std::vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high && target >= arr[low] && target <= arr[high])
    {
        // If array has only one element
        if (low == high)
        {
            return (arr[low] == target) ? low : -1;
        }

        // Calculate the probable position using interpolation formula
        int pos = low + (((double)(target - arr[low]) / (arr[high] - arr[low])) * (high - low));

        if (arr[pos] == target)
        {
            return pos;
        }

        if (arr[pos] < target)
        {
            low = pos + 1;
        }
        else
        {
            high = pos - 1;
        }
    }

    return -1; // Element not found
}

int InterpolationSearchExample::binarySearch(const std::vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }

        if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1; // Element not found
}

void InterpolationSearchExample::interpolationSearchVerbose(const std::vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;
    int step = 1;

    std::cout << "Target: " << target << std::endl;

    while (low <= high && target >= arr[low] && target <= arr[high])
    {
        std::cout << "\nStep " << step++ << ":\n";
        std::cout << "  Range: [" << low << ", " << high << "] = [" << arr[low] << ", " << arr[high] << "]" << std::endl;

        if (low == high)
        {
            if (arr[low] == target)
            {
                std::cout << "  Found at index " << low << "!" << std::endl;
                return;
            }
            else
            {
                std::cout << "  Not found!" << std::endl;
                return;
            }
        }

        // Calculate interpolated position
        double ratio = (double)(target - arr[low]) / (arr[high] - arr[low]);
        int pos = low + (ratio * (high - low));

        std::cout << "  Interpolation ratio: " << ratio << std::endl;
        std::cout << "  Calculated position: " << pos << " (value: " << arr[pos] << ")" << std::endl;

        if (arr[pos] == target)
        {
            std::cout << "  Found at index " << pos << "!" << std::endl;
            return;
        }

        if (arr[pos] < target)
        {
            std::cout << "  " << arr[pos] << " < " << target << ", searching right half" << std::endl;
            low = pos + 1;
        }
        else
        {
            std::cout << "  " << arr[pos] << " > " << target << ", searching left half" << std::endl;
            high = pos - 1;
        }
    }

    std::cout << "  Target not in valid range, not found!" << std::endl;
}

void InterpolationSearchExample::printArray(const std::vector<int> &arr)
{
    std::cout << "[";
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i];
        if (i < arr.size() - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}