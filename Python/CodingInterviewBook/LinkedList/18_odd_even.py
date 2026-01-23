'''
공간 복잡도 O(1), 시간 복잡도 O(n)
'''
from typing import List

from common import linked_list_node, linked_list_with_data

def odd_even(root: linked_list_node):

    node = root
    node2 = root.next
    odd = node
    even = node.next

    while node and node.next:
        odd.next = node.next.next
        even.next = node.next.next

        odd = odd.next
        even = even.next

        node = odd

    odd.next = node2

    while root:
        print(root.val)
        root = root.next



input_data = [1, 2, 3, 4, 5]
input_data_2 = [2, 1, 3, 5, 6, 4, 7]

root = linked_list_with_data(input_data)
root2 = linked_list_with_data(input_data_2)

#odd_even(root)
odd_even(root2)