class Solution:
    def tribonacci(self, n):
        a, b, c = 0, 1, 1
        for i in range(n - 2):
            a, b, c = b, c, a + b + c
        # take care of n == 0 case.
        return c if n else 0
