from functools import reduce
from operator import xor


class Solution:
    def singleNumber(self, nums):
        return reduce(xor, nums)
