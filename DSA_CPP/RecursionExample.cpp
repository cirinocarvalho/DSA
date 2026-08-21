#include "RecursionExample.h"
#include <iostream>
#include <vector>
#include <string>
#include <chrono>

void RecursionExample::demonstrate()
{
    std::cout << "\n=== Recursion Example ===\n";
    std::cout << "Recursive algorithms that call themselves to solve problems\n";
    std::cout << "Key concepts: Base case, recursive case, stack space\n";
    std::cout << "Common patterns: Divide and conquer, backtracking, tree traversal\n\n";

    // Factorial examples
    std::cout << "--- Factorial Examples ---\n";
    std::cout << "Factorial(n) = n! = n × (n-1) × (n-2) × ... × 1\n";

    for (int i = 0; i <= 10; i++)
    {
        std::cout << i << "! = " << factorial(i) << std::endl;
    }

    std::cout << "\nFactorial with step tracking for n=5:\n";
    factorialVerbose(5, 1);

    // Fibonacci examples
    std::cout << "\n--- Fibonacci Examples ---\n";
    std::cout << "Fibonacci(n) = Fibonacci(n-1) + Fibonacci(n-2)\n";
    std::cout << "Base cases: F(0) = 0, F(1) = 1\n\n";

    std::cout << "First 15 Fibonacci numbers:\n";
    for (int i = 0; i < 15; i++)
    {
        std::cout << "F(" << i << ") = " << fibonacci(i) << std::endl;
    }

    // Performance comparison: recursive vs iterative
    std::cout << "\n--- Performance Comparison: Fibonacci ---\n";
    int n = 35;

    // Recursive (inefficient)
    auto start = std::chrono::high_resolution_clock::now();
    long long recResult = fibonacci(n);
    auto end = std::chrono::high_resolution_clock::now();
    auto recTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // Iterative
    start = std::chrono::high_resolution_clock::now();
    long long iterResult = fibonacciIterative(n);
    end = std::chrono::high_resolution_clock::now();
    auto iterTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // Memoized
    start = std::chrono::high_resolution_clock::now();
    long long memoResult = fibonacciMemoized(n);
    end = std::chrono::high_resolution_clock::now();
    auto memoTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Computing F(" << n << "):\n";
    std::cout << "Recursive: " << recResult << " (Time: " << recTime.count() << " ms)\n";
    std::cout << "Iterative: " << iterResult << " (Time: " << iterTime.count() << " ms)\n";
    std::cout << "Memoized:  " << memoResult << " (Time: " << memoTime.count() << " ms)\n";

    // Power calculation
    std::cout << "\n--- Power Calculation ---\n";
    std::cout << "power(base, exponent) = base^exponent\n";

    int base = 2;
    for (int exp = 0; exp <= 10; exp++)
    {
        std::cout << base << "^" << exp << " = " << power(base, exp) << std::endl;
    }

    std::cout << "\nOptimized power calculation (fast exponentiation):\n";
    std::cout << "2^20 = " << powerOptimized(2, 20) << std::endl;
    std::cout << "3^15 = " << powerOptimized(3, 15) << std::endl;

    // Sum of digits
    std::cout << "\n--- Sum of Digits ---\n";
    std::vector<int> numbers = {123, 456, 789, 1000, 9876};

    for (int num : numbers)
    {
        std::cout << "Sum of digits of " << num << " = " << sumOfDigits(num) << std::endl;
    }

    // Reverse string
    std::cout << "\n--- String Reversal ---\n";
    std::vector<std::string> strings = {"hello", "world", "recursion", "algorithm"};

    for (const std::string &str : strings)
    {
        std::cout << "\"" << str << "\" reversed = \"" << reverseString(str) << "\"" << std::endl;
    }

    // Palindrome check
    std::cout << "\n--- Palindrome Check ---\n";
    std::vector<std::string> palindromes = {"racecar", "hello", "madam", "level", "world", "noon"};

    for (const std::string &str : palindromes)
    {
        std::cout << "\"" << str << "\" is " << (isPalindrome(str) ? "" : "not ") << "a palindrome" << std::endl;
    }

    // Tower of Hanoi
    std::cout << "\n--- Tower of Hanoi ---\n";
    std::cout << "Moving 3 disks from rod A to rod C using rod B:\n";
    towerOfHanoi(3, 'A', 'C', 'B');

    std::cout << "\nNumber of moves required for different disk counts:\n";
    for (int disks = 1; disks <= 10; disks++)
    {
        int moves = (1 << disks) - 1; // 2^n - 1
        std::cout << disks << " disks: " << moves << " moves" << std::endl;
    }

    // Array operations
    std::cout << "\n--- Array Operations ---\n";
    std::vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Array: ";
    printArray(array);
    std::cout << "Sum of array: " << arraySum(array, 0) << std::endl;
    std::cout << "Maximum element: " << arrayMax(array, 0) << std::endl;
    std::cout << "Is array sorted: " << (isArraySorted(array, 0) ? "Yes" : "No") << std::endl;

    std::vector<int> unsortedArray = {3, 1, 4, 1, 5, 9, 2, 6};
    std::cout << "\nUnsorted array: ";
    printArray(unsortedArray);
    std::cout << "Is array sorted: " << (isArraySorted(unsortedArray, 0) ? "Yes" : "No") << std::endl;

    // Binary search (recursive)
    std::cout << "\n--- Binary Search (Recursive) ---\n";
    std::vector<int> sortedArray = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    std::cout << "Sorted array: ";
    printArray(sortedArray);

    std::vector<int> searchValues = {7, 12, 1, 19, 20};
    for (int value : searchValues)
    {
        int index = binarySearchRecursive(sortedArray, 0, sortedArray.size() - 1, value);
        std::cout << "Search for " << value << ": ";
        if (index != -1)
        {
            std::cout << "Found at index " << index << std::endl;
        }
        else
        {
            std::cout << "Not found" << std::endl;
        }
    }

    std::cout << "\n--- Recursion Types ---\n";
    std::cout << "1. Linear Recursion: Makes one recursive call (factorial, sum)\n";
    std::cout << "2. Binary Recursion: Makes two recursive calls (fibonacci, binary tree)\n";
    std::cout << "3. Tail Recursion: Recursive call is the last operation\n";
    std::cout << "4. Multiple Recursion: Makes multiple recursive calls (Tower of Hanoi)\n";

    std::cout << "\n--- Advantages and Disadvantages ---\n";
    std::cout << "Advantages:\n";
    std::cout << "✓ Clean, elegant code for recursive problems\n";
    std::cout << "✓ Natural for tree/graph traversals\n";
    std::cout << "✓ Divide and conquer algorithms\n";
    std::cout << "✓ Mathematical elegance\n";

    std::cout << "\nDisadvantages:\n";
    std::cout << "✗ Stack overflow for deep recursion\n";
    std::cout << "✗ Function call overhead\n";
    std::cout << "✗ Repeated calculations (naive implementations)\n";
    std::cout << "✗ Memory usage (call stack)\n";

    std::cout << "\n--- Use Cases ---\n";
    std::cout << "• Tree and graph traversals\n";
    std::cout << "• Divide and conquer algorithms\n";
    std::cout << "• Mathematical computations\n";
    std::cout << "• Backtracking algorithms\n";
    std::cout << "• Parsing nested structures\n";
}

long long RecursionExample::factorial(int n)
{
    // Base case
    if (n <= 1)
    {
        return 1;
    }
    // Recursive case
    return n * factorial(n - 1);
}

long long RecursionExample::factorialVerbose(int n, int depth)
{
    std::string indent(depth * 2, ' ');
    std::cout << indent << "factorial(" << n << ") called" << std::endl;

    if (n <= 1)
    {
        std::cout << indent << "Base case reached: returning 1" << std::endl;
        return 1;
    }

    std::cout << indent << "Calculating " << n << " * factorial(" << (n - 1) << ")" << std::endl;
    long long result = n * factorialVerbose(n - 1, depth + 1);
    std::cout << indent << "factorial(" << n << ") = " << result << std::endl;

    return result;
}

long long RecursionExample::fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

long long RecursionExample::fibonacciIterative(int n)
{
    if (n <= 1)
        return n;

    long long prev = 0, curr = 1;
    for (int i = 2; i <= n; i++)
    {
        long long temp = curr;
        curr = prev + curr;
        prev = temp;
    }
    return curr;
}

long long RecursionExample::fibonacciMemoized(int n)
{
    static std::vector<long long> memo(50, -1);

    if (n <= 1)
        return n;
    if (memo[n] != -1)
        return memo[n];

    memo[n] = fibonacciMemoized(n - 1) + fibonacciMemoized(n - 2);
    return memo[n];
}

long long RecursionExample::power(int base, int exponent)
{
    if (exponent == 0)
    {
        return 1;
    }
    return base * power(base, exponent - 1);
}

long long RecursionExample::powerOptimized(int base, int exponent)
{
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return base;

    if (exponent % 2 == 0)
    {
        long long half = powerOptimized(base, exponent / 2);
        return half * half;
    }
    else
    {
        return base * powerOptimized(base, exponent - 1);
    }
}

int RecursionExample::sumOfDigits(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return (n % 10) + sumOfDigits(n / 10);
}

std::string RecursionExample::reverseString(const std::string &str)
{
    if (str.length() <= 1)
    {
        return str;
    }
    return reverseString(str.substr(1)) + str[0];
}

bool RecursionExample::isPalindrome(const std::string &str)
{
    return isPalindromeHelper(str, 0, str.length() - 1);
}

bool RecursionExample::isPalindromeHelper(const std::string &str, int left, int right)
{
    if (left >= right)
    {
        return true;
    }
    if (str[left] != str[right])
    {
        return false;
    }
    return isPalindromeHelper(str, left + 1, right - 1);
}

void RecursionExample::towerOfHanoi(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        std::cout << "Move disk 1 from " << from << " to " << to << std::endl;
        return;
    }

    towerOfHanoi(n - 1, from, aux, to);
    std::cout << "Move disk " << n << " from " << from << " to " << to << std::endl;
    towerOfHanoi(n - 1, aux, to, from);
}

int RecursionExample::arraySum(const std::vector<int> &arr, int index)
{
    if (index >= arr.size())
    {
        return 0;
    }
    return arr[index] + arraySum(arr, index + 1);
}

int RecursionExample::arrayMax(const std::vector<int> &arr, int index)
{
    if (index == arr.size() - 1)
    {
        return arr[index];
    }
    int maxRest = arrayMax(arr, index + 1);
    return std::max(arr[index], maxRest);
}

bool RecursionExample::isArraySorted(const std::vector<int> &arr, int index)
{
    if (index >= arr.size() - 1)
    {
        return true;
    }
    if (arr[index] > arr[index + 1])
    {
        return false;
    }
    return isArraySorted(arr, index + 1);
}

int RecursionExample::binarySearchRecursive(const std::vector<int> &arr, int left, int right, int target)
{
    if (left > right)
    {
        return -1; // Not found
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] > target)
    {
        return binarySearchRecursive(arr, left, mid - 1, target);
    }
    else
    {
        return binarySearchRecursive(arr, mid + 1, right, target);
    }
}

void RecursionExample::printArray(const std::vector<int> &arr)
{
    std::cout << "[";
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i];
        if (i < arr.size() - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}