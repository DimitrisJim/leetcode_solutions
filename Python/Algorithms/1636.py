from operator import itemgetter
from collections import Counter


class Solution:
    def frequencySort(self, nums):
        sort = sorted
        val, freq = itemgetter(0), itemgetter(1)
        res, freqs = [], Counter(nums).items()
        for i, j in reversed(sort(sort(freqs, key=val), key=freq, reverse=True)):
            res.extend([i] * j)
        return res
