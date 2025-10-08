using System;

namespace DSA
{
    public class InsertionSortExample
    {
        // Insertion Sort = after comparing elements to the left
        //                  shift elements to the right to make space to insert the element

        // Quadratic time O(n^2)
        // Small data set = decent
        // Large data set = BAD

        // Less steps than bubble sort
        // Best case is O(n) compared to Selection Sort and Bubble Sort O(n^2)

        public InsertionSortExample()
        {
            int[] array = { 9, 1, 8, 2, 7, 3, 6, 4, 5 };

            Console.WriteLine("Unsorted array: " + string.Join(", ", array));
            InsertionSort(array);
            Console.WriteLine("Sorted array: " + string.Join(", ", array));
        }

        private static void InsertionSort(int[] array)
        {
            for (int i = 1; i < array.Length; i++)
            {
                int temp = array[i];
                int j = i - 1;

                while (j >= 0 && array[j] > temp)
                {
                    array[j + 1] = array[j];
                    j--;
                }
                array[j + 1] = temp;
            }
        }
    }
}