from collections import deque

from CodingInterviewBook.Tree.common import tree_node


def make_tree(tree_list):
    queue = deque()

    if not tree_list:
        return None, 0

    for value in tree_list:
        node = tree_node(value)
        queue.append(node)

    level = 0

    while queue:
        node = queue.popleft()

        if level == 0:
            root = node
            if len(queue) == 0:
                level = 1
                break
        if level == len(queue):
            break
        if level == len(queue) - 1:
            node.left = queue[level] if not queue[level].value == None else None
            break

        node.left = queue[level] if not queue[level].value == None else None
        node.right = queue[level + 1] if not queue[level].value == None else None

        level += 1

    return root, level


def tree_depth_dfs(root):
    def dfs(node):
        if not node:
            return 0

        left_value = dfs(node.left) + 1
        right_value = dfs(node.right) + 1

        if left_value >= right_value:
            value = left_value
        else:
            value = right_value

        return value

    if not root:
        depth = 0
    elif not root.left and not root.right:
        depth = 1
    else:
        depth = dfs(root)

    return depth


if __name__ == "__main__":
    tree_list = [3, 9, 20, None, None, 15, 7]

    root, depth = make_tree(tree_list)
    print(depth)

    depth = tree_depth_dfs(root)
    print(depth)