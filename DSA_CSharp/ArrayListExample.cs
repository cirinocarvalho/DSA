using System;

namespace DSA
{
    public class ArrayListExample
    {
        // Array List = a dynamic array that can grow as needed
        //.              stores elements in a contiguous block of memory
        //.              allows random access to elements using an index
        //.              can store duplicate elements
        //.              can store elements of different data types
        public ArrayListExample()
        {


            List<string> arrayList = new List<string>();

            arrayList.Add("Hello");
            arrayList.Add("42");
            arrayList.Add("3.14");
            arrayList.Add("true");

            Console.WriteLine(string.Join(", ", arrayList));

            //Where are array lists useful?
            //1. When you need a dynamic array that can grow as needed
            //2. When you need to store elements of different data types
            //3. When you need to allow duplicate elements
        }
    }
}