#ifndef HASHTABLESEXAMPLE_H
#define HASHTABLESEXAMPLE_H
#include <iostream>
#include <string>

class HashTablesExample
{
public:
    void demonstrate();

private:
    void demonstrateSimpleHashFunction();
    int simpleHashFunction(const std::string &key, int tableSize);
};
#endif