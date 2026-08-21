#ifndef SELECTIONSORTEXAMPLE_H
#define SELECTIONSORTEXAMPLE_H
#include <iostream>
#pragma once
#include <vector>

class SelectionSortExample
{
public:
    static void demonstrate();

private:
    static void selectionSort(std::vector<int> &arr);
    static void selectionSortVerbose(std::vector<int> &arr);
    static void selectionSortWithCounting(std::vector<int> &arr, int &comparisons, int &swaps);
    static void demonstrateStability();
    static void performanceComparison();
    static void printArray(const std::vector<int> &arr);
};
#endif
