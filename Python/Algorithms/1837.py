class Solution:
    def sumBase(self, n: int, k: int) -> int:
        s = 0
        while n >= k:
            n, r = divmod(n, k)
            s += r
        return s + n
