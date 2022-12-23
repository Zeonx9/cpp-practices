//
// Created by musht on 30.11.2022.
//
#define B
#include <vector>
#include <iostream>

#ifdef A
using array = std::vector<int>;
void removeZerosAndShrink(array &arr) {
    for (auto it = arr.begin(); it < arr.end(); ++it)
        if (*it == 0) {
            arr.erase(it);
            --it;
        }
    arr.shrink_to_fit();
}

int main() {
    array a{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 3, 2, 4, -6, 0};
    removeZerosAndShrink(a);
    for (auto &e : a)
        std::cout << e << " ";
}
#endif

#ifdef B
#include "LinkedList.h"

template<class T>
void print_ll(const LinkedList<T> &ll) {
    for (auto e : ll) {
        std::cout << e << " ";
    }
    std::cout << "\n";
}

int main() {
    LinkedList<int> a{1, 2, 3, 5, 6, 3, 4, 8, 0, 0};
    print_ll(a);
    LinkedList<char> b("some words here");
    print_ll(b);
    LinkedList<char> c = b;
    print_ll(c);
    LinkedList<char> d("hello");
    print_ll(d);
    c = d;
    print_ll(c);
    a.push_front(-1);
    b.push_front('G');
    a.pop_back();
    print_ll(a);

    c = "hello assigned";
    print_ll(c);

}
#endif
//struct BinaryTree {
//    BinaryTree *left;
//    BinaryTree *right;
//    int val;
//};
//
//
//void branches_sum(BinaryTree *tree, int prefix, std::vector<int> &container) {
//    int new_prefix = prefix + tree->val;
//    if (not tree->left and not tree->right) {
//        container.push_back(new_prefix);
//    } else {
//        branches_sum(tree->left, new_prefix, container);
//        branches_sum(tree->right, new_prefix, container);
//    }
//}
//int main() {
//    BinaryTree t;
//    std::vector<int> v{};
//    branches_sum(&t, 0, v);
//}



