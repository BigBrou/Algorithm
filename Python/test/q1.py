class Song:
    def __init__(self, name):
        self.name = name
        self.next = None
        self.next_play_dict = dict()

    def next_song(self, song):
        self.next = song
        

    def is_repeating_playlist(self):
        result = False

        my_name = self.name

        next_obj = self.next
        while next_obj != None:
            if my_name == next_obj.name:
                result = True
                break
            next_obj = next_obj.next

        return result




first = Song("Hello")
second = Song("Eye of the tiger")

first.next_song(second)
second.next_song(first)

print(first.is_repeating_playlist())