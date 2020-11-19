class Solution:
    def heightChecker(self, heights): 
        target = sorted(heights)
        return sum(target[i] != heights[i] for i in range(len(heights)))
