class Solution:
    def getRow(self, n: int):
        res, row = [1], n + 1
        mid, odd = ((row // 2 + 1), True) if row & 1 else ((row // 2), False)
        for k in range(1, mid):
            res.append(round(res[-1] * ((n + 1 - k) / k)))
        res.extend(reversed(res[:-1]) if odd else reversed(res))
        return res
