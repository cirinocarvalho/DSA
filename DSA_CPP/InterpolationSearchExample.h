#ifndef INTERPOLATIONSEARCHEXAMPLE_H
#define INTERPOLATIONSEARCHEXAMPLE_H
#include <iostream>
#pragma once
#include <vector>

class InterpolationSearchExample
{
public:
    static void demonstrate();

private:
    static int interpolationSearch(const std::vector<int> &arr, int target);
    static int binarySearch(const std::vector<int> &arr, int target);
    static void interpolationSearchVerbose(const std::vector<int> &arr, int target);
    static void printArray(const std::vector<int> &arr);
};
#endif
