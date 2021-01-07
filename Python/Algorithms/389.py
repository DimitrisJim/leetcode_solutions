class Solution:
    def findTheDifference(self, s, t):
        # alternative
        # return (Counter(t) - Counter(s)).popitem()[0]
        x, ord_ = 0, ord
        for i in range(len(s)):
            x = x ^ ord_(s[i]) ^ ord_(t[i])
        return chr(x ^ ord_(t[-1]))
