class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        min_, abs_ = len(nums), abs
        for idx, num in enumerate(nums):
            if num == target:
                min_ = min(min_, abs(start - idx))
        return min_
