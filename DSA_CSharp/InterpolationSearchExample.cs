using System;

namespace DSA
{
    public class InterpolationSearchExample
    {
        // Interpolation Search = Improvement over binary seach best used for "uniformly distributed" data
        //                        "guesses" where a value might be based on the calculated probe results
        //                        If probe is incorrect, search area is narrowed, and a new probe is calculated

        //                        average case: O(log log n)
        //                        worst case: O(n) [values increase exponentially]
        //                        Disadvantages:
        //                        Requires the data to be sorted
        //                        Can be inefficient for small data sets or non-uniformly distributed data
        //                        Advantages:
        //                        Can be faster than binary search for large, uniformly distributed data sets   

        //int[] array = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        //int index = InterpolationSearch(array, 8);
        public InterpolationSearchExample()
        {


            int[] array = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024 };
            int index = InterpolationSearch(array, 256);

            if (index != -1)
            {
                Console.WriteLine($"Element found at index: {index}");
            }
            else
            {
                Console.WriteLine("Element not found");
            }
        }

        private static int InterpolationSearch(int[] array, int value)
        {
            int high = array.Length - 1;
            int low = 0;

            while (value >= array[low] && value <= array[high] && low <= high)
            {
                int probe = low + ((value - array[low]) * (high - low)) / (array[high] - array[low]);
                if (array[probe] == value)
                {
                    return probe; // Element found
                }
                if (array[probe] < value)
                {
                    low = probe + 1; // Search in upper part
                }
                else
                {
                    high = probe - 1; // Search in lower part
                }
            }
            return -1; // Element not found

        }
    }
}