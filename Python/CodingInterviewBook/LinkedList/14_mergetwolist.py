# merge 1->2->4, 1->3->4

from CodingInterviewBook.LinkedList.common import linked_list_node

def merge_two_list(root_1, root_2):
    p_1 = root_1
    p_2 = root_2

    while (p_1) and (p_2):
        if p_1.val <= p_2.val:
            temp_p = p_1.next
            p_1.next = p_2
            p_2 = p_2.next
            p_1.next.next = temp_p
            p_1 = p_1.next.next
        else:
            temp_p = p_2.next
            p_2.next = p_1
            p_1 = p_1.next
            p_2.next.next = temp_p
            p_2 = p_2.next.next

    if p_1:
        root = root_1
    else:
        root = root_2

    node = root_1
    while node:
        print(node.val)
        node = node.next


if __name__ == "__main__":
    # make 1->2->4
    root_1 = linked_list_node(1)
    node_f1 = linked_list_node(2)
    node_f2 = linked_list_node(4)

    root_1.next = node_f1
    node_f1.next = node_f2

    # make 1->3->4
    root_2 = linked_list_node(1)
    node_s1 = linked_list_node(3)
    node_s2 = linked_list_node(4)

    root_2.next = node_s1
    node_s1.next = node_s2

    merge_two_list(root_1, root_2)

