from math import gcd

class Solution:
    def findGCD(self, nums: List[int]) -> int:
        min_, max_ = 1001, 0
        for v in nums:
            if v > max_:
                max_ = v
            if v < min_:
                min_ = v
        return gcd(max_, min_)