class Solution:
    def findSolution(self, customfunction, z):
        """ """
        # Annoying how i, j supposedly valid in range(1, 1001) but
        # can completely bust down # of iterations when noticing how
        # they all take values [0, 100]
        func, res, range_ = customfunction.f, [], range(1, 101)
        append = res.append
        for i in range_:
            for j in range_:
                result = func(i, j)
                if result == z:
                    append([i, j])
                    break
                if result > z:
                    break
        return res
