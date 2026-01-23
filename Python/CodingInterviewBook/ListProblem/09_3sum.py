# 세 개의 수를 활용하여 합을 0으로 만들 수 있는 것을 출력
'''
1. 먼저 정렬을 수행한다.
2. 두 포인터를 양 끝단에서 부터 시작하여 더했을 때 크고, 작음에 대해서 비교하고 이를 토대로 다음 포인터의 값을 선택
'''

from typing import List, Tuple
import collections

def sum_of_digits(num_list: List, target: int) -> List:
    num_list.sort()
    num_dict = collections.Counter(num_list)
    target_list = list()

    front_p = 0
    rear_p = len(num_list) - 1

    while (rear_p - front_p) >= 2:
        small_value = num_list[front_p]
        large_value = num_list[rear_p]

        sub_sum = small_value + large_value

        if sub_sum <= target:
            target_num = target - sub_sum
            if target_num in num_dict.keys():
                made = [small_value, target_num, large_value]
                if collections.Counter(made)[target_num] <= num_dict[target_num]:
                    target_list.append(made)
            front_p += 1

        elif sub_sum > target:
            target_num = sub_sum - target
            if target_num in num_dict.keys():
                made = [small_value, target_num, large_value]
                if collections.Counter(made)[target_num] <= num_dict[target_num]:
                    target_list.append(made)
            rear_p -= 1

    final_list = list(set([tuple(key) for key in target_list]))
    final_list = [list(key) for key in final_list]

    return final_list



nums = [-1, 0, 1, 2, -1, -4]
target = 0

result = sum_of_digits(nums, target)

print(result)



