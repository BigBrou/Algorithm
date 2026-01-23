#ifndef TREE1_NODE_H
#define TREE1_NODE_H

#include <iostream>

template<typename dataType>
class Node {
public:
    dataType data;
    Node *parent;
    Node *left;
    Node *right;

public:
    Node(dataType data) {
        this->data = data;
        this->parent = NULL;
        this->left = NULL;
        this->right = NULL;
    }


    Node(Node<dataType> *parent, dataType data)
            : parent(parent), data(data) {}

    ~Node() {
        this->parent = NULL;
        this->left = NULL;
        this->right = NULL;
    };
};

enum class position {
    LEFT,
    RIGHT
};

#endif //TREE1_NODE_H
