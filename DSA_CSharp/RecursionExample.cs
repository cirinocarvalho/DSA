using System;
using System.Security;

namespace DSA
{
    public class RecursionExample
    {
        // Recursion is a programming technique where a function calls itself directly or indirectly
        // It is used to solve problems that can be broken down into smaller, simpler subproblems
        // Each recursive call works on a smaller instance of the same problem
        // Base case: the condition under which the recursion stops
        // Recursive case: the part of the function that breaks the problem down into smaller subproblems

        //Advantages:
        // Simplifies code for problems that have a recursive structure (e.g., tree traversal,
        // factorial calculation, Fibonacci sequence)
        // Makes code more readable and easier to understand for certain problems
        // Reduces the need for complex loops and state management
        //Disadvantages:
        // Can lead to high memory usage due to function call stack
        // May result in stack overflow errors for deep recursions
        // Generally less efficient than iterative solutions due to overhead of multiple function calls


        public RecursionExample()
        {
            //Walk(5);
            //Console.WriteLine(factorial(7));
            Console.WriteLine(power(2, 8));

        }

        private static int power(int baseNum, int exponentNum)
        {
            if (exponentNum < 1) return 1;
            return baseNum * power(baseNum, exponentNum - 1);
        }

        private static int factorial(int num)
        {
            if (num == 0) return 1;
            return num * factorial(num - 1);

        }

        private static void Walk(int steps)
        {
            if (steps < 1) return;
            Console.WriteLine("You take a step");
            Walk(steps - 1);
        }
    }
}