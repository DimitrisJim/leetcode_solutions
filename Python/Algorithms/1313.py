from itertools import repeat


class DList:
    """ Another attempt at trying to 
    reduce memory. Doesn't work. """
    def __init__(self, l):
        self._d = l

    def __iter__(self):
        d = self._d
        for i in range(0, len(d), 2):
            for j in range(d[i]):
                yield d[i+1]

    def __getitem__(self, i):
        d = self._d
        for ind, j in enumerate(d):
            if ind == i:
                return j
        raise IndexError("Whoops")

    def __repr__(self):
        return repr(list(self))


def yield_sublist(nums):
    for i in range(0, len(nums), 2):
        yield from repeat(nums[i+1], nums[i])

class Solution(object):
    def decompressRLElist(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        """
        # basically repeat in here manually.
        l = len(nums)
        k = 0
        fr, el = nums[0], nums[1]
        res = []
        while True:
            if fr == 0:
                k += 2
                if k >= l:
                    break
                fr, el = nums[k], nums[k+1]
            else:
                res.append(el)
                fr -= 1
        return res
        """
        """
        # repeat with extend and reusing list.
        nums_len = len(nums)
        for i in range(0, nums_len, 2):
            nums.extend(repeat(nums[i+1], nums[i]))
        return nums[nums_len:]
        """
        # yield from a generator that yields from repeat's
        return [i for i in yield_sublist(nums)]
