
graph = {
    1: [2, 3, 4],
    2: [5],
    3: [5],
    4: [],
    5: [6, 7],
    6: [],
    7: [3]
}

def dfs_recursion(v, discovered=[]):
    discovered.append(v)

    for w in graph[v]:
        if not w in discovered:
            discovered = dfs_recursion(w, discovered)
            print(discovered)

    return discovered


def dfs_stack(graph, v):
    stack_list = []
    explored_list = []

    stack_list.append(v)

    while stack_list:
        vertex = stack_list.pop()
        if vertex not in explored_list:
            explored_list.append(vertex)

            for new_vertex in graph[vertex]:
                stack_list.append(new_vertex)

    return explored_list


discovered_list = list()
dfs_recursion(1, discovered_list)

#print(dfs_stack(graph, 1))
