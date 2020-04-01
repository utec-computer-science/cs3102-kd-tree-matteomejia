#include <bits/stdc++.h>
#include "kdt.h"

typedef std::vector<int> container;

int main() {
    KDTree<container> kdtree(2);

    container point(2);
    point[0] = 0;
    point[1] = 0;

    kdtree.insertNode(kdtree.root, point, 0);

    for (int i = 0; i < 100; i++) {
        container cont(kdtree.dimension);
        cont[0] = rand() % 1000;
        cont[1] = rand() % 1000;
        kdtree.insertNode(kdtree.root, cont, 0);
    }

    std::cout << kdtree.searchNode(kdtree.root, point, 0);

    kdtree.print(kdtree.root, 10);

    return 0;
}