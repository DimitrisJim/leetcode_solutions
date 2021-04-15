class Solution:
    def findMaxAverage(self, nums, k: int) -> float:
        # Avoid computations by working with a window of 1. We find the
        # average of k-1 elements and add/remove values from the ends.
        limit = k-1
        start, max_avg = sum(nums[:limit]) / k, -(10 << 30)
        for i in range(limit, len(nums)):
            final_value = nums[i] / k
            candidate = start + final_value
            if candidate > max_avg:
                max_avg = candidate

            # remove first term of sum and add final
            start += (final_value - nums[i - limit] / k)
        return max_avg
