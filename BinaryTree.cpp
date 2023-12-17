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
    std::cout << tree.size() << std::endl;
    std::cout << tree.depth() << std::endl;
    std::cout << tree.minimum() << std::endl;
    std::cout << tree.maximum() << std::endl;
    tree.preorder();
    for (int i = 1; i < 9; ++i) {
        const auto node = tree.search(i);
        if (node != nullptr) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}
