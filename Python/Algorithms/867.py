class Solution:
    def transpose(self, A):
        rows, cols = range(len(A)), range(len(A[0]))
        res = []
        app = res.append
        for i in cols:
            app([A[j][i] for j in rows])
        return res
