from typing import List

logs = ["dig1 8 1 5 1", "let1 art can", "dig2 3 6", "let2 own kit dig", "let3 art zero"]


def reorder_log_files(logs: List[str]) -> List[str]:
    letters = list()
    digits = list()

    for str in logs:
        if str.split()[1].isdigit():
            digits.append(str)
        else:
            letters.append(str)

    letters.sort(key=lambda x: (x.split()[1:], x.split()[0]))
    return letters + digits


result = reorder_log_files(logs)
print(result)
