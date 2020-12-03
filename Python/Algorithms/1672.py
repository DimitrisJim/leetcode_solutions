class Solution:
    def maximumWealth(self, accounts):
        return max(map(sum, accounts))
