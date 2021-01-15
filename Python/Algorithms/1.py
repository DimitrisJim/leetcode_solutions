class Solution:
    def twoSum(self, nums, k):
        seen = {}
        for idx, num in enumerate(nums):
            if (idx2 := seen.get(k-num)) is not None:
                return [idx, idx2]
            seen[num] = idx
