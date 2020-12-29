# 가장 쉽게 생각하는 방법은 양 side 에 존재하는 데이터를 매핑하면서 같은지 틀린지 확인하는 것이다
# 짝수일때나 홀수일때나 매핑은 동일
# 여기서는 Linked List 를 사용한다.

from CodingInterviewBook.LinkedList.common import linked_list_node

def is_palindrome(root: linked_list_node):
    if not root:
        return True

    temp_list = list()
    node = root

    while node is not None:
        temp_list.append(node.val)
        node = node.next

    check_idx = int(len(temp_list) / 2)

    while check_idx != 0:
        check_idx -= 1

        if temp_list.pop(0) != temp_list.pop():
            return False

    return True


# method without linked_list
def is_palindrome_normal(input_list):
    if not input_list:
        return True

    check_idx = int(len(input_list) / 2)
    front_idx = 0
    rear_idx = len(input_list) - 1

    result = True

    while check_idx != 0:
        check_idx -= 1

        if input_list[front_idx] != input_list[rear_idx]:
            result = False
            break
        else:
            front_idx += 1
            rear_idx -= 1

    print(result)
    return result


input_val = input('to quit = !')
node = None

while input_val != '!':
    if node is None:
        node = linked_list_node(int(input_val))
        root = node
    else:
        temp_node = linked_list_node(int(input_val))
        node.next = temp_node

        node = temp_node

    input_val = input()


print(is_palindrome(root))



