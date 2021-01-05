class Solution:
    def findLUSlength(self, a, b):
        return -1 if a == b else max(len(a), len(b))
