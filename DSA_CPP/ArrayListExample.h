#ifndef ARRAYLISTEXAMPLE_H
#define ARRAYLISTEXAMPLE_H
#include <iostream>
#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class ArrayList
{
private:
    T *data;
    size_t size;
    size_t capacity;

    void resize()
    {
        capacity *= 2;
        T *newData = new T[capacity];
        for (size_t i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    explicit ArrayList(size_t initialCapacity = 10) : size(0), capacity(initialCapacity)
    {
        data = new T[capacity];
    }

    ~ArrayList()
    {
        delete[] data;
    }

    // Copy constructor
    ArrayList(const ArrayList &other) : size(other.size), capacity(other.capacity)
    {
        data = new T[capacity];
        for (size_t i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }

    // Assignment operator
    ArrayList &operator=(const ArrayList &other)
    {
        if (this != &other)
        {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];
            for (size_t i = 0; i < size; i++)
            {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    void add(const T &element)
    {
        if (size >= capacity)
        {
            resize();
        }
        data[size++] = element;
    }

    T get(size_t index) const
    {
        if (index >= size)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    void set(size_t index, const T &element)
    {
        if (index >= size)
        {
            throw std::out_of_range("Index out of bounds");
        }
        data[index] = element;
    }

    void insert(size_t index, const T &element)
    {
        if (index > size)
        {
            throw std::out_of_range("Index out of bounds");
        }

        if (size >= capacity)
        {
            resize();
        }

        // Shift elements to the right
        for (size_t i = size; i > index; i--)
        {
            data[i] = data[i - 1];
        }

        data[index] = element;
        size++;
    }

    void remove(size_t index)
    {
        if (index >= size)
        {
            throw std::out_of_range("Index out of bounds");
        }

        // Shift elements to the left
        for (size_t i = index; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }
        size--;
    }

    int indexOf(const T &element) const
    {
        for (size_t i = 0; i < size; i++)
        {
            if (data[i] == element)
            {
                return static_cast<int>(i);
            }
        }
        return -1; // Not found
    }

    size_t getSize() const { return size; }
    size_t getCapacity() const { return capacity; }
    bool isEmpty() const { return size == 0; }

    void print() const
    {
        std::cout << "[";
        for (size_t i = 0; i < size; i++)
        {
            std::cout << data[i];
            if (i < size - 1)
                std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
};

class ArrayListExample
{
public:
    static void demonstrate();

private:
    static void printVector(const std::vector<int> &vec)
    {
        std::cout << "[";
        for (size_t i = 0; i < vec.size(); i++)
        {
            std::cout << vec[i];
            if (i < vec.size() - 1)
                std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
};
#endif
