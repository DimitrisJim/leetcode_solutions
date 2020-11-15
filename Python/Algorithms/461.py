class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        xor, count = x ^ y, 0
        while xor:
            if xor & 1:
                count = count + 1
            xor = xor >> 1
        return count
