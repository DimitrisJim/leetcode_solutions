from math import log, isclose


class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if (n & 1 or n <= 0) and n != 1:
            return False
        res = log(n, 4)
        return isclose(round(res), res)
