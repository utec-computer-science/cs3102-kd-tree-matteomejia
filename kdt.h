#include <iostream>
#include <ostream>
#include <vector>


template <typename Container>
struct Node {
    Container point;
    Node<Container> *left, *right;
};

template <typename Container>
struct Node<Container> *newNode(Container point, int k) {
    struct Node<Container> *temp = new Node<Container>;

    temp->point = point;
    
    temp->left = temp->right = nullptr;
    return temp;
}

template <typename Container>
class KDTree {
public:
    Node<Container> *root;
    int k;

    KDTree(int _k) {
        this->k = _k;
        this->root = nullptr;
    }

    Node<Container> *insertPoint(Node<Container> *root, Container point, unsigned depth) {
        if (root == nullptr) {
            return newNode(point, k);
        }

        unsigned cd = depth % k;

        if (point[cd] < (root->point[cd])) {
            root->left = insertPoint(root->left, point, cd + 1);
        } else {
            root->right = insertPoint(root->right, point, cd + 1);
        }

        return root;
    }

    Node<Container> *insert(Node<Container> *root, Container point) {
        return insertPoint(root, point, 0);
    }

    Container operator ==(Container point) {
        for (int i = 0; i < k; i++) {
            if (this[i] != point[i]) {
                return false;
            }
        }
        return true;
    }

    bool searchPoint(Node<Container> *root, Container point, unsigned depth) {
        if (root == nullptr) {
            return false;
        }

        if (root->point == point) {
            return true;
        }

        unsigned cd = depth % k;

        if (point[cd] < root->point[cd]) {
            return searchPoint(root->left, point, cd + 1);
        }

        return searchPoint(root->right, point, cd + 1);
    }

    bool search(Node<Container> *root, Container point) {
        return searchPoint(root, point, 0);
    }

    /*std::ostream& operator<<(std::ostream& os, std::vector<int> point) {
        os << point[0] << ", " << point[1] << std::endl;
        return os;
    }*/

    void print(Node<Container> *root, int depth) {
        if (root == nullptr) {
            std::cout << "Empty\n";
        }

        if (depth == 0) {
            std::cout << "K-D Tree\n";
            std::cout << "root = ";
        }

        std::cout << depth << ": " <<  root->point[0] << ", " << root->point[1] << std::endl;

        if (root->left != nullptr) {
            std::cout << "\n" << "Lchild = ";
            print(root->left, depth + 1);
        }

        if (root->right != nullptr) {
            std::cout << "\n" << "Rchild = ";
            print(root->right, depth + 1);
        }

        if (depth == 0) {
            std::cout << "\nEND\n";
        }
    }

};