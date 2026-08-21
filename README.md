# Data Structures and Algorithms (DSA) in C# and C++

[![.NET](https://img.shields.io/badge/.NET-10.0-512BD4?logo=dotnet&logoColor=white)](https://dotnet.microsoft.com/)
[![C#](https://img.shields.io/badge/C%23-14-239120?logo=csharp&logoColor=white)](https://learn.microsoft.com/dotnet/csharp/)
[![C++](https://img.shields.io/badge/C%2B%2B-17-00599C?logo=cplusplus&logoColor=white)](https://en.cppreference.com/w/cpp/17)
[![CMake](https://img.shields.io/badge/CMake-3.10%2B-064F8C?logo=cmake&logoColor=white)](https://cmake.org/)
[![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20macOS%20%7C%20Linux-lightgrey)](#-getting-started)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Examples](https://img.shields.io/badge/examples-21%20per%20language-brightgreen)](#-implemented-data-structures)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen)](#-contributing)
[![Last Commit](https://img.shields.io/github/last-commit/cirinocarvalho/DSA)](https://github.com/cirinocarvalho/DSA/commits)

A comprehensive collection of data structures and algorithms implemented **twice** — once in C# and once in C++ — so the same concept can be compared side by side across two very different languages. All 21 examples exist in both projects.

## 📁 Project Structure

```
DSA/
├── DSA.sln                     # Visual Studio / Rider solution (C#)
├── CMakeLists.txt              # Top-level CMake target "DSA" (builds the C++ sources)
├── README.md                   # This file
├── DSA_CSharp/                 # C# project
│   ├── Program.cs              # Entry point with example selection
│   ├── CSharp.csproj           # net10.0, LangVersion 14, nullable enabled
│   ├── Node.cs / Graph.cs      # Shared building blocks
│   └── *Example.cs             # One file per algorithm / data structure
└── DSA_CPP/                    # C++ project
    ├── main.cpp                # Entry point with example selection
    ├── CMakeLists.txt          # CMake build (C++17), target "DSA_CPP"
    ├── Makefile                # Alternative build (g++, -Wall -Wextra -g)
    ├── Node.h/.cpp             # Generic node implementation
    ├── Graph.h/.cpp            # Graph data structure
    └── *Example.h/.cpp         # One header/source pair per example
```

> There are two CMake entry points: the **root** `CMakeLists.txt` builds a target named `DSA` from the `DSA_CPP/` sources, while `DSA_CPP/CMakeLists.txt` builds a target named `DSA_CPP` from within that directory. Either one works — use whichever matches your IDE setup.

## 🚀 Getting Started

### Prerequisites

**For the C# project:**
- .NET SDK 10.0 or later
- Visual Studio, VS Code, or JetBrains Rider

**For the C++ project:**
- A C++17 compatible compiler (GCC, Clang, or MSVC)
- CMake 3.10+ (optional — only for the CMake build; the root `CMakeLists.txt` asks for CMake 4.0+)
- Make (optional, for the Makefile build)

### Running the C# Project

```bash
git clone https://github.com/cirinocarvalho/DSA.git
cd DSA
dotnet run --project DSA_CSharp/CSharp.csproj
```

Or open `DSA.sln` in your IDE and press Run. To pick a different example, edit `DSA_CSharp/Program.cs` and uncomment the line you want (see [Usage Example](#-usage-example)).

### Running the C++ Project

**Option 1: Using Make**
```bash
cd DSA_CPP
make          # Build the project
make run      # Build and run
make clean    # Remove build artifacts
make help     # List available targets
```

**Option 2: Using CMake (from DSA_CPP/)**
```bash
cd DSA_CPP
mkdir -p build && cd build
cmake ..
make
./DSA_CPP
```

**Option 3: Using CMake (from the repository root)**
```bash
cmake -S . -B build
cmake --build build
./build/DSA
```

**Option 4: Direct compilation**
```bash
cd DSA_CPP
g++ -std=c++17 -o dsa_cpp *.cpp
./dsa_cpp
```

**To run different examples:** edit `main.cpp` and uncomment the demo calls you want.

## 📚 Implemented Data Structures

### Linear Data Structures

| Structure | C# | C++ | Description |
|---|---|---|---|
| Stack | `StackExample.cs` | `StackExample.h/.cpp` | LIFO (Last In, First Out) |
| Queue | `QueueExample.cs` | `QueueExample.h/.cpp` | FIFO (First In, First Out) |
| Priority Queue | `PriorityQueueExample.cs` | `PriorityQueueExample.h/.cpp` | Queue with priority-based ordering |
| Linked List | `LinkedListExample.cs` | `LinkedListExample.h/.cpp` | Dynamic linear structure of linked nodes |
| Array List | `ArrayListExample.cs` | `ArrayListExample.h/.cpp` | Dynamic (resizable) array |

### Non-Linear Data Structures

| Structure | C# | C++ | Description |
|---|---|---|---|
| Binary Search Tree | `BinarySearchTreeExample.cs` | `BinarySearchTreeExample.h/.cpp` | Ordered binary tree with insert/search/delete |
| Graph | `Graph.cs` | `Graph.h/.cpp` | Graph type shared by the traversal examples |
| — Adjacency Matrix | `AdjacencyMatrixExample.cs` | `AdjacencyMatrixExample.h/.cpp` | Matrix-based graph representation |
| — Adjacency List | `AdjacenyListExample.cs` | `AdjacencyListExample.h/.cpp` | List-based graph representation |
| Hash Table | `HashTablesExample.cs` | `HashTablesExample.h/.cpp` | Key-value storage with hashing |
| Node | `Node.cs` | `Node.h/.cpp` | Generic node used by lists, trees, and graphs |

## 🔍 Implemented Algorithms

### Search Algorithms

| Algorithm | C# | C++ | Description |
|---|---|---|---|
| Linear Search | `LinearSearchExample.cs` | `LinearSearchExample.h/.cpp` | Sequential scan through elements |
| Binary Search | `BinarySearchExample.cs` | `BinarySearchExample.h/.cpp` | Halving search over a sorted array |
| Interpolation Search | `InterpolationSearchExample.cs` | `InterpolationSearchExample.h/.cpp` | Position-estimating search for uniform data |

### Sorting Algorithms

| Algorithm | C# | C++ | Description |
|---|---|---|---|
| Bubble Sort | `BubbleSortExample.cs` | `BubbleSortExample.h/.cpp` | Simple adjacent-swap sorting |
| Selection Sort | `SelectionSortExample.cs` | `SelectionSortExample.h/.cpp` | In-place minimum-selection sorting |
| Insertion Sort | `InsertionSortExample.cs` | `InsertionSortExample.h/.cpp` | Efficient for small or nearly sorted data |
| Merge Sort | `MergeSortExample.cs` | `MergeSortExample.h/.cpp` | Stable divide-and-conquer sorting |
| Quick Sort | `QuickSortExample.cs` | `QuickSortExample.h/.cpp` | In-place partition-based sorting |

### Graph & Tree Algorithms

| Algorithm | C# | C++ | Description |
|---|---|---|---|
| Depth-First Search | `DepthFirstSearchExample.cs` | `DepthFirstSearchExample.h/.cpp` | Traversal using a stack / recursion |
| Breadth-First Search | `BreadthFirstSearchExample.cs` | `BreadthFirstSearchExample.h/.cpp` | Traversal using a queue |
| Tree Traversal | `TraverseTreeExample.cs` | `TraverseTreeExample.h/.cpp` | In-order, pre-order, and post-order |

### Other

| Topic | C# | C++ | Description |
|---|---|---|---|
| Recursion | `RecursionExample.cs` | `RecursionExample.h/.cpp` | Recursive problem-solving examples |

## 💻 Usage Example

Both entry points keep every example in a commented block, so you can enable exactly the one you want to study.

**C# — `DSA_CSharp/Program.cs`:**

```csharp
static void Main()
{
    // Uncomment the example you want to run
    // new StackExample();
    // new BinarySearchExample();
    // new MergeSortExample();
    new TraverseTreeExample();
}
```

**C++ — `DSA_CPP/main.cpp`:** each example is a class with a `demonstrate()` method.

```cpp
int main()
{
    StackExample stackDemo;
    stackDemo.demonstrate();

    // MergeSortExample mergeSortDemo;
    // mergeSortDemo.demonstrate();

    return 0;
}
```

Then rebuild and run.

## 📈 Complexity Reference

Quick reference for the algorithms in this repository (n = number of elements):

| Algorithm | Best | Average | Worst | Space | Stable |
|---|---|---|---|---|---|
| Linear Search | O(1) | O(n) | O(n) | O(1) | — |
| Binary Search | O(1) | O(log n) | O(log n) | O(1) | — |
| Interpolation Search | O(1) | O(log log n) | O(n) | O(1) | — |
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) | ✅ |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) | ❌ |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) | ✅ |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | ✅ |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) | ❌ |
| BST search / insert | O(log n) | O(log n) | O(n) | O(n) | — |
| Hash Table lookup | O(1) | O(1) | O(n) | O(n) | — |
| DFS / BFS | O(V + E) | O(V + E) | O(V + E) | O(V) | — |

Binary and interpolation search both require a **sorted** input; interpolation search additionally assumes roughly uniform distribution.

## 🎯 Learning Objectives

This project helps understand:

- **Time and space complexity** — Big O analysis in practice
- **Data structure selection** — when to reach for which structure
- **Algorithm efficiency** — comparing approaches to the same problem
- **Implementation details** — how these concepts work under the hood
- **Cross-language thinking** — the same idea expressed in a managed and an unmanaged language

## 🔀 Language Comparison

### C# implementation
- Object-oriented, one class per example, instantiated from `Program.cs`
- Automatic memory management via garbage collection
- Nullable reference types and `LangVersion 14` features enabled
- Rich BCL and LINQ available for comparison against hand-rolled versions

### C++ implementation
- Header/source separation, one `demonstrate()` method per example class
- Manual memory management with explicit ownership
- Templates for generic programming and STL containers for comparison
- Compiled with `-std=c++17 -Wall -Wextra`

### Key differences to observe
- **Memory management** — garbage collection vs. explicit `new`/`delete` and RAII
- **Performance** — C++ gives lower-level control; C# trades some of it for safety
- **Generics** — C# generics are runtime-reified; C++ templates are compile-time expanded
- **Error handling** — exception idioms differ between the two ecosystems

## 📝 Notes

- All implementations prioritize clarity and educational value over production optimization
- Each example is self-contained and can be run independently
- The code includes comments explaining the logic and complexity
- Comparing the same algorithm in both languages is the point — read them side by side
- Note the historical filename typo `AdjacenyListExample.cs` on the C# side (the C++ counterpart is spelled `AdjacencyListExample`)

## 🤝 Contributing

Contributions are welcome:

- Add new algorithms or data structures (ideally in **both** languages, to preserve parity)
- Improve existing implementations
- Add more detailed comments or documentation
- Fix bugs or optimize code

Please keep the naming convention (`<Topic>Example`) and the "uncomment to run" entry-point pattern so new examples fit alongside the existing ones.

## 📄 License

This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.

## 🔗 Useful Resources

- [Big O Cheat Sheet](https://www.bigocheatsheet.com/)
- [Data Structures Visualization](https://visualgo.net/)
- [Algorithm Complexity Reference](https://en.wikipedia.org/wiki/Time_complexity)
- [C# Documentation](https://learn.microsoft.com/dotnet/csharp/)
- [C++ Reference](https://cppreference.com/)

---

**Happy Learning!** 🎓
