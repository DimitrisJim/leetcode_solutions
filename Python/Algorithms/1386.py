class Solution:
    power_cache = {}

    def getKth(self, lo: int, hi: int, k: int) -> int:
        # could use tabulation
        def power_x(x, cache=self.power_cache):
            if x == 1:
                return 1
            if x in cache:
                return cache[x]
            elif x & 1:
                cache[x] = power_x(3 * x + 1) + 1
            else:
                cache[x] = power_x(x // 2) + 1
            return cache[x]

        # can use heap here.
        values = [(i, power_x(i)) for i in range(lo, hi+1)]
        return sorted(values, key=itemgetter(1))[k-1][0]
