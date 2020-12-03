class Solution:
    def fib(self, N: int) -> int:
        if N == 0:
            return 0
        if N == 1 or N == 2:
            return 1
        f, fprev = 1, 1
        for i in range(N - 2):
            f, fprev = f+fprev, f
        return f
