clothes1 = [['yellow_hat', 'headgear'], ['blue_sunglasses', 'eyewear'], ['green_turban', 'headgear']]
clothes2 = [['crow_mask', 'face'], ['blue_sunglasses', 'face'], ['smoky_makeup', 'face']]

def solution(clothes):
    clothes_dict = dict()
    clothes_list = list()

    # arrange clothes
    for idx in range(len(clothes)):
        clothes_each = clothes[idx][0]
        clothes_category = clothes[idx][-1]

        if clothes_category not in clothes_dict:
            clothes_dict[clothes_category] = [clothes_each]
            clothes_list.append(clothes_category)
        else:
            if clothes_each not in clothes_dict[clothes_category]:
                clothes_dict[clothes_category].append(clothes_each)

    # check clothes category count
    total_clothes_count_list = list()

    for idx in range(len(clothes_list)):
        clothes_category = clothes_list[idx]
        clothes_category_count = len(clothes_dict[clothes_category])

        total_clothes_count_list.append(clothes_category_count)

    # combinations
    total_combinations = 1

    for count in total_clothes_count_list:
        total_combinations *= (count + 1)

    total_combinations = total_combinations -1
    return total_combinations

print(solution(clothes1))
print(solution(clothes2))