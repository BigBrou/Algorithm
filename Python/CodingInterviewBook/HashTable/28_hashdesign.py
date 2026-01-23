import collections

class list_node:
    def __init__(self, key=None, value=None):
        self.key = key
        self.value = value
        self.next = None


class my_hash_map:
    def __init__(self):
        self.size = 1000
        self.table = collections.defaultdict(list_node)

    def put(self, key, value):
        index = key % self.size

        if self.table[index].value is None:
            self.table[index] = list_node(key, value)
            return

        hash_root = self.table[index]
        while hash_root:
            if hash_root.key == key:
                hash_root.value = value #?
                return

            if hash_root.next == None:
                a = list_node(key, value)
                hash_root.next = a
                return

            hash_root = hash_root.next


    def get(self, key):
        index = key % self.size
        if self.table[index].value is None:
            return -1

        hash_root = self.table[index]
        while hash_root:
            if hash_root.key == key:
                return hash_root.value

            hash_root = hash_root.next

        return -1


    def remove(self, key):
        index = key % self.size
        if self.table[index].value is None:
            return

        hash_root = self.table[index]
        if hash_root.key == key:
            self.table[index] = list_node() if hash_root is None else hash_root.next
            return

        prev = hash_root
        while hash_root:
            if hash_root.key == key:
                prev.next = hash_root.next
                return
            prev, hash_root = hash_root, hash_root.next


if __name__ == "__main__":
    hash_map = my_hash_map()
    hash_map.put(1, 1)
    hash_map.put(2, 2)

    print(hash_map.get(1))
    print(hash_map.get(3))

    hash_map.put(2, 1)
    print(hash_map.get(2))

    hash_map.remove(2)
    # print(hash_map.get(2)) ? Error???



