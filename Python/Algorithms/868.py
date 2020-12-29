class Solution:
    def binaryGap(self, n: int) -> int:
        # handle 1.
        if n < 3:
            return 0
        max_dst, count, start = 0, 0, False
        while n:
            if n & 1:
                if count > max_dst:
                    max_dst = count
                count = 1
                start = True
            else:
                if start:
                    count = count + 1
            n >>= 1
        return max_dst
