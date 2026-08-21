#ifndef INSERTIONSORTEXAMPLE_H
#define INSERTIONSORTEXAMPLE_H
#include <iostream>
#pragma once
#include <vector>

class InsertionSortExample
{
public:
    static void demonstrate();

private:
    static void insertionSort(std::vector<int> &arr);
    static void insertionSortVerbose(std::vector<int> &arr);
    static void insertionSortWithCounting(std::vector<int> &arr, int &comparisons, int &shifts);
    static void binaryInsertionSort(std::vector<int> &arr);
    static void binaryInsertionSortVerbose(std::vector<int> &arr);
    static int binarySearch(const std::vector<int> &arr, int left, int right, int key);
    static void demonstrateStability();
    static void onlineInsertionSort(const std::vector<int> &stream);
    static void performanceComparison();
    static void printArray(const std::vector<int> &arr);
};
#endif
