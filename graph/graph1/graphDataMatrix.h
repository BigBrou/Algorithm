#ifndef GRAPH1_GRAPHDATAMATRIX_H
#define GRAPH1_GRAPHDATAMATRIX_H

#include <iostream>
#include <vector>

void getFixMatrix(std::vector<int *> intArr) {
    int arr[] = {0, 1, 0, 0, 1, 0};
    intArr.push_back(arr);
    int arr2[] = {1, 0, 1, 1, 1, 0};
    intArr.push_back(arr2);
    int arr3[] = {0, 1, 0, 1, 0, 0};
    intArr.push_back(arr3);
    int arr4[] = {0, 1, 1, 0, 1, 1};
    intArr.push_back(arr4);
    int arr5[] = {1, 1, 0, 1, 0, 0};
    intArr.push_back(arr5);
    int arr6[] = {0, 0, 0, 1, 0, 0};
    intArr.push_back(arr6);
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

#endif //GRAPH1_GRAPHDATAMATRIX_H
