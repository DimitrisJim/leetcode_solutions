from collections import Counter


class Solution:
    def numEquivDominoPairs(self, dominoes) -> int:
        counts = Counter(map(frozenset, dominoes)).values()
        return int(.5 * sum(n * (n - 1) for n in counts if n > 1))
