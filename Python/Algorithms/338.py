class Solution:
    def countBits(self, n: int):
        res = [0] * (n + 1)
        for i in range(1, n+1):
            # i >> 1 will always be smaller than `i` and
            # present in the array.
            # i & 1 checks if we shifted off a zero or a one
            # (and, respectively adds 0 or 1 to the result)
            res[i] = res[i >> 1] + (i & 1)
        return res
