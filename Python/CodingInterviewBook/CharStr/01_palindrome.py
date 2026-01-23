# 1. 알파벳, 숫자를 제외하고는 제거
# 2. 모두 알파벳을 소문자로 변환

from typing import List, Dict, Tuple, Set


def is_palindrome(str_data: str) -> bool:
    # think 1
    new_str = ''
    for idx in range(len(str_data)):
        if str_data[idx].isalnum():
            new_str += new_str.join(str_data[idx])
    print(new_str)

    # think 2
    new_str = new_str.lower()
    print(new_str)

    result = True
    # for idx in range(len(new_str) // 2):
    #     if new_str[idx] != new_str[-1 - idx]:
    #         result = False

    half_length = len(new_str) // 2
    front_str = new_str[: half_length]
    rear_str = new_str[-half_length: ]
    if front_str != ''.join(reversed(rear_str)):
        result = False

    return result


input_data = "A man, a plan, a canal: Panama"
input_data_2 = "race a car"
input_data_3 = "1a 2 3 2 a1"

result1 = is_palindrome(input_data)
result2 = is_palindrome(input_data_2)
result3 = is_palindrome(input_data_3)

print(result1)
print(result2)
print(result3)