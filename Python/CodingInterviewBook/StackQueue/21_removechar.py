'''
중복된 문자열 제거하고 사전식 순서로 나열

solution
    1. start from rear to front
    2. if same alphabet in extracted words, compare data and decide which one to be erased
'''
from typing import List

# failed
# def make_lexicographical_order(data_str: str) -> str:
#     lexicographical_str = ''
#
#     for idx in reversed(range(len(data_str))):
#         word = data_str[idx]
#
#         if word in list(lexicographical_str):
#             temp_str = word + lexicographical_str
#             if temp_str < lexicographical_str:
#                 lexicographical_str = lexicographical_str.replace(word, '')
#             else:
#                 continue
#
#         lexicographical_str = word + lexicographical_str
#
#     return lexicographical_str

def make_lexicographical_order(data_str: str) -> str:
    word_list = list(data_str)
    reverse_order = sorted(list(set(word_list)), reverse=True)

    for word in reverse_order:
        word_indices = [idx for idx, w in enumerate(word_list) if word == w]
        if len(word_indices) <= 1:
            continue

        extracted_list = list()
        for idx in word_indices:
            erased_front = ''.join(word_list[:idx]).replace(word, '')
            erased_rear = ''.join(word_list[idx+1:]).replace(word, '')
            erased_str = erased_front + word + erased_rear
            extracted_list.append(erased_str)

        word_list = sorted(extracted_list)[0]

    lexicographical_str = ''.join(word_list)

    return lexicographical_str


input_data = "bcabc" # abc
input_data_2 = "cbacdcbc" # acdb
input_data_3 = "abacb" # abc

result_1 = make_lexicographical_order(input_data)
result_2 = make_lexicographical_order(input_data_2)
result_3 = make_lexicographical_order(input_data_3)

print(result_1)
print(result_2)
print(result_3)

'''
output
'abc'
'acdb'
'abc'
'''