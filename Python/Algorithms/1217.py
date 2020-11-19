class Solution:
    def minCostToMoveChips(self, positions):
        odds = sum(i % 2 for i in positions)
        evens = len(positions) - odds
        return evens if evens < odds else odds
