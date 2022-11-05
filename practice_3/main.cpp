#include <iostream>

#define A

#ifdef A
#include "DynArray.h"

int main() {
    DynArray arr(10);
    arr.append(1.0);
    for (int i = 0; i < 15; ++i) {
        arr.append(i * 1.1);
    }
    std::cout << arr << '\n';
}
#endif

#ifdef B
#include "MyStack.h"

int main() {
    int n;
    std::cout << "Enter a number of elements in sequence\n";
    std::cin >> n;

    MyStack stack;

    std::cout << "Enter elements:\n";
    for (int i = 0; i < n; ++i) {
        int elem;
        std::cin >> elem;
        stack.put(elem);
    }
    std::cout << "Reversed Sequece\n";
    while (!stack.isEmpty()) {
        std::cout << stack.pop() << ' ';
    }
    std::cout << "\n";
    stack.pop();
}
#endif