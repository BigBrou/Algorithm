from typing import List

nums = [2, 7, 11, 15]
target = 9

# [0, 1]

def solution(nums: List[int]) -> List[int]:
    nums_dict = dict()
    index_list = list()

    for idx, num in enumerate(nums):
        nums_dict[num] = idx

    for num in nums:
        if target - num in nums_dict:
            index_list.append(nums_dict[num])
            index_list.append(nums_dict[target - num])
            break

    return index_list

index_list = solution(nums)
print(index_list)