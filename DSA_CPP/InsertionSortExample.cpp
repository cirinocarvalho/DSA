#include "InsertionSortExample.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

void InsertionSortExample::demonstrate()
{
    std::cout << "\n=== Insertion Sort Example ===\n";
    std::cout << "Incremental sorting algorithm that builds sorted array one element at a time\n";
    std::cout << "Best Case: O(n) - already sorted, Average/Worst Case: O(n²)\n";
    std::cout << "Space Complexity: O(1) - in-place sorting\n";
    std::cout << "Properties: Stable, adaptive, online algorithm\n\n";

    // Basic example
    std::cout << "--- Basic Insertion Sort ---\n";
    std::vector<int> basicArray = {5, 2, 4, 6, 1, 3};

    std::cout << "Original array: ";
    printArray(basicArray);

    std::cout << "\nStep-by-step sorting process:\n";
    insertionSortVerbose(basicArray);

    std::cout << "Final sorted array: ";
    printArray(basicArray);

    // Demonstrate different scenarios
    std::cout << "\n--- Different Input Scenarios ---\n";

    // Already sorted (best case)
    std::vector<int> sortedArray = {1, 2, 3, 4, 5, 6, 7};
    std::cout << "Already sorted (best case): ";
    printArray(sortedArray);

    int comparisons = 0, shifts = 0;
    insertionSortWithCounting(sortedArray, comparisons, shifts);
    std::cout << "Comparisons: " << comparisons << ", Shifts: " << shifts << std::endl;
    std::cout << "Result: ";
    printArray(sortedArray);

    // Reverse sorted (worst case)
    std::vector<int> reverseArray = {7, 6, 5, 4, 3, 2, 1};
    std::cout << "\nReverse sorted (worst case): ";
    printArray(reverseArray);

    comparisons = 0;
    shifts = 0;
    insertionSortWithCounting(reverseArray, comparisons, shifts);
    std::cout << "Comparisons: " << comparisons << ", Shifts: " << shifts << std::endl;
    std::cout << "Result: ";
    printArray(reverseArray);

    // Nearly sorted
    std::vector<int> nearlyArray = {1, 2, 4, 3, 5, 6, 7};
    std::cout << "\nNearly sorted: ";
    printArray(nearlyArray);

    comparisons = 0;
    shifts = 0;
    insertionSortWithCounting(nearlyArray, comparisons, shifts);
    std::cout << "Comparisons: " << comparisons << ", Shifts: " << shifts << std::endl;
    std::cout << "Result: ";
    printArray(nearlyArray);

    // Array with duplicates
    std::vector<int> duplicateArray = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    std::cout << "\nWith duplicates: ";
    printArray(duplicateArray);
    insertionSort(duplicateArray);
    std::cout << "After sorting: ";
    printArray(duplicateArray);

    // Single element and empty arrays
    std::vector<int> singleArray = {42};
    std::cout << "\nSingle element: ";
    printArray(singleArray);
    insertionSort(singleArray);
    std::cout << "After sorting: ";
    printArray(singleArray);

    std::vector<int> emptyArray = {};
    std::cout << "\nEmpty array: ";
    printArray(emptyArray);
    insertionSort(emptyArray);
    std::cout << "After sorting: ";
    printArray(emptyArray);

    // Performance comparison
    std::cout << "\n--- Performance Analysis ---\n";
    performanceComparison();

    // Binary insertion sort demonstration
    std::cout << "\n--- Binary Insertion Sort ---\n";
    std::vector<int> binaryArray = {5, 2, 4, 6, 1, 3};
    std::cout << "Original array: ";
    printArray(binaryArray);

    std::cout << "Using binary search to find insertion position:\n";
    binaryInsertionSortVerbose(binaryArray);
    std::cout << "Final result: ";
    printArray(binaryArray);

    // Demonstrate stability
    std::cout << "\n--- Stability Demonstration ---\n";
    demonstrateStability();

    // Online algorithm demonstration
    std::cout << "\n--- Online Algorithm Demonstration ---\n";
    std::cout << "Processing stream of numbers: 5, 1, 9, 3, 7, 2\n";
    std::vector<int> stream = {5, 1, 9, 3, 7, 2};
    onlineInsertionSort(stream);

    std::cout << "\n--- Insertion Sort vs Other O(n²) Algorithms ---\n";
    std::cout << "Insertion Sort:\n";
    std::cout << "✓ Adaptive (O(n) for nearly sorted data)\n";
    std::cout << "✓ Stable (preserves relative order of equal elements)\n";
    std::cout << "✓ Online (can sort list as it receives it)\n";
    std::cout << "✓ In-place (O(1) extra memory)\n";
    std::cout << "✓ Simple implementation\n";
    std::cout << "✓ Efficient for small datasets\n";
    std::cout << "✗ O(n²) worst-case time complexity\n";

    std::cout << "\nComparison:\n";
    std::cout << "• Selection Sort: Always O(n²), not stable, fewer swaps\n";
    std::cout << "• Bubble Sort: O(n²), stable, more swaps, adaptive\n";
    std::cout << "• Insertion Sort: O(n²) worst, O(n) best, stable, adaptive\n";

    std::cout << "\n--- Use Cases ---\n";
    std::cout << "• Small datasets (typically n < 50)\n";
    std::cout << "• Nearly sorted data (takes advantage of O(n) best case)\n";
    std::cout << "• Online algorithms (sorting data as it arrives)\n";
    std::cout << "• As a subroutine in hybrid algorithms (e.g., Quicksort)\n";
    std::cout << "• When simplicity and stability are important\n";
    std::cout << "• Educational purposes (easy to understand and implement)\n";

    std::cout << "\n--- Real-world Applications ---\n";
    std::cout << "• Playing card sorting (natural human sorting method)\n";
    std::cout << "• Maintaining sorted order in dynamic lists\n";
    std::cout << "• Hybrid sorting algorithms (Timsort uses insertion sort)\n";
    std::cout << "• Small subarray sorting in divide-and-conquer algorithms\n";
}

void InsertionSortExample::insertionSort(std::vector<int> &arr)
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void InsertionSortExample::insertionSortVerbose(std::vector<int> &arr)
{
    int n = arr.size();

    std::cout << "Starting with: ";
    printArray(arr);

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        std::cout << "\nStep " << i << ": Insert " << key << " into sorted portion [0.." << (i - 1) << "]\n";
        std::cout << "  Sorted portion: [";
        for (int k = 0; k < i; k++)
        {
            std::cout << arr[k];
            if (k < i - 1)
                std::cout << ", ";
        }
        std::cout << "], Current element: " << key << std::endl;

        int j = i - 1;

        // Show the shifting process
        std::cout << "  Shifting: ";
        while (j >= 0 && arr[j] > key)
        {
            std::cout << arr[j] << " moves right, ";
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
        std::cout << "insert " << key << " at position " << (j + 1) << std::endl;

        std::cout << "  Array now: ";
        printArray(arr);
    }
}

void InsertionSortExample::insertionSortWithCounting(std::vector<int> &arr, int &comparisons, int &shifts)
{
    int n = arr.size();
    comparisons = 0;
    shifts = 0;

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0)
        {
            comparisons++;
            if (arr[j] > key)
            {
                arr[j + 1] = arr[j];
                shifts++;
                j--;
            }
            else
            {
                break;
            }
        }

        if (j + 1 != i)
        {
            arr[j + 1] = key;
        }
    }
}

void InsertionSortExample::binaryInsertionSort(std::vector<int> &arr)
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int insertPos = binarySearch(arr, 0, i - 1, key);

        // Shift elements to make room
        for (int j = i; j > insertPos; j--)
        {
            arr[j] = arr[j - 1];
        }

        arr[insertPos] = key;
    }
}

void InsertionSortExample::binaryInsertionSortVerbose(std::vector<int> &arr)
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        std::cout << "\nInserting " << key << " into sorted portion [0.." << (i - 1) << "]\n";

        int insertPos = binarySearch(arr, 0, i - 1, key);
        std::cout << "  Binary search found insertion position: " << insertPos << std::endl;

        if (insertPos < i)
        {
            std::cout << "  Shifting elements from position " << insertPos << " to " << (i - 1) << " one position right\n";

            // Shift elements to make room
            for (int j = i; j > insertPos; j--)
            {
                arr[j] = arr[j - 1];
            }
            arr[insertPos] = key;
        }

        std::cout << "  Array now: ";
        printArray(arr);
    }
}

int InsertionSortExample::binarySearch(const std::vector<int> &arr, int left, int right, int key)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] <= key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return left;
}

void InsertionSortExample::demonstrateStability()
{
    struct Element
    {
        int value;
        char id;

        bool operator>(const Element &other) const
        {
            return value > other.value;
        }
    };

    std::vector<Element> elements = {{5, 'A'}, {2, 'B'}, {5, 'C'}, {1, 'D'}, {5, 'E'}, {3, 'F'}};

    std::cout << "Original order (value, id): ";
    for (const auto &elem : elements)
    {
        std::cout << "(" << elem.value << "," << elem.id << ") ";
    }
    std::cout << std::endl;

    // Manual insertion sort to show stability
    int n = elements.size();
    for (int i = 1; i < n; i++)
    {
        Element key = elements[i];
        int j = i - 1;

        while (j >= 0 && elements[j] > key)
        {
            elements[j + 1] = elements[j];
            j--;
        }
        elements[j + 1] = key;
    }

    std::cout << "After insertion sort: ";
    for (const auto &elem : elements)
    {
        std::cout << "(" << elem.value << "," << elem.id << ") ";
    }
    std::cout << std::endl;
    std::cout << "Notice: Equal elements maintain their relative order (5,A) before (5,C) before (5,E)\n";
}

void InsertionSortExample::onlineInsertionSort(const std::vector<int> &stream)
{
    std::vector<int> sortedList;

    for (int value : stream)
    {
        std::cout << "Receiving: " << value << std::endl;

        // Find insertion position
        int pos = 0;
        while (pos < sortedList.size() && sortedList[pos] < value)
        {
            pos++;
        }

        // Insert at position
        sortedList.insert(sortedList.begin() + pos, value);

        std::cout << "  Sorted list: ";
        printArray(sortedList);
    }
}

void InsertionSortExample::performanceComparison()
{
    std::vector<int> sizes = {100, 500, 1000};

    std::cout << "Performance comparison (average of 5 runs):\n";
    std::cout << "Size\tRandom(ms)\tSorted(ms)\tReverse(ms)\n";
    std::cout << "----\t----------\t----------\t-----------\n";

    for (int size : sizes)
    {
        // Test with different data patterns
        long long randomTime = 0, sortedTime = 0, reverseTime = 0;

        for (int trial = 0; trial < 5; trial++)
        {
            // Random data
            std::vector<int> randomArr(size);
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(1, size * 10);

            for (int i = 0; i < size; i++)
            {
                randomArr[i] = dis(gen);
            }

            auto start = std::chrono::high_resolution_clock::now();
            insertionSort(randomArr);
            auto end = std::chrono::high_resolution_clock::now();
            randomTime += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

            // Sorted data
            std::vector<int> sortedArr(size);
            for (int i = 0; i < size; i++)
            {
                sortedArr[i] = i + 1;
            }

            start = std::chrono::high_resolution_clock::now();
            insertionSort(sortedArr);
            end = std::chrono::high_resolution_clock::now();
            sortedTime += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

            // Reverse sorted data
            std::vector<int> reverseArr(size);
            for (int i = 0; i < size; i++)
            {
                reverseArr[i] = size - i;
            }

            start = std::chrono::high_resolution_clock::now();
            insertionSort(reverseArr);
            end = std::chrono::high_resolution_clock::now();
            reverseTime += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        }

        std::cout << size << "\t" << (randomTime / 5000.0) << "\t\t"
                  << (sortedTime / 5000.0) << "\t\t" << (reverseTime / 5000.0) << std::endl;
    }
}

void InsertionSortExample::printArray(const std::vector<int> &arr)
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