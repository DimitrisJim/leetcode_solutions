class Solution:
    def minSubsequence(self, nums):
        # Go through the list backwards.
        nums.sort(reverse=True)
        # Keep track of what's left, where we're at.
        left_sum, seq = sum(nums), 0

        # Continuously increase seq and decrease left_sum
        # until we reach point were seq > left_sum
        for i in range(len(nums)):
            v = nums[i]
            seq = seq + v
            left_sum = left_sum - v
            if (seq - left_sum) > 0:
                # done, return subsequence.
                return nums[:i+1]
