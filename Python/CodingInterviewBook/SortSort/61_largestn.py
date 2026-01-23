from typing import List

# 버블 정렬 에란데..

def make_largest_number(num_list: List[int]) -> str:
    largest_number = ''

    for idx in range(len(num_list)):
        for idxsub in range(1, len(num_list)):
            if str(num_list[idxsub-1]) + str(num_list[idxsub]) < str(num_list[idxsub]) + str(num_list[idxsub-1]):
                num_list[idxsub-1], num_list[idxsub] = num_list[idxsub], num_list[idxsub-1]

    largest_number = ''.join([str(x) for x in num_list])
    return int(largest_number)


# input_data_1 = [10, 2]
# input_data_2 = [3, 30, 34, 5, 9]
input_data_3 = [0, 0]

# result_1 = make_largest_number(input_data_1)
# result_2 = make_largest_number(input_data_2)
result_3 = make_largest_number(input_data_3)

# print(result_1)
print(result_3)