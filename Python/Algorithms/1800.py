class Solution:
    def maxAscendingSum(self, nums) -> int:
        # return early in special case.
        if len(nums) == 1:
            return nums[0]
        
        # keep track of current sum and max found so far.
        max_found = 0
        current_sum = 0
        for i in range(len(nums) - 1):
            current_sum += nums[i]
            if nums[i+1] <= nums[i]:
                # update max if current exceeds it.
                if current_sum > max_found:
                    max_found = current_sum
                current_sum = 0

        # need to check if last value contributes to 
        # current sum or not.
        if nums[-1] > nums[-2]:
            return max(max_found, current_sum + nums[-1])
        return max(max_found, nums[-1])