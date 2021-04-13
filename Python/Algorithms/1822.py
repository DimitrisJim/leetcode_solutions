class Solution:
    def arraySign(self, nums: List[int]) -> int:
        # start with an indication of positive
        res = 1
        for i in nums:
            if i == 0:
                return 0
            # if negative, toggle result (indicate negative)
            if i < 0:
                res = -res
        return res