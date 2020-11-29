class Solution:
    def sortByBits(self, arr):
        def numberOfSetBits(i):
            i = i - ((i >> 1) & 0x55555555)
            i = (i & 0x33333333) + ((i >> 2) & 0x33333333)
            return (((i + (i >> 4) & 0xF0F0F0F) * 0x1010101) & 0xffffffff) >> 24

        # sort is stable.
        arr.sort()
        arr.sort(key=lambda x: numberOfSetBits(x))
        return arr
