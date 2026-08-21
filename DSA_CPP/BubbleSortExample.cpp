#include "BubbleSortExample.h"
#include <vector>
#include <iostream>

void BubbleSortExample::demonstrate()
{
    std::cout << "\n=== Bubble Sort Example ===\n";
    std::cout << "Bubble Sort: Simple comparison-based sorting algorithm\n";
    std::cout << "Time Complexity: O(n²) average and worst case, O(n) best case\n";
    std::cout << "Space Complexity: O(1) - In-place sorting\n";
    std::cout << "Stable: Yes - Maintains relative order of equal elements\n\n";

    // Test with different arrays
    std::vector<int> arr1 = {64, 34, 25, 12, 22, 11, 90};
    std::cout << "Example 1 - Random array:\n";
    demonstrateBubbleSort(arr1);

    std::vector<int> arr2 = {5, 2, 8, 6, 1, 9, 4};
    std::cout << "\nExample 2 - Another random array:\n";
    demonstrateBubbleSort(arr2);

    std::vector<int> arr3 = {1, 2, 3, 4, 5};
    std::cout << "\nExample 3 - Already sorted (best case):\n";
    demonstrateBubbleSort(arr3);

    std::cout << "\n--- Bubble Sort Properties ---\n";
    std::cout << "✓ Simple to understand and implement\n";
    std::cout << "✓ In-place sorting (O(1) space)\n";
    std::cout << "✓ Stable sorting algorithm\n";
    std::cout << "✓ Can detect if array is already sorted\n";
    std::cout << "✗ Poor time complexity O(n²)\n";
    std::cout << "✗ Not suitable for large datasets\n";
    std::cout << "✗ Many unnecessary comparisons\n";

    std::cout << "\n--- Use Cases ---\n";
    std::cout << "• Educational purposes (learning sorting concepts)\n";
    std::cout << "• Very small datasets (< 10 elements)\n";
    std::cout << "• When simplicity is more important than efficiency\n";
    std::cout << "• Checking if an array is nearly sorted\n";
}

void BubbleSortExample::demonstrateBubbleSort(std::vector<int> arr)
{
    std::cout << "Original array: ";
    printArray(arr);

    int comparisons = bubbleSort(arr);

    std::cout << "Sorted array:   ";
    printArray(arr);
    std::cout << "Total comparisons: " << comparisons << std::endl;
}

int BubbleSortExample::bubbleSort(std::vector<int> &arr)
{
    int n = arr.size();
    int comparisons = 0;
    bool swapped;

    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;

        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; j++)
        {
            comparisons++;

            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1])
            {
                swap(arr, j, j + 1);
                swapped = true;
            }
        }

        // If no swapping occurred, array is sorted
        if (!swapped)
        {
            break;
        }
    }

    return comparisons;
}

void BubbleSortExample::swap(std::vector<int> &arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void BubbleSortExample::printArray(const std::vector<int> &arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i];
        if (i < arr.size() - 1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}