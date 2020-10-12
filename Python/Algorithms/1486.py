from functools import reduce
from operator import xor


class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        # basically hiding the loop, see C for the more 
        # sensible and readable approach.
        return reduce(xor, (start + 2*i for i in range(n)))
