#ifndef STACKEXAMPLE_H
#define STACKEXAMPLE_H

#include <iostream>
#include <stack>
#include <vector>

class StackExample
{
public:
    void demonstrate();

private:
    void basicStackOperations();
    void customStackImplementation();
};

// Custom Stack implementation using array
template <typename T>
class CustomStack
{
private:
    std::vector<T> data;
    int topIndex;

public:
    CustomStack() : topIndex(-1) {}

    void push(const T &item)
    {
        data.push_back(item);
        topIndex++;
        std::cout << "Pushed: " << item << std::endl;
    }

    T pop()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Stack is empty!");
        }
        T item = data[topIndex];
        data.pop_back();
        topIndex--;
        std::cout << "Popped: " << item << std::endl;
        return item;
    }

    T top() const
    {
        if (isEmpty())
        {
            throw std::runtime_error("Stack is empty!");
        }
        return data[topIndex];
    }

    bool isEmpty() const
    {
        return topIndex == -1;
    }

    size_t size() const
    {
        return topIndex + 1;
    }

    void display() const
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty" << std::endl;
            return;
        }
        std::cout << "Stack contents (top to bottom): ";
        for (int i = topIndex; i >= 0; i--)
        {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

#endif // STACKEXAMPLE_H