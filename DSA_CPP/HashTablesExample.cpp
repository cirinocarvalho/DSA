#include "HashTablesExample.h"
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

void HashTablesExample::demonstrate()
{
    std::cout << "\n=== Hash Tables Example ===\n";
    std::cout << "Hash Table: Key-value data structure with O(1) average access\n";
    std::cout << "Time Complexity - Insert/Delete/Search: O(1) average, O(n) worst\n";
    std::cout << "Space Complexity: O(n)\n\n";

    // Demonstrate basic hash table operations
    std::cout << "--- Basic Hash Table Operations ---\n";
    std::unordered_map<std::string, int> hashTable;

    // Insert key-value pairs
    std::cout << "Inserting key-value pairs:\n";
    hashTable["apple"] = 5;
    hashTable["banana"] = 3;
    hashTable["cherry"] = 8;
    hashTable["date"] = 2;
    hashTable["elderberry"] = 12;

    for (const auto &pair : hashTable)
    {
        std::cout << "Key: '" << pair.first << "' -> Value: " << pair.second << std::endl;
    }

    // Search operations
    std::cout << "\n--- Search Operations ---\n";
    std::vector<std::string> searchKeys = {"apple", "grape", "cherry", "fig"};

    for (const std::string &key : searchKeys)
    {
        auto it = hashTable.find(key);
        if (it != hashTable.end())
        {
            std::cout << "Found '" << key << "' with value: " << it->second << std::endl;
        }
        else
        {
            std::cout << "Key '" << key << "' not found in hash table" << std::endl;
        }
    }

    // Update values
    std::cout << "\n--- Update Operations ---\n";
    std::cout << "Before update - apple: " << hashTable["apple"] << std::endl;
    hashTable["apple"] = 10;
    std::cout << "After update - apple: " << hashTable["apple"] << std::endl;

    // Delete operations
    std::cout << "\n--- Delete Operations ---\n";
    std::cout << "Deleting 'banana'...\n";
    hashTable.erase("banana");

    std::cout << "Hash table after deletion:\n";
    for (const auto &pair : hashTable)
    {
        std::cout << "Key: '" << pair.first << "' -> Value: " << pair.second << std::endl;
    }

    // Demonstrate collision handling concept
    std::cout << "\n--- Collision Handling Demo ---\n";
    demonstrateSimpleHashFunction();

    // Hash table statistics
    std::cout << "\n--- Hash Table Statistics ---\n";
    std::cout << "Current size: " << hashTable.size() << std::endl;
    std::cout << "Bucket count: " << hashTable.bucket_count() << std::endl;
    std::cout << "Load factor: " << hashTable.load_factor() << std::endl;
    std::cout << "Max load factor: " << hashTable.max_load_factor() << std::endl;

    std::cout << "\n--- Hash Table Properties ---\n";
    std::cout << "✓ Very fast average case O(1) operations\n";
    std::cout << "✓ Flexible key types (strings, numbers, objects)\n";
    std::cout << "✓ Dynamic resizing\n";
    std::cout << "✓ Memory efficient for sparse data\n";
    std::cout << "✗ Worst case O(n) with poor hash function\n";
    std::cout << "✗ No ordering of elements\n";
    std::cout << "✗ Hash function quality affects performance\n";

    std::cout << "\n--- Use Cases ---\n";
    std::cout << "• Caching and memoization\n";
    std::cout << "• Database indexing\n";
    std::cout << "• Symbol tables in compilers\n";
    std::cout << "• Counting frequency of elements\n";
    std::cout << "• Fast lookups in large datasets\n";
}

void HashTablesExample::demonstrateSimpleHashFunction()
{
    std::cout << "Simple hash function demonstration (key % table_size):\n";

    const int TABLE_SIZE = 7;
    std::vector<std::string> keys = {"key1", "key8", "key15", "key22", "key2"};

    std::cout << "Table size: " << TABLE_SIZE << std::endl;
    std::cout << "Hash function: sum of ASCII values % " << TABLE_SIZE << std::endl;

    for (const std::string &key : keys)
    {
        int hash = simpleHashFunction(key, TABLE_SIZE);
        std::cout << "'" << key << "' -> hash: " << hash;

        // Show potential collision
        bool collision = false;
        for (const std::string &otherKey : keys)
        {
            if (otherKey != key && simpleHashFunction(otherKey, TABLE_SIZE) == hash)
            {
                std::cout << " (collision with '" << otherKey << "')";
                collision = true;
                break;
            }
        }

        std::cout << std::endl;
    }

    std::cout << "\nCollision resolution strategies:\n";
    std::cout << "• Chaining: Store multiple values in same bucket (linked list)\n";
    std::cout << "• Open addressing: Find next available slot (linear probing)\n";
    std::cout << "• Robin Hood hashing: Minimize variance in probe distances\n";
}

int HashTablesExample::simpleHashFunction(const std::string &key, int tableSize)
{
    int sum = 0;
    for (char c : key)
    {
        sum += static_cast<int>(c);
    }
    return sum % tableSize;
}