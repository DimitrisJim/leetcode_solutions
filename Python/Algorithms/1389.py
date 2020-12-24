class Solution:
    def createTargetArray(self, nums, index):
        target = []
        for idx, num in zip(index, nums):
            target.insert(idx, num);
        return target
