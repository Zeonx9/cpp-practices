//
// Created by musht on 06.11.2022.
//
#include <iostream>

#define B

#ifdef A
#include "DynArray.h"

int main() {
    DynArray<int> a{1, 2, 3}, b{4, 5, 6};
    std::cout << DynArray<int>::getObjectCount() << "\n";
    DynArray<int> c = a + b;
    std::cout << DynArray<int>::getObjectCount() << "\n";
    DynArray<int> d = a * 5;
    DynArray<int> p = d;
    std::cout << a << " " << p << " " << "\n" << DynArray<int>::getObjectCount() << "\n";
    DynArray<std::string> ss{"hello", " ", "world", "!"};
    std::cout << DynArray<std::string>::getObjectCount() << "\n";
}
#endif

#ifdef B
#include "include/Queue.h"

int main() {
    Queue<int> q{1, 2, 3, 4, 5}, q2(5);
    std::cout << q << " " << q2 << "\n";
    while (not q.isEmpty())
        q2.enqueue(q.dequeue());
    std::cout << q << " " << q2 << "\n";
}
#endif