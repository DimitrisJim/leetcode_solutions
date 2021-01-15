class Solution:
    def maxScore(self, s):
        l, end = 1, len(s) - 1
        max_ = s.count('1') + (-1 if s[0] == '1' else 1)
        tmp = max_
        while l < end:
            tmp = tmp + (1 if s[l] == '0' else -1)
            if tmp > max_:
                max_ = tmp
            l = l + 1
        return max_
