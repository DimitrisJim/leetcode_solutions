class Solution:
    @staticmethod
    def is_nozero(i):
        """ Filter, True if i is no-zero, False otherwise.

        Could also do:

            d = 1000
            while i < d:
                d //= 10
            while d:
                q, i = divmod(i, d)
                if not q:
                    return False
                d = d // 10
            return True

        but for Python, tranforming to str is just faster.
        """
        return '0' not in repr(i)

    def non_zero_nums(self, n, reverse=False):
        """ Yields no-zero numbers. """
        nozero = self.is_nozero
        if reverse:
            # 1 is lowest bound
            r = range(n, 0, -1)
        else:
            r = range(1, n)
        for i in r:
            if nozero(i):
                yield i

    def getNoZeroIntegers(self, n):
        advance = next
        upper = self.non_zero_nums(n - 1, reverse=True)
        lower = self.non_zero_nums(n)

        # try largest + smallest and advance according to result
        # of their addition.
        u, l = advance(upper), advance(lower)
        while True:
            candidate = u + l
            if candidate == n:
                return [l, u]
            elif candidate < n:
                l = advance(lower)
            else:
                u = advance(upper)
