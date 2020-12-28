from collections import Counter


class Solution:
    def maxNumberOfBalloons(self, text):
        c, s = Counter(text), "balloon"
        i = 0
        while True:
            for char in s:
                if c[char]:
                    c[char] -= 1
                else:
                    return i
            i = i + 1 
