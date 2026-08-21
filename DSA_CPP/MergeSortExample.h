#ifndef MERGESORTEXAMPLE_H
#define MERGESORTEXAMPLE_H
#include <iostream>
#include <vector>

class MergeSortExample
{
public:
    void demonstrate();

private:
    void demonstrateMergeSort(std::vector<int> arr);
    void mergeSort(std::vector<int> &arr, int left, int right);
    void merge(std::vector<int> &arr, int left, int mid, int right);
    void printArray(const std::vector<int> &arr);
};
#endif