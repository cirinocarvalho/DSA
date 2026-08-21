#ifndef BINARYSEARCHEXAMPLE_H
#define BINARYSEARCHEXAMPLE_H

#include <iostream>
#include <vector>
#include <algorithm>

class BinarySearchExample
{
public:
    void demonstrate();

private:
    int binarySearch(const std::vector<int> &arr, int target);
    int binarySearchRecursive(const std::vector<int> &arr, int target, int left, int right);
    void printArray(const std::vector<int> &arr, const std::string &message);
};

#endif // BINARYSEARCHEXAMPLE_H
