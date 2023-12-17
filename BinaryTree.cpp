#include <iostream>
#include "BinaryTree.hpp"
int main() {
    BinaryTree<int> tree;
    int n;
    std::cin >> n;
    int integer;
    while (std::cin >> integer) {
        tree.insert(integer);
    }

    return 0;
}
