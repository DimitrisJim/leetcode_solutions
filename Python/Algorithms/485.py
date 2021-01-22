class Solution:
    def findMaxConsecutiveOnes(self, nums):
        max_, count = 0, 0
        for i in nums:
            if i:
                count = count + 1
                if count > max_:
                    max_ = count
                continue
            count = 0
        return max_
