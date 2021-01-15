class tree_node:
    def __init__(self, value):
        self._value = value
        self._left = None
        self._right = None

    @property
    def value(self):
        return self._value

    @property
    def left(self):
        return self._left

    @left.setter
    def left(self, node):
        self._left = node

    @property
    def right(self):
        return self._right

    @right.setter
    def right(self, node):
        self._right = node


def make_tree(tree_list):
    tree_class_list = list()

    for value in tree_list:
        node = tree_node(value)
        tree_class_list.append(node)

    for idx, node in enumerate(tree_class_list):
        left_index = 2 * idx + 1
        right_index = 2 * idx + 2

        if left_index < len(tree_list):
            node.left = tree_class_list[left_index]
        if right_index < len(tree_list):
            node.right = tree_class_list[right_index]

    return tree_class_list[0]
