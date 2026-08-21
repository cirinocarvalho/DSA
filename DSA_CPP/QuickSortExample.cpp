#include "QuickSortExample.h"
#include <vector>
#include <iostream>

void QuickSortExample::demonstrate()
{
    std::cout << "\n=== Quick Sort Example ===\n";
    std::cout << "Quick Sort: Divide-and-conquer in-place sorting algorithm\n";
    std::cout << "Time Complexity: O(n log n) average, O(n²) worst case\n";
    std::cout << "Space Complexity: O(log n) - Due to recursion stack\n";
    std::cout << "Stable: No - May change relative order of equal elements\n\n";

    // Test with different arrays
    std::vector<int> arr1 = {64, 34, 25, 12, 22, 11, 90};
    std::cout << "Example 1 - Random array:\n";
    demonstrateQuickSort(arr1);

    std::vector<int> arr2 = {10, 7, 8, 9, 1, 5};
    std::cout << "\nExample 2 - Another random array:\n";
    demonstrateQuickSort(arr2);

    std::vector<int> arr3 = {1, 2, 3, 4, 5};
    std::cout << "\nExample 3 - Already sorted (worst case):\n";
    demonstrateQuickSort(arr3);

    std::vector<int> arr4 = {5, 4, 3, 2, 1};
    std::cout << "\nExample 4 - Reverse sorted:\n";
    demonstrateQuickSort(arr4);

    std::cout << "\n--- Quick Sort Properties ---\n";
    std::cout << "✓ In-place sorting (low memory usage)\n";
    std::cout << "✓ Fast average case O(n log n)\n";
    std::cout << "✓ Cache-efficient due to in-place nature\n";
    std::cout << "✓ Widely used in practice\n";
    std::cout << "✗ Worst case O(n²) with poor pivot selection\n";
    std::cout << "✗ Not stable\n";
    std::cout << "✗ Performance depends on pivot selection\n";

    std::cout << "\n--- Use Cases ---\n";
    std::cout << "• General-purpose sorting when average case performance is key\n";
    std::cout << "• When memory usage should be minimal\n";
    std::cout << "• Standard library implementations (with optimizations)\n";
    std::cout << "• When stability is not required\n";
}

void QuickSortExample::demonstrateQuickSort(std::vector<int> arr)
{
    std::cout << "Original array: ";
    printArray(arr);

    quickSort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array:   ";
    printArray(arr);
}

void QuickSortExample::quickSort(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        // Partition the array and get the pivot index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int QuickSortExample::partition(std::vector<int> &arr, int low, int high)
{
    // Choose the rightmost element as pivot
    int pivot = arr[high];

    // Index of smaller element (indicates right position of pivot)
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            i++; // Increment index of smaller element
            swap(arr, i, j);
        }
    }

    // Place pivot in its correct position
    swap(arr, i + 1, high);
    return i + 1;
}

void QuickSortExample::swap(std::vector<int> &arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void QuickSortExample::printArray(const std::vector<int> &arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i];
        if (i < arr.size() - 1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}