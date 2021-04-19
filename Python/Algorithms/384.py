from random import randint


class Solution:

    def __init__(self, nums):
        """ Always keep original around. """
        self.original = nums

    def reset(self):
        """ Resets the array to its original configuration and return it. """
        return self.original

    def shuffle(self):
        """ Returns a random shuffling of the array.
        Fisher-Yates: https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
        """
        res, rnd = self.original.copy(), randint
        length = len(res) - 1
        # range is exclusive on right end.
        for i in range(0, length):
            # randint is inclusive on right end.
            # i.e idx in [0, len(res) - 1]
            idx = rnd(i, length)
            res[idx], res[i] = res[i], res[idx]
        return res
