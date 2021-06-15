class Solution:
    def isCovered(self, ranges: List[List[int]], left: int, right: int) -> bool:
        # note: could also do with set ops.
        ranges.sort(key=itemgetter(1))
        i, length = 0, len(ranges)
        while left <= right and i < length:
            l, r = ranges[i]
            if l <= left <= r:
                left = r + 1
            if l <= right <= r:
                right = l - 1
            i += 1
        return left > right
