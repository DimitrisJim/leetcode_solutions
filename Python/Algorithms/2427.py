class Solution:
    def commonFactors(self, a: int, b: int) -> int:
        if a == 1 or b == 1:
            return 1
        # always count 1 as a factor
        factors = 1
        min_, max_ = (a, b) if a < b else (b, a)
        if max_ % min_ == 0:
            factors += 1
        for i in range(2, (min_ // 2) + 1):
            if min_ % i == 0 and max_ % i == 0:
                factors += 1
        return factors