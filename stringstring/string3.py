from typing import List
from collections import defaultdict

words = ["eat", "tea", "tan", "ate", "nat", "bat"]


def solution(words: List[str]) -> List[str]:
    words_dict = defaultdict(list)

    for word in words:
        words_dict[''.join(sorted(word))].append(word)

    return words_dict.values()


word_list = solution(words)
print(word_list)


