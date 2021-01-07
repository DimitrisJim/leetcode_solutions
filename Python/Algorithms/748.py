from string import ascii_letters
from collections import Counter


class Solution:
    letters = {*ascii_letters}

    def shortestCompletingWord(self, licensePlate, words):
        counter, letters = Counter, self.letters
        words.sort(key=len)
        # keep both a set and a multiset (counter).
        ms = counter(i.lower() for i in licensePlate if i in letters)
        s = set(ms)

        for i in words:
            # check subset relationship first. if that
            # succeeds, subtract multisets.
            if s <= {*i} and not ms - counter(i):
                return i
