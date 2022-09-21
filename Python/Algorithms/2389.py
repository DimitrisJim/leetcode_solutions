import bisect

class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        nums.sort()
        sumnum = nums[0]
        for i in range(1, len(nums)):
            nums[i] = nums[i] + sumnum
            sumnum = nums[i]
        
        return [bisect.bisect_right(nums, q) for q in queries]