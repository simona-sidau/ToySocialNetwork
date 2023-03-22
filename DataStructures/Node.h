#ifndef PROIECTTOYSOCIALNETWORK_NODE_H
#define PROIECTTOYSOCIALNETWORK_NODE_H

#include<iostream>

using namespace std;

template<typename T>
class ABC;

template<class T>
class ABCNode {
private:
    T info;
    ABCNode<T> *left;
    ABCNode<T> *right;
public:
    /**
     * Constructor
     * @param info
     */
    ABCNode(T info) : info(info) { this->left = nullptr, this->right = nullptr; }

    /**
     * Constructor
     * @param info
     * @param left
     * @param right
     */
    ABCNode(T info, ABCNode<T> *left, ABCNode<T> *right) : info(info), left(left), right(right) {}

    bool operator==(const ABCNode &rhs) const;

    bool operator!=(const ABCNode &rhs) const;

    ABCNode &operator=(const ABCNode &rhs) {
        this->info = info;
        this->right = right;
        this->left = left;
    }

    friend class ABC<T>;
};

#endif //PROIECTTOYSOCIALNETWORK_NODE_H
