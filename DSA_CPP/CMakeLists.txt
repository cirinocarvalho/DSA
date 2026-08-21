cmake_minimum_required(VERSION 3.10)
project(DSA_CPP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
add_executable(DSA_CPP
    main.cpp
    Node.cpp
    Graph.cpp
    StackExample.cpp
    QueueExample.cpp
    PriorityQueueExample.cpp
    LinkedListExample.cpp
    ArrayListExample.cpp
    LinearSearchExample.cpp
    BinarySearchExample.cpp
    InterpolationSearchExample.cpp
    BubbleSortExample.cpp
    SelectionSortExample.cpp
    InsertionSortExample.cpp
    MergeSortExample.cpp
    QuickSortExample.cpp
    RecursionExample.cpp
    HashTablesExample.cpp
    AdjacencyMatrixExample.cpp
    AdjacencyListExample.cpp
    DepthFirstSearchExample.cpp
    BreadthFirstSearchExample.cpp
    BinarySearchTreeExample.cpp
    TraverseTreeExample.cpp
)

# Include directories
target_include_directories(DSA_CPP PRIVATE .)