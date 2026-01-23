#ifndef GRAPH1_GRAPHALG_H
#define GRAPH1_GRAPHALG_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

void dfs_recursion(int start, std::vector<int> graph[], bool check[]) {
    check[start] = true;
    std::cout << start;

    for (int idx = 0; idx < graph[start].size(); idx++) {
        int next = graph[start][idx];

        if (check[next] == false){
            dfs_recursion(next, graph, check);
        }
    }
}

void dfs(int start, std::vector<int> graph[], bool check[]) {
    check[start] = true;
    std::cout << start << " ";

    std::stack<int> graphStack;
    graphStack.push(start);

    while (graphStack.empty() == false) {
        int stackValue = graphStack.top();
        graphStack.pop();

        for (int idx = 0; idx < graph[stackValue].size(); idx++) {
            int nextValue = graph[stackValue][idx];

            if (check[nextValue] == false) {
                graphStack.push(stackValue);
                graphStack.push(nextValue);
                std::cout << nextValue << " ";

                check[nextValue] = true;
                break;
            }
        }
    }

    std::cout << "dfs done" << std::endl;
}

void bfs(int start, std::vector<int> graph[], bool check[]) {
    check[start] = true;
    std::cout << start << " ";

    std::queue<int> graphQueue;
    graphQueue.push(start);

    while (graphQueue.empty() == false) {
        int queueValue = graphQueue.back();

        for (int idx = 0; idx < graph[queueValue].size(); idx++) {
            int nextValue = graph[queueValue][idx];

            if (check[nextValue] == false) {
                graphQueue.push(nextValue);
                std::cout << nextValue << " ";

                check[nextValue] = true;
            }
        }
        graphQueue.pop();
    }


}

#endif //GRAPH1_GRAPHALG_H
