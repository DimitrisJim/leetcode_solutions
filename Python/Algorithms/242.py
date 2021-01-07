from collections import Counter


class Solution:
    def isAnagram(self, s, t):
        return False if len(s) != len(t) else Counter(s) == Counter(t)
