from collections import Counter


class Solution:
    def frequencySort(self, s: str) -> str:
        counts = Counter(s)
        res = []
        for (c, count) in counts.most_common():
            res.append(c * count)
        return "".join(res)
