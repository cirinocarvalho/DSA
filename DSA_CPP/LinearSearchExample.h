#ifndef LINEARSEARCHEXAMPLE_H
#define LINEARSEARCHEXAMPLE_H
#include <iostream>
#include <vector>

class LinearSearchExample
{
public:
    void demonstrate();

private:
    int linearSearch(const std::vector<int> &arr, int target);
    void linearSearchVerbose(const std::vector<int> &arr, int target);
    std::vector<int> findAllOccurrences(const std::vector<int> &arr, int target);
    void printArray(const std::vector<int> &arr);
};
#endif
