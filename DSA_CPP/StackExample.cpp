#include "StackExample.h"

void StackExample::demonstrate()
{
    std::cout << "\n=== Stack Example ===\n";
    std::cout << "Stack: LIFO (Last In, First Out) data structure\n";
    std::cout << "Time Complexity - Push: O(1), Pop: O(1), Top: O(1)\n";
    std::cout << "Space Complexity: O(n)\n\n";

    basicStackOperations();
    std::cout << std::endl;
    customStackImplementation();
}

void StackExample::basicStackOperations()
{
    std::cout << "--- Using STL Stack ---\n";
    std::stack<int> stack;

    // Push elements
    std::cout << "Pushing elements: 10, 20, 30, 40, 50\n";
    for (int i = 1; i <= 5; i++)
    {
        stack.push(i * 10);
        std::cout << "Pushed: " << (i * 10) << ", Size: " << stack.size() << std::endl;
    }

    std::cout << "\nTop element: " << stack.top() << std::endl;

    // Pop elements
    std::cout << "\nPopping all elements:\n";
    while (!stack.empty())
    {
        std::cout << "Popped: " << stack.top() << ", Size: " << stack.size() - 1 << std::endl;
        stack.pop();
    }

    std::cout << "Stack is " << (stack.empty() ? "empty" : "not empty") << std::endl;
}

void StackExample::customStackImplementation()
{
    std::cout << "--- Custom Stack Implementation ---\n";
    CustomStack<std::string> customStack;

    // Push elements
    std::cout << "Pushing string elements:\n";
    customStack.push("First");
    customStack.push("Second");
    customStack.push("Third");
    customStack.push("Fourth");

    customStack.display();

    std::cout << "\nTop element: " << customStack.top() << std::endl;
    std::cout << "Stack size: " << customStack.size() << std::endl;

    // Pop some elements
    std::cout << "\nPopping 2 elements:\n";
    customStack.pop();
    customStack.pop();

    customStack.display();

    std::cout << "\nFinal stack size: " << customStack.size() << std::endl;
    std::cout << "Is empty: " << (customStack.isEmpty() ? "Yes" : "No") << std::endl;
}