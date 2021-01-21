class Solution:
    def getMaximumGenerated(self, n):
        if n < 2:
            return n
        A, max_, dm = [0, 1], 0, divmod
        for i in range(2, n+1):
            q, r = dm(i, 2)
            v1 = A[q]
            if v1 > max_:
                max_ = v1
            if r:
                res = v1 + A[q+1]
                if res > max_:
                    max_ = res
                A.append(res)
            else:
                A.append(v1)
        return max_
