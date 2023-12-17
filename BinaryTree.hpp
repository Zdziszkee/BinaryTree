//
// Created by Kacper Kuchta on 12/7/23.
//

#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP
#include <queue>
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

        //TODO FIX
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
    size_t current_depth{};

public:
    /**
     * Wstawia element x do drzewa
     */
    template<class U>
    void insert(U&& x) {
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
            auto value = child->value;

            if (x > value) {
                child = child->right;
            } else if (x < value) {
                child = child->left;
            } else {
                return child;
            }
        }

        return nullptr;
    }

    /**
     * Sprawdza czy element należy do drzewa, zwraca wskaźnik do węzła lub nullptr.
     */
    template<class U>
    BinaryNode* searchRecursive(U&& x, BinaryNode* node) const {
        if (node == nullptr) {
            return nullptr;
        }
        auto value = node->value;
        if (x > value) {
            searchRecursive(node->right, x);
        } else if (x < value) {
            searchRecursive(node->left, x);
        } else {
            return node;
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

    T& minimum() {
        BinaryNode* node = root;
        while (node->left != nullptr) {
            node = node->left;
        }
        return node->value;
    }

    /**
     *  Zwraca wartość największego elementu
     */
    void maximum() {
        BinaryNode* node = root;
        while (node->right != nullptr) {
            node = node->right;
        }
        return node->value;
    }

    /**
     * Zwraca wysokość drzewa
     */
    size_t depth() {
        if (root == nullptr)return 0;

        size_t depth = 0;
        std::queue<BinaryNode *> queue;
        queue.push(root);

        while (!queue.empty()) {
            depth++;
            const size_t size = queue.size();

            for (int i = 0; i < size; ++i) {
                BinaryNode* current = queue.front();
                queue.pop();

                if (current->left) {
                    queue.push(current->left);
                }
                if (current->right) {
                    queue.push(current->right);
                }
            }
        }
        return depth;
    }

    /**
     * Zwraca wysokość drzewa
     */
    size_t depth_recursive(BinaryNode* root) {
        if (root == nullptr)return 0;

        const size_t left_depth = depth_recursive(root->left);
        const size_t right_depth = depth_recursive(root->right);

        return std::max(left_depth, right_depth) + 1;
    }

    /**
     * Wypisuje zawartość wszystkich węzłów w kolejnosci inorder
     */
    void inorder() const {
        auto iterator = this->begin();
        while (iterator != this->end()) {
            std::cout << *iterator << std::endl;
            ++iterator;
        }
    }

    /**
     * Wypisuje zawartość wszystkich węzłów w kolejnosci inorder
     */
    void inorder_recursive(BinaryNode* root) {
        if (root == nullptr) return;
        inorder_recursive(root->left);
        std::cout << root->value << " ";
        inorder_recursive(root->right);
    }

    /**
     * Wypisuje zawartość wszystkich węzłów w kolejnosci preorder
     */
    void preorder() {
        std::stack<BinaryNode *> stack;
        stack.push(root);
        while (!stack.empty()) {
            BinaryNode* current = stack.top();
            stack.pop();
            std::cout << current->value << std::endl;
            if (current->right != nullptr) {
                stack.push(current->right);
            }
            if (current->left != nullptr) {
                stack.push(current->left);
            }
        }
    }

    /**
     * Wypisuje zawartość wszystkich węzłów w kolejnosci preorder
     */
    void preorder_recursive(BinaryNode* root) {
        if (root == nullptr) return;
        std::cout << root->value << std::endl;
        preorder_recursive(root->left);
        preorder_recursive(root->right);
    }

    /**
     * Wypisuje zawartość wszystkich węzłów w kolejnosci postorder
     */
    void postorder() {
        //complex to implmement iterative way so
        postorder_recursive(root);
    }

    /**
     * Wypisuje zawartość wszystkich węzłów w kolejnosci postorder
     */
    void postorder_recursive(BinaryNode* root) {
        if (root == nullptr) return;
        postorder_recursive(root->left);
        postorder_recursive(root->right);
        std::cout << root->value << std::endl;
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
