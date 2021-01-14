class Solution:
    # not O(1) space
    def findDisappearedNumbers(self, nums):
        s = {*range(1, len(nums) + 1)}
        remove = s.remove
        for i in nums:
            if i in s:
                remove(i)
        return [*s]
