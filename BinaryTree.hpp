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

        BinaryNode(const T value, BinaryNode<T>* const left, BinaryNode<T>* const right)
            : value(value),
              left(left),
              right(right) {
        }
    };

    size_t current_size{};
    BinaryNode* root{};

    class BinaryIterator {
        std::stack<BinaryNode*> stack;
        BinaryNode* current_node{};

        explicit BinaryIterator(const BinaryNode* tree) : current_node(tree) {
        }

        T& operator*() { return current_node->value; }

        BinaryIterator& operator++() {
            if (current_node->right == nullptr) {
                stack.pop();
            }else {

            }
            return *this;
        }

        BinaryIterator& operator--() {
            current_node.
            return *this;
        }

        bool operator==(const Iterator& other) const {
            return this->current_node == other.current_node;
        }

        bool operator!=(const Iterator& other) const {
            return this->current_node != other.current_node;
        }
    };

    /**
     * Wstawia element x do drzewa
     */
    template<class U>
    void insert(U&& x) {
        BinaryNode node = new BinaryNode(x);
        node.



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


    begin();

    end();

    rbegin();

    rend();
};
#endif //BINARYTREE_HPP
