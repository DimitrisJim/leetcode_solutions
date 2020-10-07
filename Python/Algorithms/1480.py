from typing import List


class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        """ Find running sum of 1-d array. Theta(n) complexity
        for all cases."""
        res = []
        # hold running sum and add on the fly.
        running_sum = 0
        for num in nums:
            running_sum += num
            res.append(running_sum)
        return res
