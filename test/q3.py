import collections

Node = collections.namedtuple('Node', ['left', 'right', 'value'])


def contains(root, value):
    if root == None:
        return False
    if root.value == value:
        return True

    if root.value < value:
        result = contains(root.right, value)
    elif root.value > value:
        result = contains(root.left, value)

    return result


n1 = Node(value=1, left=None, right=None)
n3 = Node(value=3, left=None, right=None)
n2 = Node(value=2, left=n1, right=n3)

print(contains(n2, 3))