class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        count = 0
        (b, s) = (start, goal) if start > goal else (goal, start)
        while s:
            if b & 1 != s & 1:
                count += 1
            b >>= 1
            s >>= 1
        while b:
            if b & 1:
                count += 1
            b >>= 1
        return count