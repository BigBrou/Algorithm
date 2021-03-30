def find_two_sum(numbers, target_sum):
    """
    :param numbers: (list of ints) The list of numbers.
    :param target_sum: (int) The required target sum.
    :returns: (a tuple of 2 ints) The indices of the two elements whose sum is equal to target_sum
    """
    number_dict = dict()
    for idx, num in enumerate(numbers):
        number_dict[num] = idx

    indices = None
    for num, index in number_dict.items():
        target_num = target_sum - num
        if (target_num in number_dict) and (target_num != num):
            indices = (index, number_dict[target_num])

    return indices


if __name__ == "__main__":
    #print(find_two_sum([3, 1, 5, 7, 5, 9], 0))
    print(find_two_sum([0, 0, 0, 0, 0, 0], 10))