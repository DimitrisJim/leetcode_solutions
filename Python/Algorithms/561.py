class Solution:
    def arrayPairSum(self, nums):
        nums.sort(reverse=True)
        return sum(nums[i] for i in range(1, len(nums), 2))
