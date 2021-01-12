
def enumerate_sum(candidate, target):
    total_candidates_list = list()

    # 1. setting the graph
    candidates_graph = dict()
    for idx in range(len(candidate)):
        data = candidate[idx]
        candidates_graph[data] = candidate[idx:]

    print(candidates_graph)


    def dfs(vertex, candidates_list):
        selected_node = candidates_graph[vertex][0]
        candidates_list.append(selected_node)

        if sum(candidates_list) > target:
            return
        elif sum(candidates_list) == target:
            total_candidates_list.append(candidates_list)
        else:
            for idx in candidates_graph[selected_node]:
                dfs(idx, candidates_list[:])

    for idx in range(len(candidate)):
        dfs(candidate[idx], [])

    return total_candidates_list


if __name__== "__main__":
    candidates = [2, 3, 6, 7]
    target = 7

    candidates2 = [2, 3, 5]
    target2 = 8

    print(enumerate_sum(candidates2, target2))