#include <iostream>
#include "Node.h"
#include "NodeFunction.h"

template <typename dataType>
void preorder(Node<dataType> *root) {
    if (root == NULL)
        return;

    std::cout << root->data;

    preorder(root->left);
    preorder(root->right);
}

template <typename dataType>
void inorder(Node<dataType> *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    std::cout << root->data;
    inorder(root->right);
}

template <typename dataType>
void postorder(Node<dataType> *root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    std::cout << root->data;
}


int main() {
    int nodeCount;
    std::cin >> nodeCount;

    Node<char> *root;
    Node<char> *parentNode = NULL;

    for (int idx = 0; idx < nodeCount; idx++)  {
        char data;
        char parentData;
        char pos;

        if (idx == 0) {
            std::cin >> data;
            root = new Node<char>(data);
        }
        else {
            while (parentNode == NULL) {
                std::cout << "choose parent ";
                std::cin >> parentData;
                parentNode = searchNode(root, parentData);
            }

            std::cout << "insert data and position(l,r) : ";
            std::cin >> data >> pos;
            if (pos == 'l')
                insertNode(parentNode, data, position::LEFT);
            else
                insertNode(parentNode, data, position::RIGHT);
            parentNode = NULL;
        }
    }

    preorder(root);
    std::cout << std::endl;
    inorder(root);
    std::cout << std::endl;
    postorder(root);

    return 0;
}


