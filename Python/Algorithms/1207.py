from collections import Counter


class Solution:
    def uniqueOccurrences(self, arr):
        counts = Counter(arr)
        return len(counts) == len(set(counts.values()))
