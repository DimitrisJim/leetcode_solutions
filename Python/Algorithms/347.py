from collections import Counter


class Solution:
    def topKFrequent(self, nums, k: int):
        # most_common invokes heapq.nlargest if k <= n. As a result
        # this runs in O(nlogk).
        return [i for i, _ in Counter(nums).most_common(k)]
