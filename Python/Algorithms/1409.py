class Solution:
    def processQueries(self, queries, m):
        P, res = [*range(1, m+1)], []

        # the most inefficient approach.
        for i in queries:
            res.append(P.index(i))
            P.insert(0, P.pop(res[-1]))
        return res
