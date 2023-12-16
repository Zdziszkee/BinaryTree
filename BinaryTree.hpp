//
// Created by Kacper Kuchta on 12/7/23.
//

#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP
#include <stack>
#include <utility>

template<typename T>
class BinaryTree {
    class BinaryNode {
    public:
        T value;
        BinaryNode* left;
        BinaryNode* right;

        template<class U>
        explicit BinaryNode(const U&& value, BinaryNode* const left, BinaryNode* const right)
            : value(std::forward<U>(value)),
              left(left),
              right(right) {
        }
    };

    size_t current_size{};
    BinaryNode* root{};

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
            BinaryNode* node = stack.top()->right;

            while (node != nullptr) {
                stack.push(node);
                node = node->left;
            }

            if (!stack.empty()) {
                stack.pop();
            }
            return *this;
        }

        BinaryIterator& operator--() {
            BinaryNode* current = stack.top()->left;

            while (current != nullptr) {
                stack.push(current);
                current = current->right;
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

    /**
     * Wstawia element x do drzewa
     */
    template<class U>
    void insert(const U&& x) {
        BinaryNode node = new BinaryNode(x);
        BinaryNode parent = nullptr;
        BinaryNode child = root;

        while (child != nullptr) {
            parent = child;
            if (x >= child.value) {
                child = child.right;
            } else {
                child = child.left;
            }
        }

        if (x < parent.value) {
            parent->left = node;
        } else {
            parent->right = node;
        }
    }

    /**
     * Sprawdza czy element należy do drzewa, zwraca wskaźnik do węzła lub nullptr.
     */
    template<class U>
    void search(U&& x) {
    }

    /**
     * Sprawdza czy element należy do drzewa, zwraca wskaźnik do węzła lub nullptr.
     */
    template<class U>
    void searchRecursive(U&& x);

    /**
     * Zwraca liczbę węzłów
     */
    size_t size() {
        return current_size;
    }

    /**
     *  Zwraca wartość najmniejszego elementu
     */
    minimum();

    /**
     *  Zwraca wartość największego elementu
     */
    maximum();

    /**
     * Zwraca wysokość drzewa
     */
    depth();

    /**
     * Wypisuje zawartość wszystkich węzłów w kolejnosci inorder
     */
    inorder();

    /**
     * Wypisuje zawartość wszystkich węzłów w kolejnosci preorder
     */
    preorder();

    /**
     * Wypisuje zawartość wszystkich węzłów w kolejnosci postorder
     */
    postorder();

    /**
     * Usuwa węzeł it (iterator) z drzewa
     */
    erase (it){
    };
    /**
     * Ssprawdza czy w drzewie istnieje droga korzeń-do-liścia dla której suma wartości w węzłach jest równa x
     */
    hasPathSum (x){
    };

    /**
     *  Sprawdza czy dwa drzewa są identyczne
     */
    sameTree(tree1, tree2);


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
