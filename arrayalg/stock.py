from typing import List

stock_list = [7, 1, 5, 3, 6, 4]
#result = 5


def solution(stock_list: List[int]) -> int:
    left_idx = 0
    right_idx = len(stock_list) - 1

    min_value = stock_list[left_idx]
    max_value = stock_list[right_idx]

    while left_idx < right_idx:
        if min_value > stock_list[left_idx]:
            min_value = stock_list[left_idx]
        left_idx += 1

        if max_value < stock_list[right_idx]:
            max_value = stock_list[right_idx]
        right_idx -= 1

    return max_value - min_value

print(solution(stock_list))