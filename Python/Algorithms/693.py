class Solution:
    def hasAlternatingBits(self, n):
        while n:
            b = n & 1
            n = n >> 1
            if b == (n & 1):
                return False
        return True
