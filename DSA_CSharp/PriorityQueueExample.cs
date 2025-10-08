using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;

namespace DSA
{
    public class PriorityQueueExample
    {
        //Priority Queue = A FICO data structure that serves elements
        //.                with the highest priority first
        //.                before elements with lower priority
        public PriorityQueueExample()
        {
            PriorityQueue<double, double> queue = new PriorityQueue<double, double>();
            queue.Enqueue(3.1, 3.1);
            queue.Enqueue(4.1, 4.1);
            queue.Enqueue(2.1, 2.1);
            queue.Enqueue(5.1, 5.1);
            queue.Enqueue(1.1, 1.1);

            while (queue.Count > 0)
            {
                Console.WriteLine(queue.Dequeue());
            }
        }
    }
}
