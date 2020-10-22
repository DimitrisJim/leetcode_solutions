class Solution:
    def sumZero(self, n):
        l = [0] if n & 1 else []
        lapp = l.append
        for i in range(1, (n//2) + 1):
            lapp(i)
            lapp(-i)
        return l
