class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        length, total = len(nums), 0
        for k in range(1, 1 << length):
            subtotal = 0
            # View subsequences as bitstrings where bit set
            # indicates we should pick a specific index.
            # We essentially generate the following sequence:
            #
            # 0, 01, 10, 11, 001, 010, 100, 011, 101, 110, 111
            #
            # and use that to index into the array (via k & (1 << i))
            # which checks if the the i'th bit is set.
            for i in range(length):
                if k & (1 << i):
                    subtotal ^= nums[i]
            total += subtotal
        return total
