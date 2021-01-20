from collections import Counter


class Solution:
    def findShortestSubArray(self, nums):
        # Find max degree and which elements of nums share
        # that degree.
        max_deg, max_items, length = -1, [], len(nums) - 1
        for i, j in Counter(nums).most_common():
            if max_deg == -1:
                # max degree == 1 means we only have singles.
                if j == 1:
                    return 1
                max_deg = j
            if j != max_deg:
                break
            max_items.append(i)

        # go from left end and right end and find
        # leftmost & rightmost occurence of item
        # in max_items
        min_len = length + 1
        for i in max_items:
            start, end = 0, length
            while start < end:
                s, e = nums[start], nums[end]
                if s != i:
                    start = start + 1
                if e != i:
                    end = end - 1
                # We found leftmost + rightmost.
                if s == e == i:
                    l = end - start + 1
                    # they are clumped together
                    if l == max_deg:
                        return l
                    if l < min_len:
                        min_len = l
                    break
        return min_len
