import numpy as np

a = ["mislav", "stanko", "mislav", "ana"]
b = ["stanko", "ana", "mislav"]


def solution(participant, completion):
    import numpy as np
    participant_np = np.array(participant)
    completion_np = np.array(completion)
    remain = np.setdiff1d(completion_np, participant_np)

    print(remain)

    answer = ''
    return remain[0]

print(solution(a, b))