#include <iostream>
#include "BinaryTree.hpp"
int main() {
    BinaryTree<int> tree;
    tree.insert(5);
    tree.insert(7);
    tree.insert(4);
    tree.insert(1);
    tree.insert(6);
    tree.insert(3);
    tree.insert(9);
    tree.insert(8);
    tree.insert(2);
    tree.insert(10);

    for (int value : tree) {
        std::cout << value << std::endl;

    }
    return 0;
}
