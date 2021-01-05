class Solution:
    def thousandSeparator(self, n: int) -> str:
        res = []
        n, count = repr(n), 0
        for i in range(len(n) - 1, -1, -1):
            if count == 3:
                res.append('.')
                count = 1
            else:
                count = count + 1
            res.append(n[i])
        return "".join(reversed(res))
