
def solution_with_counter(jewel, stone):
    import collections

    jewel_counter = collections.Counter(S)
    test_counter_in_list = collections.Counter([1, 2, 3, 3, 2, 5, 6])
    count = 0

    for char in jewel:
        count += jewel_counter[char]

    return count


def solution(jewel, stone):
    jewel_dict = dict()

    for idx in range(len(jewel)):
        if jewel[idx] not in jewel_dict:
            jewel_dict[jewel[idx]] = 0

    total_jewel = 0
    for idx in range(len(stone)):
        if stone[idx] in jewel_dict:
            total_jewel += 1
            #jewel_dict[stone[idx]] += 1

    return total_jewel


if __name__ == "__main__":
    J = "aA"
    S = "aAAbbbb"

    total_jewel = solution(J, S)
    print(total_jewel)

    total_jewel = solution_with_counter(J, S)
    print(total_jewel)

