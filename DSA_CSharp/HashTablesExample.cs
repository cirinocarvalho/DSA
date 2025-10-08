using System;
using System.Collections;

namespace DSA
{
    public class HashTableExample
    {
        // Hashtable = A data structure that stores unique keys to value ex, <Integer, String>
        //.            Each key/value pair is known as an 'Entry'.
        //             Fast insertion, lookups, deletion of key/value pairs
        //             Not ideal for small data sets, great for large data sets

        // Hashing = takes a key and computes and integer (formula will vary based on key and data type)
        //.          In a Hashtable, we use the hash % capacity to calculate an index number

        // key.GetHashCode() % capacity = index

        // Bucket = an indexed storage location for one or more Entries
        // Collision = when two keys hash to the same index
        // Chaining = a way of handling collisions by using a more complex data structure at each bucket
        //            (i.e. LinkedList, Binary Search Tree, etc.)   
        // Load Factor = # of entries / # of buckets

        // Runtime complexity: Best case O(1), Worst case O(n)

        public HashTableExample()
        {
            Dictionary<string, string> table = new Dictionary<string, string>(10);

            table.Add("100", "Spongebob");
            table.Add("123", "Patrick");
            table.Add("321", "Sandy");
            table.Add("555", "Squidward");
            table.Add("777", "Gary");

            //table.Remove(777);

            foreach (string key in table.Keys)
            {
                Console.WriteLine($" {key.GetHashCode() % 10} {key} {table[key]}");
            }

        }

    }
}