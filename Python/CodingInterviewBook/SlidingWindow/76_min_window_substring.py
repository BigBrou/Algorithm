
import collections
import math

# correct but time limit exceeded ha...
def minimal_window(string: str, sub_string: str) -> str:
    string_dict = collections.Counter(string)
    sub_string_dict = collections.Counter(sub_string)

    # check string covers sub_string
    for word in sub_string_dict.keys():
        if word not in string_dict:
            return ''
        if sub_string_dict[word] > string_dict[word]:
            return ''

    # check minimal window
    sub_string_list = list(sub_string)
    minimal_list = list()
    queue_idx_list = list()

    max_window_len = math.inf
    result_str = ''

    for idx, word in enumerate(string):
        if word in sub_string_list:
            minimal_list.append(word)
            queue_idx_list.append(idx)

        if collections.Counter(minimal_list)[word] > sub_string_dict[word]:
            erase_idx = minimal_list.index(word)
            del minimal_list[erase_idx]
            del queue_idx_list[erase_idx]

        temp_arrange = sorted(minimal_list)
        if temp_arrange == sorted(sub_string_list):
            window_len = max(queue_idx_list) - min(queue_idx_list) + 1
            if window_len < max_window_len:
                max_window_len = window_len
                result_str = string[min(queue_idx_list): max(queue_idx_list)+1]

            del minimal_list[0]
            del queue_idx_list[0]

    return result_str


S = "ADOBECODEBANC"
T = "ABC"

result = minimal_window(S, T)
print(result)