using System;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.CompilerServices;


namespace DSA
{
    class StackExample
    {
        // Stack = LIFO data structure. Last In First Out
        //.        Stores objects into a sort of "vertical tower"
        //.        push() = add item to the top of the stack
        //.        pop() = remove item from the top of the stack
        //.        peek() = return the item at the top of the stack without removing it

        public StackExample()
        {


            Stack<string> stack = new Stack<string>();

            stack.Push("Minecraft");
            stack.Push("Skyrim");
            stack.Push("Roblox");
            stack.Push("DOOM");
            stack.Push("Valorant");

            //stack.Pop();

            //string myFavGame = stack.Pop();
            //Console.WriteLine(stack.Peek());
            Console.WriteLine(string.Join(", ", stack));
            //Console.WriteLine(Search(stack, "Skyrim"));
            //Console.WriteLine($"My favorite game is: {myFavGame}");

            // Uses of stacks 
            // 1. Undo/Redo features in text editors
            // 2. Moving back/forward in web browsers
            // 3. Backtracking algorithms (e.g., maze solving)
            // 4. Calling functions (call stack)
            // 5. Expression evaluation (e.g., postfix notation)
            // 6. Syntax parsing (e.g., compilers)
            // 7. Memory management (e.g., stack memory allocation)
            // 8. Depth-First Search (DFS) in graph algorithms
            // 9. Balancing symbols (e.g., parentheses checking)
            // 10. Reversing data (e.g., reversing a string)
            // 11. Game state management (e.g., saving and loading states)


        }

        // Mimic Java's stack.search()
        static int Search<T>(Stack<T> stack, T item)
        {
            int index = 1; // top = 1
            foreach (var element in stack)
            {
                if (EqualityComparer<T>.Default.Equals(element, item))
                    return index;
                index++;
            }
            return -1;
        }
    }
}

