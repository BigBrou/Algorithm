
def make_subsets(data_list):
    subset_list = list()

    # 1. setting the graph
    candidates_graph = dict()
    for idx in range(len(data_list)):
        data = data_list[idx]
        candidates_graph[data] = data_list[idx+1:]

    print(candidates_graph)

    # 2. dfs
    def dfs(vertex, fill_list=[]):
        copy_list = fill_list[:]
        copy_list.append(vertex)

        if copy_list not in subset_list:
            subset_list.append(copy_list)
        else:
            print('logit failed', copy_list)

        for node in candidates_graph[vertex]:
            dfs(node, copy_list)

    # 3. select root
    for data in data_list:
        dfs(data, [])

    subset_list.sort(key=len)
    return subset_list


if __name__ == '__main__':
    nums = [1, 2, 3]

    print(make_subsets(nums))