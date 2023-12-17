#include <iostream>
#include "BinaryTree.hpp"


void test() {
    BinaryTree<int> tree;
    tree.insert(5);
    tree.insert(1);
    tree.insert(10);
    tree.insert(7);
    tree.insert(6);
    tree.insert(8);
    tree.insert(13);
    tree.insert(12);
    tree.insert(14);
    for (int element : tree) {
        std::cout<<element<<std::endl;
    }

}

int main() {
    test();
    /*
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
    for (int i = 1; i < 10; ++i) {
        const auto node = tree.search(i);
        if (node != nullptr) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
    */

    return 0;
}


