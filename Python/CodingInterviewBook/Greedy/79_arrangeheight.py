import heapq

# [height, taller_count]
people = [[7, 0], [4, 4], [7, 1], [5, 0], [6, 1], [5, 2]]


def arrange_height(people):
    heap = []

    for person in people:
        heapq.heappush(heap, (-person[0], person[1]))

    result = []
    while heap:
        person = heapq.heappop(heap)
        result.insert(person[1], [-person[0], person[1]])
    return result


res = arrange_height(people)
print(res)


