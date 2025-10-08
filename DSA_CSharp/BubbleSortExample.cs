using System;

namespace DSA
{
    public class BubbleSortExample
    {
        // Bubble Sort = pairs of adjacent elements are compared, and the elements
        //.              swapped if they are not in order.

        // Quadratic time O(n^2)
        // Small data set = okay-ish
        // Large data set = BAD

        public BubbleSortExample()
        {
            int[] array = { 9, 1, 8, 2, 7, 3, 6, 4, 5 };

            Console.WriteLine("Unsorted array: " + string.Join(", ", array));
            BubbleSort(array);
            Console.WriteLine("Sorted array: " + string.Join(", ", array));

        }

        private static void BubbleSort(int[] array)
        {
            // Find the length of the array
            for (int i = 0; i < array.Length - 1; i++)
            {
                // Last i elements are already in place
                for (int j = 0; j < array.Length - i - 1; j++)
                {
                    // For ascending order, use: if (array[j] > array[j + 1])
                    // For descending order, use: if (array[j] < array[j + 1])
                    if (array[j] > array[j + 1])
                    {
                        int temp = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = temp;
                    }
                }
            }
        }
    }
}