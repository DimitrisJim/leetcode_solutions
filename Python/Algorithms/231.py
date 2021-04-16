from math import log2


class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        return n > 0 and log2(n).is_integer()
