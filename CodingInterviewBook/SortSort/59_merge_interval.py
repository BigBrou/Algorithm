from typing import List

'''
1. arr_list 를 정렬
2. 순차적으로 돌면서 O(n)으로 값 merge
'''


def merge_arr(arr_list: List) -> List:
    new_merged_list = list()

    arr_list.sort(key=lambda x: x[0])
    temp_value = arr_list[0]

    for arr_value in arr_list:
        if (arr_value[0] >= temp_value[0]) and (arr_value[0] <= temp_value[1]):
            temp_value[1] = max([arr_value[1], temp_value[1]])
        else:
            new_merged_list.append(temp_value)
            temp_value = arr_value
    new_merged_list.append(temp_value)

    return new_merged_list


input_data_1 = [[1, 3], [2, 6], [8, 10], [15, 18]]

result_1 = merge_arr(input_data_1)
print(result_1)
