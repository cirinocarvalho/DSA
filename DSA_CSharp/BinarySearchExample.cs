using System;

namespace DSA
{
    public class BinarySearchExample
    {
        // Binary Search = Search algorithm that finds the position of a target value within a sorted array
        //                 Half of the array is eliminated during each "step"
        //                 More efficient than linear search for large data sets
        //                 runtime complexity: O(log n) 
        //                 Disadvantages:
        //                 Requires the data to be sorted
        //                 Advantages:
        //                 Much faster than linear search for large data sets
        //                 Useful for large data sets where search operations are frequent
        public BinarySearchExample()
        {


            int[] array = new int[10000000];
            int target = 42;

            for (int i = 0; i < array.Length; i++)
            {
                array[i] = i;
            }

            int index = BinarySearch(array, target);

            if (index != -1)
            {
                Console.WriteLine($"Element found at: {index}");
            }
            else
            {
                Console.WriteLine("Element not found");
            }

        }

        private static int BinarySearch(int[] array, int target)
        {
            int low = 0;
            int high = array.Length - 1;

            while (low <= high)
            {
                int middle = low + (high - low) / 2;
                int value = array[middle];

                if (value < target)
                {
                    low = middle + 1;
                }
                else if (value > target)
                {
                    high = middle - 1;
                }
                else
                {
                    return middle; // Target found
                }
            }
            return -1; // Target not found
        }
    }
}