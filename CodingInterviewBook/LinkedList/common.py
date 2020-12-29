
class linked_list_node:
    def __init__(self, value):
        self.val = value
        self.next = None



def linked_list():
    input_value = input()
    root = None

    while input_value != "!":
        if not root:
            root = linked_list_node(input_value)
            temp = root
        else:
            temp.next = linked_list_node(input_value)
            temp = temp.next

        input_value = input()

    return root