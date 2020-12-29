


def solution(str):
    alphabet_dict = dict()

    str_len = len(str)
    final_sub_length = 0

    for idx in range(str_len):
        if str[idx] not in alphabet_dict:
            alphabet_dict[str[idx]] = idx
        else:
            sub_length = idx - alphabet_dict[str[idx]]
            alphabet_dict[str[idx]] = idx
            if sub_length > final_sub_length:
                final_sub_length = sub_length

    return final_sub_length


if __name__ == "__main__":
    str_1 = "abcabcbb"
    str_2 = "bbbbb"
    str_3 = "pwwkew"

    count_1 = solution(str_1)
    count_2 = solution(str_2)
    count_3 = solution(str_3)

    print(count_1)
    print(count_2)
    print(count_3)