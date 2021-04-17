from math import log, isclose


class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        # Nice observation, powers of three are all odd.
        if n & 1 == 0 or n <= 0:
            return False
        res = log(n, 3)
        return isclose(round(res), res)
