#ifndef GRAPH1_GRAPHDATAMATRIX_H
#define GRAPH1_GRAPHDATAMATRIX_H

#include <iostream>

int** getFixedGraphMatrix() {
    int matrix[6][6] = {
            {0, 1, 0, 0, 1, 0},
            {1, 0, 1, 1, 1, 0},
            {0, 1, 0, 1, 0, 0},
            {0, 1, 1, 0, 1, 1},
            {1, 1, 0, 1, 0, 0},
            {0, 0, 0, 1, 0, 0}
    };
    int graphDim = 6;

    int **graphMatrix = new int *[graphDim];

    for (int idx = 0; idx < graphDim; idx++) {
        graphMatrix[idx] = new int[graphDim];

        for (int idxsub = 0; idxsub < graphDim; idxsub++) {
            graphMatrix[idx][idxsub] = matrix[idx][idxsub];
        }
    }

    return graphMatrix;
}


int** getGraphMatrix(int graphDim) {
    int **graphMatrix = new int *[graphDim];

    for (int idx = 0; idx < graphDim; idx++) {
        graphMatrix[idx] = new int[graphDim];

        for (int idxsub = 0; idxsub < graphDim; idxsub++) {
            std::cin >> graphMatrix[idx][idxsub];
        }
    }

    return graphMatrix;
}

void printGraphMatrix(int **graphMatrix, int graphDim) {
    for (int idx = 0; idx < graphDim; idx++) {
        for (int idxsub =0; idxsub < graphDim; idxsub++) {
            std::cout << graphMatrix[idx][idxsub] << ", ";
        }
        std::cout << std::endl;
    }
}

int** executeCustomMatrix(int graphDim) {
    int **graphMatrix;

    graphMatrix = getGraphMatrix(graphDim);
    printGraphMatrix(graphMatrix, graphDim);

    return graphMatrix;
}



#endif //GRAPH1_GRAPHDATAMATRIX_H
