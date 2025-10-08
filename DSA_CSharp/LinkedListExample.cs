using System;
using System.Collections.Generic;

namespace DSA
{
    public class LinkedListExample
    {
        // Linked List = linear data structure
        //.               made up of nodes
        //.               each node contains a value and a pointer to the next node
        //.               nodes are not stored in contiguous locations in memory
        //.               dynamic size
        //.               insertion and deletion of nodes is easy
        //.               no index, so you have to traverse the list to find an item

        // Singly Linked List = nodes that contain a value and a pointer to the next node
        // Doubly Linked List = nodes that contain a value and a pointer to the next and
        //                       previous nodes
        // Circular Linked List = nodes that contain a value and a pointer to the next node
        //                         the last node points to the first node


        public LinkedListExample()
        {

            LinkedList<string> linkedList = new LinkedList<string>();

            linkedList.AddFirst("A");
            linkedList.AddLast("C");
            linkedList.AddLast("D");

            Console.WriteLine(string.Join(", ", linkedList));

            //Where are linked lists useful?
            //1. Music player (songs are linked to the next song)
            //2. Web browsers (each page is linked to the next page)
            //3. Image viewer (each image is linked to the next image)
            //4. Implementing stacks and queues
            //5. GPS navigation (each location is linked to the next location)
        }
    }
}