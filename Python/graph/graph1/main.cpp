#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

#include "graphAlg.h"

int main() {
    int nodes, edges;
    std::cin >> nodes >> edges;

    std::vector<int> graph[nodes];

    bool check[nodes];
    std::fill(check, check + nodes, false);

    for (int idx = 0; idx < edges; idx++) {
        int node1, node2;
        std::cin >> node1 >> node2;

        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    for (int idx = 0; idx < nodes; idx++) {
        std::sort(graph[idx].begin(), graph[idx].end());
    }

    int start = 0;
    bfs(start, graph, check);



    return 0;
}
