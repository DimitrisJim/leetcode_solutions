class Solution:
    def subsets(self, nums):
        count = len(nums)
        result = [[]]
        for i in range(1, 2 ** count):
            result.append([nums[j] for j in range(count) if i & (2 ** j)])
        return result
