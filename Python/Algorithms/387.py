class Solution:
    def firstUniqChar(self, s):
        c, idx = Counter(s), 0
        for i in s:
            if c[i] == 1:
                return idx
            idx = idx + 1
        return -1
