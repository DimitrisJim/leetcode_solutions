from itertools import chain


class Solution:
    def matrixReshape(self, nums, r, c):
        rows, cols = len(nums), len(nums[0])

        # can't fit in new row/col orientation.
        if (r * c) > (rows * cols):
            return nums

        # go through elements of nums by chaining
        it, next_ = chain.from_iterable(nums), next
        result = []
        for i in range(r):
            sub = []
            for j in range(c):
                sub.append(next_(it))
            result.append(sub)
        return result
