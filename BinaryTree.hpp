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
        BinaryNode<T>* left;
        BinaryNode<T>* right;
        template<class U>
        explicit BinaryNode(const U&& value, BinaryNode<T>* const left, BinaryNode<T>* const right)
            : value(std::forward<U>(value)),
              left(left),
              right(right) {
        }
    };

    size_t current_size{};
    BinaryNode* root{};

    class BinaryIterator {
        BinaryNode* current_node;

    public:
        explicit BinaryIterator(::BinaryTree<T>::BinaryNode* current_node)
            : current_node(current_node)
         {
        }

    private:
        T& operator*() {
            return current_node->value;
        }

        BinaryIterator& operator++() {
            // Successor is the minimum value node in the right subtree
            if (current_node->right != nullptr) {
                BinaryNode* current = current_node->right;
                while (current->left != nullptr) {
                    current = current->left;
                }
                current_node =  current;
            }else {
                current_node = nullptr;
            }
            return *this;
        }
        // Predecessor is the maximum value node in the left subtree
        BinaryIterator& operator--() {
            if (current_node->left == nullptr) {
                current_node =  nullptr;
                BinaryNode* current = current_node->left;
                while (current->right != nullptr) {
                    current = current->right;
                }
                current_node =  current;
            }else {
                current_node = nullptr;

            }
            return *this;
        }

        bool operator==(const BinaryIterator& other) const {
            return this->current_node == other.current_node;
        }

        bool operator!=(const BinaryIterator& other) const {
            return this->current_node != other.current_node;
        }
    };

    /**
     * Wstawia element x do drzewa
     */
    template<class U>
    void insert(const U&& x) {
        BinaryNode node = new BinaryNode(x);

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
