class Solution:
    def maxSubArray(self, nums):
        maximum, prev, max_ = nums[0], 0, max
        for num in nums:
            prev = max_(num, num + prev)
            maximum = max_(prev, maximum)
        return maximum
