#include "ArrayListExample.h"
#include <iostream>
#include <vector>
#include <memory>

void ArrayListExample::demonstrate()
{
    std::cout << "\n=== ArrayList Example ===\n";
    std::cout << "Dynamic array implementation with automatic resizing\n";
    std::cout << "Average Time Complexity: Access O(1), Search O(n), Insert O(1) amortized, Delete O(n)\n";
    std::cout << "Space Complexity: O(n)\n\n";

    // Demonstrate built-in std::vector (C++ equivalent of ArrayList)
    std::cout << "--- Using std::vector (C++ equivalent of ArrayList) ---\n";
    std::vector<int> arrayList;

    std::cout << "Initial capacity: " << arrayList.capacity() << ", size: " << arrayList.size() << std::endl;

    // Adding elements
    std::cout << "\nAdding elements 1-10:\n";
    for (int i = 1; i <= 10; i++)
    {
        arrayList.push_back(i);
        std::cout << "Added " << i << " - Size: " << arrayList.size() << ", Capacity: " << arrayList.capacity() << std::endl;
    }

    std::cout << "\nCurrent array: ";
    printVector(arrayList);

    // Accessing elements
    std::cout << "\n--- Random Access ---\n";
    std::cout << "Element at index 0: " << arrayList[0] << std::endl;
    std::cout << "Element at index 5: " << arrayList[5] << std::endl;
    std::cout << "Element at index 9: " << arrayList[9] << std::endl;

    // Searching elements
    std::cout << "\n--- Search Operations ---\n";
    int searchValue = 7;
    auto it = std::find(arrayList.begin(), arrayList.end(), searchValue);
    if (it != arrayList.end())
    {
        std::cout << "Found " << searchValue << " at index " << (it - arrayList.begin()) << std::endl;
    }

    // Inserting at specific position
    std::cout << "\n--- Insert at Position ---\n";
    arrayList.insert(arrayList.begin() + 5, 99);
    std::cout << "Inserted 99 at index 5: ";
    printVector(arrayList);

    // Removing elements
    std::cout << "\n--- Remove Operations ---\n";
    arrayList.erase(arrayList.begin() + 5);
    std::cout << "Removed element at index 5: ";
    printVector(arrayList);

    arrayList.pop_back();
    std::cout << "Removed last element: ";
    printVector(arrayList);

    // Demonstrate custom ArrayList implementation
    std::cout << "\n--- Custom ArrayList Implementation ---\n";
    ArrayList<int> customList(4); // Initial capacity 4

    std::cout << "Custom ArrayList created with initial capacity 4\n";

    // Add elements to trigger resizing
    for (int i = 1; i <= 8; i++)
    {
        customList.add(i * 10);
        std::cout << "Added " << (i * 10) << " - Size: " << customList.getSize() << ", Capacity: " << customList.getCapacity() << std::endl;
    }

    std::cout << "\nCustom ArrayList contents: ";
    customList.print();

    // Access elements
    std::cout << "\n--- Custom ArrayList Operations ---\n";
    std::cout << "Element at index 3: " << customList.get(3) << std::endl;

    // Set element
    customList.set(3, 999);
    std::cout << "Set element at index 3 to 999: ";
    customList.print();

    // Insert at position
    customList.insert(2, 555);
    std::cout << "Inserted 555 at index 2: ";
    customList.print();

    // Remove element
    customList.remove(4);
    std::cout << "Removed element at index 4: ";
    customList.print();

    // Search element
    int index = customList.indexOf(555);
    std::cout << "Index of 555: " << index << std::endl;

    std::cout << "\n--- ArrayList vs Array Comparison ---\n";
    std::cout << "Fixed Array:\n";
    std::cout << "✓ Faster access (no overhead)\n";
    std::cout << "✓ Memory efficient\n";
    std::cout << "✗ Fixed size\n";
    std::cout << "✗ Manual memory management\n";

    std::cout << "\nDynamic ArrayList:\n";
    std::cout << "✓ Dynamic sizing\n";
    std::cout << "✓ Automatic memory management\n";
    std::cout << "✓ Rich API (insert, remove, search)\n";
    std::cout << "✗ Slight overhead\n";
    std::cout << "✗ May waste memory (capacity > size)\n";

    std::cout << "\n--- Use Cases ---\n";
    std::cout << "• When you need random access to elements\n";
    std::cout << "• When size varies during runtime\n";
    std::cout << "• When you need to frequently add/remove at the end\n";
    std::cout << "• Implementation of other data structures\n";
    std::cout << "• Suitable for most general-purpose collections\n";
}