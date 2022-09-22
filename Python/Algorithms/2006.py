from collections import Counter

class Solution:
    def countKDifference(self, nums: List[int], k: int) -> int:
        c, count = Counter(nums), 0
        for i in nums:
            a, b = i - k, i + k
            if a in c:
                count += c[a]
            if b in c:
                count += c[b]
            if i in c:
                c[i] -= 1
        return count