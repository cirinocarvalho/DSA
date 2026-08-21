#ifndef RECURSIONEXAMPLE_H
#define RECURSIONEXAMPLE_H
#include <iostream>
#pragma once
#include <vector>
#include <string>

class RecursionExample
{
public:
    static void demonstrate();

private:
    // Mathematical functions
    static long long factorial(int n);
    static long long factorialVerbose(int n, int depth);
    static long long fibonacci(int n);
    static long long fibonacciIterative(int n);
    static long long fibonacciMemoized(int n);
    static long long power(int base, int exponent);
    static long long powerOptimized(int base, int exponent);
    static int sumOfDigits(int n);

    // String operations
    static std::string reverseString(const std::string &str);
    static bool isPalindrome(const std::string &str);
    static bool isPalindromeHelper(const std::string &str, int left, int right);

    // Classic algorithms
    static void towerOfHanoi(int n, char from, char to, char aux);

    // Array operations
    static int arraySum(const std::vector<int> &arr, int index);
    static int arrayMax(const std::vector<int> &arr, int index);
    static bool isArraySorted(const std::vector<int> &arr, int index);
    static int binarySearchRecursive(const std::vector<int> &arr, int left, int right, int target);

    // Utility
    static void printArray(const std::vector<int> &arr);
};
#endif