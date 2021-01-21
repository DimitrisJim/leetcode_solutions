class Solution:
    def search(self, nums, target):
        start, end = 0, len(nums) - 1
        while start <= end:
            idx = (start + end) // 2
            mid = nums[idx]
            if mid == target:
                return idx
            # go left
            if target < mid:
                end = idx - 1
            else:
                start = idx + 1
        return -1
