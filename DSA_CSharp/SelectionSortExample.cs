using System;

namespace DSA
{
    public class SelectionSortExample
    {
        // Selection Sort = search through the array and keep track of the minimum value during
        //.                 each iteration. At the end of the iteration, swap the minimum value found with the value
        //.                 at the current position.

        // Quadratic time O(n^2)
        // Small data set = okay-ish
        // Large data set = BAD

        public SelectionSortExample()
        {
            int[] array = { 9, 1, 8, 2, 7, 3, 6, 4, 5 };

            Console.WriteLine("Unsorted array: " + string.Join(", ", array));
            SelectionSort(array);
            Console.WriteLine("Sorted array: " + string.Join(", ", array));

        }

        private static void SelectionSort(int[] array)
        {
            for (int i = 0; i < array.Length - 1; i++)
            {
                // Find the minimum element in unsorted array
                int min = i;

                // Find the minimum element in unsorted array
                for (int j = i + 1; j < array.Length; j++)
                {
                    // For ascending order, use: if (array[min] > array[j])
                    // For descending order, use: if (array[min] < array[j])
                    if (array[min] > array[j])
                    {
                        min = j;
                    }
                }
                // Swap the found minimum element with the first element
                int temp = array[i];
                array[i] = array[min];
                array[min] = temp;
            }
        }
    }
}

