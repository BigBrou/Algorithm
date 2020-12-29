
graph = {
    1: [2, 3, 4],
    2: [5],
    3: [5],
    4: [],
    5: [6, 7],
    6: [],
    7: [3]
}

def bfs(graph, vertex):
    queue = list()
    explored_list = list()

    queue.append(vertex)
    while queue:
        v = queue.pop(0)

        if v not in explored_list:
            explored_list.append(v)

            for edge in graph[v]:
                queue.append(edge)

    return explored_list


print(bfs(graph, 1))