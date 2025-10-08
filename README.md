# Data Structures and Algorithms (DSA) in C#

A comprehensive collection of data structures and algorithms implementations in C#. This project serves as a learning resource and reference for common computer science concepts.

## 📁 Project Structure

```
DSA/
├── DSA.sln                    # Solution file
├── README.md                  # This file
└── DSA_CSharp/               # Main C# project
    ├── Program.cs            # Entry point with example selection
    ├── CSharp.csproj         # Project file
    └── [Implementation Files] # Individual algorithm/data structure files
```

## 🚀 Getting Started

### Prerequisites

- .NET 9.0 or later
- Visual Studio, VS Code, or JetBrains Rider

### Running the Project

1. Clone or download this repository
2. Open the solution file `DSA.sln` in your IDE
3. Build and run the project
4. Uncomment the desired example in `Program.cs` to see it in action

## 📚 Implemented Data Structures

### Linear Data Structures

- **Stack** (`StackExample.cs`) - LIFO (Last In, First Out) data structure
- **Queue** (`QueueExample.cs`) - FIFO (First In, First Out) data structure
- **Priority Queue** (`PriorityQueueExample.cs`) - Queue with priority-based ordering
- **Linked List** (`LinkedListExample.cs`) - Dynamic linear data structure
- **Array List** (`ArrayListExample.cs`) - Dynamic array implementation

### Non-Linear Data Structures

- **Binary Search Tree** (`BinarySearchTreeExample.cs`) - Self-balancing binary tree
- **Graph** (`Graph.cs`) - Graph data structure with adjacency representations
  - **Adjacency Matrix** (`AdjacencyMatrixExample.cs`) - Matrix-based graph representation
  - **Adjacency List** (`AdjacenyListExample.cs`) - List-based graph representation
- **Hash Tables** (`HashTablesExample.cs`) - Key-value pair storage with hashing

## 🔍 Implemented Algorithms

### Search Algorithms

- **Linear Search** (`LinearSearchExample.cs`) - Sequential search through elements
- **Binary Search** (`BinarySearchExample.cs`) - Efficient search in sorted arrays
- **Interpolation Search** (`InterpolationSearchExample.cs`) - Improved binary search for uniformly distributed data

### Sorting Algorithms

- **Bubble Sort** (`BubbleSortExample.cs`) - Simple comparison-based sorting
- **Selection Sort** (`SelectionSortExample.cs`) - In-place comparison sorting
- **Insertion Sort** (`InsertionSortExample.cs`) - Efficient for small datasets
- **Merge Sort** (`MergeSortExample.cs`) - Divide-and-conquer stable sorting
- **Quick Sort** (`QuickSortExample.cs`) - Efficient divide-and-conquer sorting

### Graph Algorithms

- **Depth-First Search (DFS)** (`DepthFirstSearchExample.cs`) - Graph traversal using stack
- **Breadth-First Search (BFS)** (`BreadthFirstSearchExample.cs`) - Graph traversal using queue

### Tree Algorithms

- **Tree Traversal** (`TraverseTreeExample.cs`) - In-order, pre-order, and post-order traversals

### Other Algorithms

- **Recursion** (`RecursionExample.cs`) - Recursive algorithm examples

## 💻 Usage Example

To run a specific algorithm or data structure example:

1. Open `Program.cs`
2. Uncomment the desired example line in the `Main` method:

```csharp
static void Main()
{
    // Uncomment the example you want to run
    new StackExample();           // Stack operations
    new BinarySearchExample();    // Binary search demonstration
    new MergeSortExample();       // Merge sort algorithm
    // ... other examples
}
```

3. Build and run the project

## 🎯 Learning Objectives

This project helps understand:

- **Time and Space Complexity** - Big O notation analysis
- **Data Structure Selection** - When to use which data structure
- **Algorithm Efficiency** - Comparing different algorithmic approaches
- **Implementation Details** - How these concepts work under the hood

## 📈 Complexity Analysis

Each implementation includes comments about:

- **Time Complexity** - How runtime scales with input size
- **Space Complexity** - Memory usage characteristics
- **Best/Average/Worst Case** scenarios where applicable

## 🤝 Contributing

Feel free to contribute by:

- Adding new algorithms or data structures
- Improving existing implementations
- Adding more detailed comments or documentation
- Fixing bugs or optimizing code

## 📝 Notes

- All implementations prioritize clarity and educational value over production optimization
- Each example is self-contained and can be run independently
- The code includes extensive comments explaining the logic and complexity

## 🔗 Useful Resources

- [Big O Cheat Sheet](https://www.bigocheatsheet.com/)
- [Data Structures Visualization](https://visualgo.net/)
- [Algorithm Complexity Reference](https://en.wikipedia.org/wiki/Time_complexity)

---

**Happy Learning!** 🎓
