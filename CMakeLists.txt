cmake_minimum_required(VERSION 4.0)
project(DSA)

set(CMAKE_CXX_STANDARD 14)

include_directories(DSA_CPP)

add_executable(DSA
        DSA_CPP/AdjacencyListExample.cpp
        DSA_CPP/AdjacencyListExample.h
        DSA_CPP/AdjacencyMatrixExample.cpp
        DSA_CPP/AdjacencyMatrixExample.h
        DSA_CPP/ArrayListExample.cpp
        DSA_CPP/ArrayListExample.h
        DSA_CPP/BinarySearchExample.cpp
        DSA_CPP/BinarySearchExample.h
        DSA_CPP/BinarySearchTreeExample.cpp
        DSA_CPP/BinarySearchTreeExample.h
        DSA_CPP/BreadthFirstSearchExample.cpp
        DSA_CPP/BreadthFirstSearchExample.h
        DSA_CPP/BubbleSortExample.cpp
        DSA_CPP/BubbleSortExample.h
        DSA_CPP/DepthFirstSearchExample.cpp
        DSA_CPP/DepthFirstSearchExample.h
        DSA_CPP/Graph.cpp
        DSA_CPP/Graph.h
        DSA_CPP/HashTablesExample.cpp
        DSA_CPP/HashTablesExample.h
        DSA_CPP/InsertionSortExample.cpp
        DSA_CPP/InsertionSortExample.h
        DSA_CPP/InterpolationSearchExample.cpp
        DSA_CPP/InterpolationSearchExample.h
        DSA_CPP/LinearSearchExample.cpp
        DSA_CPP/LinearSearchExample.h
        DSA_CPP/LinkedListExample.cpp
        DSA_CPP/LinkedListExample.h
        DSA_CPP/main.cpp
        DSA_CPP/MergeSortExample.cpp
        DSA_CPP/MergeSortExample.h
        DSA_CPP/Node.cpp
        DSA_CPP/Node.h
        DSA_CPP/PriorityQueueExample.cpp
        DSA_CPP/PriorityQueueExample.h
        DSA_CPP/QueueExample.cpp
        DSA_CPP/QueueExample.h
        DSA_CPP/QuickSortExample.cpp
        DSA_CPP/QuickSortExample.h
        DSA_CPP/RecursionExample.cpp
        DSA_CPP/RecursionExample.h
        DSA_CPP/SelectionSortExample.cpp
        DSA_CPP/SelectionSortExample.h
        DSA_CPP/StackExample.cpp
        DSA_CPP/StackExample.h
        DSA_CPP/TraverseTreeExample.cpp
        DSA_CPP/TraverseTreeExample.h)
