from typing import List, Tuple, Dict, Set


def reverse_str(str_list: List):
    half_length = len(str_list) // 2
    for idx in range(half_length):
        str_list[idx], str_list[-1 - idx] = str_list[-1 - idx], str_list[idx]


input_data_1 = ['h', 'e', 'l', 'l', 'o']
input_data_2 = ['h', 'a', 'n', 'n', 'a', 'H']

reverse_str(input_data_1)
reverse_str(input_data_2)

print(input_data_1)
print(input_data_2)