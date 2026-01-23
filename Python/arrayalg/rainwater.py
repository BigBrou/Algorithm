from typing import List

list_input = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]

def solution(list_input: List[int]) -> int:
    if not list_input:
        return 0

    rain_count = 0
    left, right = 0, len(list_input) - 1
    left_max, right_max = list_input[left], list_input[right]

    while left < right:
        left_max = max(list_input[left], left_max)
        right_max = max(list_input[right], right_max)

        if left_max < right_max:
            rain_count += left_max - list_input[left]
            left += 1
        else:
            rain_count += right_max - list_input[right]
            right -= 1

    print(rain_count)
    return rain_count


def trap(list_input: List[int]) -> int:
    stack = []
    rain_count = 0

    for idx in range(len(list_input)):
        while stack and list_input[idx] > list_input[stack[-1]]:
            top = stack.pop()

            if not len(stack):
                break

            distance = idx - stack[-1] - 1
            rain = min(list_input[idx], list_input[stack[-1]]) - list_input[top]

            rain_count += distance * rain

        stack.append(idx)

    print(rain_count)
    return rain_count


trap(list_input)

solution(list_input)