from collections import Counter

class Solution:
    def makeEqual(self, words) -> bool:
        # can use a char array.
        l = len(words)
        if l <= 1:
            return True
        c = Counter("".join(words))
        return all(v % l == 0 for v in c.values())