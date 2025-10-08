using System;

namespace DSA
{
    public class MergeSortExample
    {
        // Merge Sort = Divide and Conquer algorithm that splits an array into smaller subarrays,
        //              sorts those subarrays, and then merges them back together
        //              More efficient than simpler algorithms like Bubble Sort, Selection Sort, and Insertion Sort
        //              Runtime complexity: O(n log n) in all cases (best, average, worst)
        //              Advantages:
        //              Consistent O(n log n) performance
        //              Stable sort (preserves the relative order of equal elements)
        //              Well-suited for large data sets and linked lists
        //              Disadvantages:
        //              Requires additional memory for temporary arrays during the merge process
        //              Generally slower for small data sets compared to simpler algorithms
        public MergeSortExample()
        {


            int[] array = { 9, 5, 7, 3, 2, 1, 6, 4, 8 };
            Console.WriteLine("Unsorted Array: " + string.Join(", ", array));

            MergeSort(array);

            Console.WriteLine("Sorted Array: " + string.Join(", ", array));
        }

        private static void MergeSort(int[] array)
        {
            int length = array.Length;
            if (length <= 1) return; //base case 

            int middle = length / 2;
            int[] leftArray = new int[middle];
            int[] rightArray = new int[length - middle];

            int i = 0; //left array
            int j = 0; //right array

            for (; i < length; i++)
            {
                if (i < middle)
                {
                    leftArray[i] = array[i];
                }
                else
                {
                    rightArray[j] = array[i];
                    j++;
                }
            }

            MergeSort(leftArray);
            MergeSort(rightArray);
            Merge(leftArray, rightArray, array);
        }

        private static void Merge(int[] leftArray, int[] rightArray, int[] array)
        {
            int leftSize = array.Length / 2;
            int rightSize = array.Length - leftSize;
            int i = 0, l = 0, r = 0; //indices

            //check the conditions for merging
            while (l < leftSize && r < rightSize)
            {
                if (leftArray[l] < rightArray[r])
                {
                    array[i] = leftArray[l];
                    i++;
                    l++;

                }
                else
                {
                    array[i] = rightArray[r];
                    i++;
                    r++;
                }
            }

            while (l < leftSize)
            {
                array[i] = leftArray[l];
                i++;
                l++;
            }
            while (r < rightSize)
            {
                array[i] = rightArray[r];
                i++;
                r++;
            }

        }
    }
}

