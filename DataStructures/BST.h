#ifndef PROIECTTOYSOCIALNETWORK_TREE_H
#define PROIECTTOYSOCIALNETWORK_TREE_H

#include "Node.h"

template<class T>
class ABC {
private:
    ABCNode<T> *root;
    int size{};

    void add(ABCNode<T> *ad, T elem) {

        if (ad->info > elem) { // add left
            if (ad->left != nullptr) {
                add(ad->left, elem);
            } else {
                ad->left = new ABCNode<T>(elem, nullptr, nullptr);
            }
        } else {  //add right
            if (ad->right != nullptr) {
                add(ad->right, elem);
            } else {
                ad->right = new ABCNode<T>(elem, nullptr, nullptr);
            }
        }
    }

    void showIN(ABCNode<T> *ad) {
        if (ad != nullptr) {
            showIN(ad->left);
            cout << ad->info << endl;
            showIN(ad->right);
        }
    }

    ABCNode<T> *removeNode(ABCNode<T> *node, T key) {
        if (node == nullptr)
            return node;
        if (key < node->info)
            node->left = removeNode(node->left, key);
        else if (key > node->info)
            node->right = removeNode(node->right, key);
        else {
            if (node->right == nullptr and node->left == nullptr)
                return nullptr;
            else if (node->left == nullptr) {
                return node->right;
            } else if (node->right == nullptr)
                return node->left;
            T temp = minValueNode(node->right)->info;
            node->info = temp;
            node->right = removeNode(node->right, temp);
        }
        return node;
    }


    ABCNode<T> *minValueNode(ABCNode<T> *node) {
        ABCNode<T> *current = node;

        while (current && current->left != nullptr)
            current = current->left;

        return current;
    }

    ABCNode<T> *searchNode(ABCNode<T> *current, T key) {

        if (current == nullptr)
            return nullptr;

        if (current->info == key)
            return current;
        if (current->info < key)
            return searchNode(current->right, key);
        return searchNode(current->left, key);
    }

public:
    /**
     * Constructor
     */
    ABC() {
        this->root = nullptr;
        this->size = 0;
    }

/**
 * Add an entity to BST
 * @param elem
 */
    void add(T elem) {
        if (this->root == nullptr) this->root = new ABCNode<T>(elem, nullptr, nullptr);
        else add(this->root, elem);
        this->size++;
    }

/**
 * Remove an element from BST
 * @param key
 * @return
 */
    ABCNode<T> *remove(T key) {
        this->size--;
        return removeNode(this->root, key);
    }

/**
 * Search an element in BST
 * @param key
 * @return
 */
    bool search(T key) {
        if (searchNode(this->root, key))
            return true;
        return false;
    }

/**
 * Get a node from BST
 * @param key
 * @return
 */
    T &getNode(T key) {
        ABCNode<T> *node = searchNode(this->root, key);
        return node->info;
    }

/**
 * Show elements from BST
 */
    void show() {
        showIN(this->root);
    }

/**
 * Get the number of elements in BST
 * @return
 */
    int lSize() {
        return this->size;
    }
};

template<class T>
bool ABCNode<T>::operator==(const ABCNode &rhs) const {
    return info == rhs.info &&
           left == rhs.left &&
           right == rhs.right;
}

template<class T>
bool ABCNode<T>::operator!=(const ABCNode &rhs) const {
    return !(rhs == *this);
}

#endif //PROIECTTOYSOCIALNETWORK_TREE_H
