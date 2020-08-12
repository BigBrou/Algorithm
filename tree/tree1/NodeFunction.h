#ifndef TREE1_NODEFUNCTION_H
#define TREE1_NODEFUNCTION_H

#include "Node.h"

template<typename dataType>
Node<dataType> * searchNode(Node<dataType> *node, dataType data) {
    if (node == NULL)
        return NULL;
    if (node->data == data)
        return node;

    Node<dataType>* leftNode = searchNode(node->left, data);
    Node<dataType>* rightNode = searchNode(node->right, data);

    if (leftNode != NULL)
        return leftNode;
    else if (rightNode != NULL)
        return rightNode;
    else
        return NULL;
}

template<typename dataType>
void insertNode(Node<dataType> *parent, dataType data, position pos) {
    Node<dataType> *node = new Node<dataType>(parent, data);

    if (pos == position::LEFT)
        parent->left = node;
    else
        parent->right = node;
    node->parent = parent;
}

template <typename dataType>
void deleteNode(Node<dataType> *root, dataType data) {
    Node<dataType>* node = searchNode(root, data);
    Node<dataType>* parent = node->parent;

    Node<dataType>* leftNode = node->left;
    Node<dataType>* rightNode = node->right;


    if ((leftNode == NULL) && (rightNode == NULL)) {
        if (parent->left == node)
            parent->left = NULL;
        else
            parent->right = NULL;
    }
    else if (rightNode != NULL) {
        if (parent->left == node)
            parent->left = rightNode;
        else
            parent->right = rightNode;
    }
    else {
        if (parent->left == node)
            parent->left = leftNode;
        else
            parent->right = leftNode;
    }


    delete node;
}


#endif //TREE1_NODEFUNCTION_H
