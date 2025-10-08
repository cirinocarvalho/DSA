using System;

namespace DSA
{
    public class QuickSortExample
    {
        // Quick Sort = a divide-and-conquer algorithm that sorts an array by partitioning it into smaller sub-arrays.
        //              It selects a 'pivot' element and partitions the other elements into two groups:
        //              those less than the pivot and those greater than the pivot.
        //              The sub-arrays are then sorted recursively.
        //              Quick Sort is generally faster than other O(n log n) algorithms like Merge Sort and Heap Sort.
        //              It has an average-case time complexity of O(n log n) and a worst-case time complexity of O(n^2).
        //                This process continues moving unsorted array boundary by one element to the right.

        // Quadratic time O(n^2)
        // Small data set = okay-ish
        // Large data set = BAD

        public QuickSortExample()
        {
            int[] array = { 5, 3, 8, 4, 2, 7, 1, 10 };

            Console.WriteLine("Unsorted array: " + string.Join(", ", array));
            QuickSort(array, 0, array.Length - 1);
            Console.WriteLine("Sorted array: " + string.Join(", ", array));
        }

        private static void QuickSort(int[] array, int start, int end)
        {
            if (end <= start) return; // Base case: if the array has one or no elements, it's already sorted
            int pivot = Partition(array, start, end);
            QuickSort(array, start, pivot - 1); // Recursively sort the left sub-array
            QuickSort(array, pivot + 1, end);   // Recursively sort the right sub-array

        }
        private static int Partition(int[] array, int start, int end)
        {
            int pivot = array[end]; // Choose the last element as the pivot
            int i = start - 1;     // Pointer for the smaller element

            for (int j = start; j <= end - 1; j++)
            {
                if (array[j] < pivot) // If the current element is smaller than the pivot
                {
                    i++;
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
            i++;
            int temp1 = array[i];
            array[i] = array[end];
            array[end] = temp1;

            return i;

        }
    }
}

