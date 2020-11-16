from collections import Counter

# 14.2 79.93
class Solution:

    # 64 99.47
    def canBeEqual(self, target, arr):
        target.sort()
        arr.sort()
        return all(i == j for i, j in zip(target, arr))

    def canBeEqual2(self, target, arr):
        return Counter(target) == Counter(arr)
