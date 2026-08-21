#include "MergeSortExample.h"
#include <vector>
#include <iostream>

void MergeSortExample::demonstrate()
{
    std::cout << "\n=== Merge Sort Example ===\n";
    std::cout << "Merge Sort: Divide-and-conquer stable sorting algorithm\n";
    std::cout << "Time Complexity: O(n log n) - Best, Average, and Worst case\n";
    std::cout << "Space Complexity: O(n) - Additional space for merging\n";
    std::cout << "Stable: Yes - Maintains relative order of equal elements\n\n";

    // Test with different arrays
    std::vector<int> arr1 = {64, 34, 25, 12, 22, 11, 90};
    std::cout << "Example 1 - Random array:\n";
    demonstrateMergeSort(arr1);

    std::vector<int> arr2 = {5, 2, 4, 6, 1, 3};
    std::cout << "\nExample 2 - Small array:\n";
    demonstrateMergeSort(arr2);

    std::vector<int> arr3 = {1, 2, 3, 4, 5};
    std::cout << "\nExample 3 - Already sorted:\n";
    demonstrateMergeSort(arr3);

    std::vector<int> arr4 = {5, 4, 3, 2, 1};
    std::cout << "\nExample 4 - Reverse sorted:\n";
    demonstrateMergeSort(arr4);

    std::cout << "\n--- Merge Sort Properties ---\n";
    std::cout << "✓ Consistent O(n log n) performance\n";
    std::cout << "✓ Stable sorting algorithm\n";
    std::cout << "✓ Predictable performance - no worst case degradation\n";
    std::cout << "✓ Good for large datasets\n";
    std::cout << "✗ Requires additional O(n) space\n";
    std::cout << "✗ Not in-place sorting\n";

    std::cout << "\n--- Use Cases ---\n";
    std::cout << "• Large datasets requiring guaranteed O(n log n) performance\n";
    std::cout << "• When stability is important (maintaining relative order)\n";
    std::cout << "• External sorting (when data doesn't fit in memory)\n";
    std::cout << "• When consistent performance is more important than space\n";
}

void MergeSortExample::demonstrateMergeSort(std::vector<int> arr)
{
    std::cout << "Original array: ";
    printArray(arr);

    mergeSort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array:   ";
    printArray(arr);
}

void MergeSortExample::mergeSort(std::vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        // Find the middle point
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

void MergeSortExample::merge(std::vector<int> &arr, int left, int mid, int right)
{
    // Calculate sizes of the two subarrays
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0;    // Initial index of first subarray
    int j = 0;    // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if any
    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[], if any
    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void MergeSortExample::printArray(const std::vector<int> &arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i];
        if (i < arr.size() - 1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}