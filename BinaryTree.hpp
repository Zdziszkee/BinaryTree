//
// Created by Kacper Kuchta on 12/7/23.
//

#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP
#include <stack>

template<typename T>
class BinaryTree {
    struct BinaryNode {
    public:
        T value;
        BinaryNode* left;
        BinaryNode* right;

        template<class U>
        explicit BinaryNode(U&& value, BinaryNode* left = nullptr, BinaryNode* right = nullptr)
            : value(std::forward<U>(value)),
              left(left),
              right(right) {
        }
    };

    class BinaryIterator {
        std::stack<BinaryNode *> stack;

    public:
        explicit BinaryIterator(BinaryNode* root) {
            while (root != nullptr) {
                stack.push(root);
                root = root->left;
            }
        }

        T& operator*() {
            return stack.top()->value;
        }

        BinaryIterator& operator++() {
            BinaryNode* top = stack.top();
            stack.pop();
            if (top->right != nullptr) {
                stack.push(top->right);
                top = top->right;
                while (top->left != nullptr) {
                    stack.push(top->left);
                    top = top->left;
                }
            }


            return *this;
        }

        BinaryIterator& operator--() {
            BinaryNode* node = stack.top()->left;

            while (node != nullptr) {
                stack.push(node);
                node = node->right;
            }

            if (!stack.empty()) {
                stack.pop();
            }
            return *this;
        }

        bool operator==(const BinaryIterator& other) const {
            return stack == other.stack;
        }

        bool operator!=(const BinaryIterator& other) const {
            return stack != other.stack;
        }
    };

private:
    size_t current_size{};
    BinaryNode* root{};

public:
    /**
     * Wstawia element x do drzewa
     */
    template<class U>
    void insert(const U&& x) {
        auto* node = new BinaryNode(x, nullptr, nullptr);
        BinaryNode* parent = nullptr;
        BinaryNode* child = root;
        if (root == nullptr) {
            root = node;
            return;
        }
        while (child != nullptr) {
            parent = child;
            if (x >= child->value) {
                child = child->right;
            } else {
                child = child->left;
            }
        }

        if (x < parent->value) {
            parent->left = node;
        } else {
            parent->right = node;
        }
        current_size++;
    }

    /**
     * Sprawdza czy element należy do drzewa, zwraca wskaźnik do węzła lub nullptr.
     */
    template<class U>
    BinaryNode* search(U&& x) {
        BinaryNode* child = root;

        while (child != nullptr) {
            if (x >= child->value) {
                child = child->right;
                if (child->value == std::forward<U>(x)) {
                    return child;
                }
            } else {
                child = child->left;
            }
        }

        return nullptr;
    }

    /**
     * Sprawdza czy element należy do drzewa, zwraca wskaźnik do węzła lub nullptr.
     */
    template<class U>
    BinaryNode* searchRecursive(BinaryNode* node, U&& x) const {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->value == x) {
            return node;
        }
        if (x >= node->value) {
            searchRecursive(node->right, std::forward<U>(x));
        } else {
            searchRecursive(node->left, std::forward<U>(x));
        }
    }

    /**
     * Zwraca liczbę węzłów
     */
    size_t size() {
        return current_size;
    }

    /**
     *  Zwraca wartość najmniejszego elementu
     */
    void minimum() {
    }

    /**
     *  Zwraca wartość największego elementu
     */
    void maximum() {
    }

    /**
     * Zwraca wysokość drzewa
     */
    void depth() {
    }

    /**
     * Wypisuje zawartość wszystkich węzłów w kolejnosci inorder
     */
    void inorder() {
    }

    /**
     * Wypisuje zawartość wszystkich węzłów w kolejnosci preorder
     */
    void preorder() {
    }

    /**
     * Wypisuje zawartość wszystkich węzłów w kolejnosci postorder
     */
    void postorder() {
    }

    /**
     * Usuwa węzeł it (iterator) z drzewa
     */
    void erase(BinaryIterator iterator) {
    };
    /**
     * Ssprawdza czy w drzewie istnieje droga korzeń-do-liścia dla której suma wartości w węzłach jest równa x
     */
    template<class U>
    void hasPathSum(U&& x) {
    };

    /**
     *  Sprawdza czy dwa drzewa są identyczne
     */

    void sameTree(BinaryTree second) {
    }


    BinaryIterator begin() const {
        return BinaryIterator(root);
    };

    BinaryIterator end() const {
        return BinaryIterator(nullptr);
    };

    BinaryIterator rbegin() {
    }

    BinaryIterator rend();
};
#endif //BINARYTREE_HPP
