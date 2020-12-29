from CodingInterviewBook.LinkedList.common import linked_list_node



# 이런 식으로 뒤에 링크를 할당하는 방법으로 하게 되면, 연결은 되지만 변경된 root를 알 수가 없게 된다. fail 1
# def reverse_recursion(node, parent=None):
#
#     if node.next is None:
#          return node
#     else:
#         a = reverse_recursion(node.next, node)
#         a.next = node
#         return node

# python 의 특성상 참조의 형식으로 진행되기 때문에 line 20, 21 을 묶어서 수행하지 않으면 21 수행시 next 가 node로 변경되어 버린다. (골 때리네)
# def reverse_recursion(node, parent=None):
#     if node.next is None:
#         return node
#     else:
#         next = node.next
#         node.next = node
#         return reverse_recursion(next, node)

def reverse_recursion(node, parent=None):
    if node.next is None:
        node.next = parent
        return node

    next, node.next = node.next, parent
    return reverse_recursion(next, node)


# def reverselist(head):
#     node, prev = head, None
#
#     while node:
#         next, node.next = node.next, prev
#         prev, node = node, next


if __name__ == "__main__":
    root = linked_list_node(1)
    node_1 = linked_list_node(2)
    node_2 = linked_list_node(3)
    node_3 = linked_list_node(4)
    node_4 = linked_list_node(5)

    root.next = node_1
    node_1.next = node_2
    node_2.next = node_3
    node_3.next = node_4

    new_root = reverse_recursion(root)

    # reverselist(root)

    # print
    node = new_root
    while node:
        print(node.val)
        node = node.next
