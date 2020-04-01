#include <bits/stdc++.h>

template <typename Container>
class Node {
public:
    Container point;
    Node<Container> *left, *right;

    Node(Container point) {
        this->point = point;
        this->left = this->right = NULL;
    }
};

template <typename Container>
class KDTree {
public:
    Node<Container> *root;
    int dimension;

    KDTree(int d) {
        this->dimension = d;
        this->root = nullptr;
    }

    Node<Container> *insertNode(Node<Container> *root, Container point, unsigned depth) {
        if (root == nullptr) {
            return new Node<Container>(point);
        }

        depth %= 2;

        if (point[depth] < (root->point[depth])) {
            root->left = insertNode(root->left, point, depth + 1);
        } else {
            root->right = insertNode(root->right, point, depth + 1);
        }

        return root;
    }

    Container operator ==(Container point) {
        for (int i = 0; i < dimension; i++) {
            if (this[i] != point[i]) {
                return false;
            }
        }
        return true;
    }

    bool searchNode(Node<Container> *root, Container point, unsigned depth) {
        if (root == nullptr) {
            return false;
        }

        if (root->point == point) {
            return true;
        }

        depth %= 2;

        if (point[depth] < root->point[depth]) {
            return searchNode(root->left, point, depth + 1);
        }

        return searchNode(root->right, point, depth + 1);
    }

    void print(Node<Container> *root, int depth) {
        if (depth == 0) {
            std::cout << "-- Kd Tree --" << std::endl;
        }
        std::cout << depth << ": " << root->point[0] << ", " << root->point[1] << std::endl;

        if (root->left != nullptr) {
            print(root->left, depth + 1);
        }

        if (root->right != nullptr) {
            print(root->right, depth + 1);
        }

        if (depth == 0) {
            std::cout << "-- END --" << std::endl;
        }
    }

};