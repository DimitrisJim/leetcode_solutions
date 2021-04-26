class Solution:
    def minOperations(self, nums) -> int:
        if len(nums) < 2:
            return 0

        inc = 0
        for i in range(1, len(nums)):
            a, b = nums[i-1], nums[i]
            if a == b:
                inc += 1
                nums[i] += 1
            elif a > b:
                diff = (a - b) + 1
                inc += diff
                nums[i] += diff
        return inc
