class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        nums.sort(key=abs, reverse=True)
        for i in range(1, len(nums)):
            if nums[i] + nums[i-1] == 0:
                return abs(nums[i])
        return -1

    def findMaxK2(self, nums: List[int]) -> int:
        seen, max_ = set(), -1
        for i in nums:
            if -i in seen:
                if abs(i) > max_:
                    max_ = abs(i)
            else:
                seen.add(i)
        return max_