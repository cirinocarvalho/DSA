#include "SelectionSortExample.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

void SelectionSortExample::demonstrate()
{
    std::cout << "\n=== Selection Sort Example ===\n";
    std::cout << "Simple in-place sorting algorithm that finds minimum and swaps\n";
    std::cout << "Time Complexity: O(n²) for all cases (best, average, worst)\n";
    std::cout << "Space Complexity: O(1) - in-place sorting\n";
    std::cout << "Stability: Not stable (equal elements may change relative order)\n\n";

    // Basic example
    std::cout << "--- Basic Selection Sort ---\n";
    std::vector<int> basicArray = {64, 34, 25, 12, 22, 11, 90};

    std::cout << "Original array: ";
    printArray(basicArray);

    std::cout << "\nStep-by-step sorting process:\n";
    selectionSortVerbose(basicArray);

    std::cout << "Final sorted array: ";
    printArray(basicArray);

    // Demonstrate with different scenarios
    std::cout << "\n--- Different Scenarios ---\n";

    // Already sorted array
    std::vector<int> sortedArray = {1, 2, 3, 4, 5, 6, 7};
    std::cout << "Already sorted: ";
    printArray(sortedArray);
    selectionSort(sortedArray);
    std::cout << "After selection sort: ";
    printArray(sortedArray);

    // Reverse sorted array
    std::vector<int> reverseArray = {7, 6, 5, 4, 3, 2, 1};
    std::cout << "\nReverse sorted: ";
    printArray(reverseArray);
    selectionSort(reverseArray);
    std::cout << "After selection sort: ";
    printArray(reverseArray);

    // Array with duplicates
    std::vector<int> duplicateArray = {5, 2, 8, 2, 9, 1, 5, 5};
    std::cout << "\nWith duplicates: ";
    printArray(duplicateArray);
    selectionSort(duplicateArray);
    std::cout << "After selection sort: ";
    printArray(duplicateArray);

    // Single element
    std::vector<int> singleArray = {42};
    std::cout << "\nSingle element: ";
    printArray(singleArray);
    selectionSort(singleArray);
    std::cout << "After selection sort: ";
    printArray(singleArray);

    // Empty array
    std::vector<int> emptyArray = {};
    std::cout << "\nEmpty array: ";
    printArray(emptyArray);
    selectionSort(emptyArray);
    std::cout << "After selection sort: ";
    printArray(emptyArray);

    // Performance comparison
    std::cout << "\n--- Performance Comparison ---\n";
    performanceComparison();

    // Show number of comparisons and swaps
    std::cout << "\n--- Algorithm Analysis ---\n";
    std::vector<int> analysisArray = {5, 2, 8, 1, 9};
    std::cout << "Analyzing array: ";
    printArray(analysisArray);

    int comparisons = 0, swaps = 0;
    selectionSortWithCounting(analysisArray, comparisons, swaps);

    std::cout << "Total comparisons: " << comparisons << std::endl;
    std::cout << "Total swaps: " << swaps << std::endl;
    std::cout << "Expected comparisons for n=" << 5 << ": " << (5 * (5 - 1)) / 2 << std::endl;

    // Demonstrate stability issue
    std::cout << "\n--- Stability Demonstration ---\n";
    demonstrateStability();

    std::cout << "\n--- Selection Sort vs Other Algorithms ---\n";
    std::cout << "Selection Sort:\n";
    std::cout << "✓ Simple implementation\n";
    std::cout << "✓ In-place sorting (O(1) space)\n";
    std::cout << "✓ Minimum number of swaps (O(n))\n";
    std::cout << "✓ Performance doesn't depend on input order\n";
    std::cout << "✗ Always O(n²) time complexity\n";
    std::cout << "✗ Not stable\n";
    std::cout << "✗ Not adaptive (no benefit for sorted data)\n";

    std::cout << "\nComparison with other O(n²) algorithms:\n";
    std::cout << "• Bubble Sort: More swaps, adaptive, stable\n";
    std::cout << "• Insertion Sort: Adaptive, stable, better for small/sorted data\n";
    std::cout << "• Selection Sort: Fewer swaps, consistent performance\n";

    std::cout << "\n--- Use Cases ---\n";
    std::cout << "• When memory is limited (in-place sorting)\n";
    std::cout << "• When minimizing swaps is important (expensive writes)\n";
    std::cout << "• Educational purposes (simple to understand)\n";
    std::cout << "• Small datasets where simplicity is preferred\n";
    std::cout << "• When stability is not required\n";
}

void SelectionSortExample::selectionSort(std::vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        // Find the minimum element in remaining unsorted array
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        if (minIndex != i)
        {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}

void SelectionSortExample::selectionSortVerbose(std::vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        std::cout << "\nPass " << (i + 1) << ":\n";
        std::cout << "  Finding minimum in range [" << i << ", " << (n - 1) << "]: ";

        int minIndex = i;
        int minValue = arr[i];

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
                minValue = arr[j];
            }
        }

        std::cout << "minimum is " << minValue << " at index " << minIndex << std::endl;

        if (minIndex != i)
        {
            std::cout << "  Swapping " << arr[i] << " with " << arr[minIndex] << std::endl;
            std::swap(arr[i], arr[minIndex]);
        }
        else
        {
            std::cout << "  No swap needed (minimum is already at position " << i << ")" << std::endl;
        }

        std::cout << "  Array after pass " << (i + 1) << ": ";
        printArray(arr);
    }
}

void SelectionSortExample::selectionSortWithCounting(std::vector<int> &arr, int &comparisons, int &swaps)
{
    int n = arr.size();
    comparisons = 0;
    swaps = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            comparisons++;
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            std::swap(arr[i], arr[minIndex]);
            swaps++;
        }
    }
}

void SelectionSortExample::demonstrateStability()
{
    // Using a struct to show stability issues
    struct Element
    {
        int value;
        char id;

        bool operator<(const Element &other) const
        {
            return value < other.value;
        }
    };

    std::vector<Element> elements = {{5, 'A'}, {2, 'B'}, {5, 'C'}, {1, 'D'}, {5, 'E'}};

    std::cout << "Original order (value, id): ";
    for (const auto &elem : elements)
    {
        std::cout << "(" << elem.value << "," << elem.id << ") ";
    }
    std::cout << std::endl;

    // Manual selection sort to show instability
    int n = elements.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (elements[j] < elements[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            std::swap(elements[i], elements[minIndex]);
        }
    }

    std::cout << "After selection sort: ";
    for (const auto &elem : elements)
    {
        std::cout << "(" << elem.value << "," << elem.id << ") ";
    }
    std::cout << std::endl;
    std::cout << "Notice: Original order of equal elements (5,A), (5,C), (5,E) is not preserved\n";
}

void SelectionSortExample::performanceComparison()
{
    std::vector<int> sizes = {1000, 2000, 4000};

    std::cout << "Performance with different array sizes:\n";
    std::cout << "Size\tTime (ms)\tComparisons\tSwaps\n";
    std::cout << "----\t---------\t-----------\t-----\n";

    for (int size : sizes)
    {
        // Create random array
        std::vector<int> arr(size);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, size * 10);

        for (int i = 0; i < size; i++)
        {
            arr[i] = dis(gen);
        }

        // Measure time
        auto start = std::chrono::high_resolution_clock::now();

        int comparisons = 0, swaps = 0;
        selectionSortWithCounting(arr, comparisons, swaps);

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        std::cout << size << "\t" << duration.count() << "\t\t" << comparisons << "\t\t" << swaps << std::endl;
    }
}

void SelectionSortExample::printArray(const std::vector<int> &arr)
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