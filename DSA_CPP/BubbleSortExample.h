#ifndef BUBBLESORTEXAMPLE_H
#define BUBBLESORTEXAMPLE_H
#include <iostream>
#include <vector>

class BubbleSortExample
{
public:
    void demonstrate();

private:
    void demonstrateBubbleSort(std::vector<int> arr);
    int bubbleSort(std::vector<int> &arr);
    void swap(std::vector<int> &arr, int i, int j);
    void printArray(const std::vector<int> &arr);
};
#endif
