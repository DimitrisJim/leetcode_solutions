class Solution:
    def threeConsecutiveOdds(self, arr):
        count = 0
        for i in arr:
            count = (count + 1) if i & 1 else 0
            if count == 3:
                return True
