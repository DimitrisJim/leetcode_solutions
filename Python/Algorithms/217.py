class Solution:
    def containsDuplicate(self, nums):
        s = set()
        # bail early
        for i in nums:
            if i in s:
                return True
            s.add(i)
        return False
