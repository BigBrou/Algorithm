from collections import defaultdict, Counter

paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]

def solution(paragraph: str) -> str:
    words_dict = defaultdict(int)

    words_list = [word.lower() for word in paragraph.replace('.', '').replace(',', '').split()
                  if word not in banned]

    for word in words_list:
        words_dict[word] += 1

    words_counter = Counter(words_dict)
    words_counter_reorder = words_counter.most_common(1) # ordering list
    max_word = words_counter_reorder[0][0]

    return max_word


word = solution(paragraph)
print(word)

