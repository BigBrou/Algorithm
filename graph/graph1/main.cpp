#include <iostream>
#include <stack>
#include <vector>
#include <array>

#include "graphDataMatrix.h"

int main() {
    int graphDim;
    std::cout << "Square Matrix Graph Dimension : ", std::cin >> graphDim;

    int **graphMatrix;
    graphMatrix = getGraphMatrix(graphDim);
    printGraphMatrix(graphMatrix, graphDim);

    return 0;
}

