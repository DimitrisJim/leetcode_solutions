class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        # a, b hold 1st and 2nd maxes
        a = b = 0
        # c, d hold 1st and 2nd mins
        c = d = 10 ** 4 + 1
        for num in nums:
            if num >= a:
                a, b = num, a
            elif num > b:
                b = num
            if num <= c:
                c, d = num, c
            elif num < d:
                d = num
        return a*b - c*d
