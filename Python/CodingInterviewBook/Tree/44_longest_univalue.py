from CodingInterviewBook.Tree.common import tree_node, make_tree

from collections import deque

# fail need to modify
def check_longest_univalue_path(root):
    max_value = [0]

    def dfs(node):
        if node == None:
            return 0

        left_value = dfs(node.left)
        right_value = dfs(node.right)

        if node.left and node.value == node.left.value:
            left_value += 1
        else:
            left_value = 0
        if node.right and node.value == node.right.value:
            right_value += 1
        else:
            right_value = 0

        # if left_value >= right_value:
        #     value = left_value
        # else:
        #     value = right_value
        value = left_value + right_value

        if max_value[0] < value:
            max_value[0] = value

        return value

    dfs(root)
    return max_value[0]


if __name__ == "__main__":
    input_1 = [5, 4, 5, 1, 1, 5]
    input_2 = [1, 4, 5, 4, 4, 5]

    input_1_tree = make_tree(input_1)
    input_2_tree = make_tree(input_2)

    path_1 = check_longest_univalue_path(input_1_tree)
    path_2 = check_longest_univalue_path(input_2_tree)

    print(path_1)
    print(path_2)