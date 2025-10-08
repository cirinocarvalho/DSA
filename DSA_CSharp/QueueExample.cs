using System;
using System.Collections.Generic;


namespace DSA
{
    public class QueueExample
    {
        // Queue = FIFO data structure. First In First Out (ex. A line of people)
        //.        A collection designed for holding elements prior to processing
        //.        Linear data structure
        //.        enqueue() = add item to the back of the queue
        //.        dequeue() = remove item from the front of the queue
        //.        peek() = return the item at the front of the queue without removing it
        public QueueExample()
        {

            Queue<string> queue = new Queue<string>();

            queue.Enqueue("Alice");
            queue.Enqueue("Bob");
            queue.Enqueue("Charlie");
            queue.Enqueue("Diana");

            Console.WriteLine(string.Join(", ", queue));

            string servedCustomer = queue.Dequeue();
            Console.WriteLine($"Served customer: {servedCustomer}");
            Console.WriteLine(string.Join(", ", queue));

            Console.WriteLine($"Next customer: {queue.Peek()}");
            Console.WriteLine(string.Join(", ", queue));

            //Where are queues useful?

            //1. Keyboard buffer (letters you type are stored in a queue until they are processed)
            //2. Printer queue (documents sent to the printer are stored in a queue until the printer is ready)
            //3. Call center systems (calls are queued until an agent is available
        }
    }
}