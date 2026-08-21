#ifndef QUICKSORTEXAMPLE_H
#define QUICKSORTEXAMPLE_H
#include <iostream>
#include <vector>

class QuickSortExample
{
public:
    void demonstrate();

private:
    void demonstrateQuickSort(std::vector<int> arr);
    void quickSort(std::vector<int> &arr, int low, int high);
    int partition(std::vector<int> &arr, int low, int high);
    void swap(std::vector<int> &arr, int i, int j);
    void printArray(const std::vector<int> &arr);
};
#endif