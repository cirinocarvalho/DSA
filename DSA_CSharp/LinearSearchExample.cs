using System;

namespace DSA
{
    public class LinearSearchExample
    {
        // Linerar Search = Iterate through a colection one element at a time

        //                runtime complexity: O(n)

        //.               Disadvantages:
        //.               Slow for large data sets
        //.               Advantages:
        //.               Fast for search small to medium data sets
        //.               Does not require the data to be sorted
        //.               Useful for data structures that do not allow random access (e.g., linked lists)

        public LinearSearchExample()
        {
            int[] array = { 9, 1, 8, 2, 7, 3, 6, 4, 5 };
            int index = LinearSearch(array, 6);

            if (index != -1)
            {
                Console.WriteLine($"Element found at index: {index}");
            }
            else
            {
                Console.WriteLine("Element not found");
            }

        }
        private static int LinearSearch(int[] array, int value)
        {
            for (int i = 0; i < array.Length; i++)
            {
                if (array[i] == value)
                {
                    return i; // Element found
                }
            }
            return -1; // Element not found
        }
    }

}


