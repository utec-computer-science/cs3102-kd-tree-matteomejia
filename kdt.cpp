#include <iostream>
#include <vector>
#include <fstream>
#include "kdt.h"

typedef std::vector<int> container;
int main() {
    KDTree<container> kdt(2);

    std::vector<container> points(1000);

    for (int i = 0; i < 1000; i++) {
        points[i][0] = rand() % 1000;
        points[i][1] = rand() % 1000;
    }

    for (container cp : points) {
        kdt.insert(kdt.root, cp);
    }

    kdt.print(kdt.root, 0);

    return 0;
}