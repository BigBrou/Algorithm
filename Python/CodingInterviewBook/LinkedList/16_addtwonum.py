from CodingInterviewBook.LinkedList.common import linked_list
from CodingInterviewBook.LinkedList.common import linked_list_node

def read_total_value(root):
    node = root
    str = ''
    while node:
        str += node.val
        node = node.next

    return int(str[::-1])


if __name__ == "__main__":
    num_1 = linked_list() # 2 4 3 !
    num_2 = linked_list() # 5 6 4 !

    str_num_1 = read_total_value(num_1)
    str_num_2 = read_total_value(num_2)

    print(str_num_1)
    print(str_num_2)

    str_num_3 = str(str_num_1 + str_num_2)[::-1]
    print(str_num_3)

    root = None
    for idx in range(len(str_num_3)):
        node = linked_list_node(int(str_num_3[idx]))
        if not root:
            root = node
            temp_node = node
        else:
            temp_node.next = node
            temp_node = temp_node.next

    while root:
        print(root.val)
        root = root.next

