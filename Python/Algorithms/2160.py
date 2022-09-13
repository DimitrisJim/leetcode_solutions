class Solution:
    def minimumSum(self, num: int) -> int:
        digits = []
        for i in range(3, -1, -1):
            digits.append(num // (10**i))
            num %= 10**i
        digits.sort()

        min_a, min_b, c, d = digits
        return (min_a * 10 + c) + (min_b * 10 + d)