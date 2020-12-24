class Solution:
    @staticmethod
    def best_guess_k(c, n):
        """
        Basically, tries to increase k faster when
        c is a really large value.
        """
        # local look-ups
        range_, sum_, k = range, sum, 0
        # try and increase k faster:
        if c <= 100:
            return 0
        if c <= 1000:
            ammount = 2
        elif c <= 100000:
            ammount = 10
        elif c <= 10_000_000:
            ammount = 50
        else:
            ammount = 250
        k = 0
        while True:
            sumk = sum_(
                ((k + 1) * i + (((k * (k + 1)) >> 1) * n))
                for i in range_(1, n+1)
            )
            if sumk < c:
                k = k + ammount
            else:
                k = k - ammount
                break
        return k

    def distributeCandies(self, candies, n):
        def arr_to_k(k, n):
            """ Build and return array, used when we know k."""
            return [
                ((k + 1) * i + (((k * (k + 1)) >> 1) * n))
                for i in range(1, n+1)
            ]

        # local look-ups
        range_, sum_ = range, sum

        # Find how many times we can go through the array
        # and what will be left over.
        prev, next_ = 0, 0
        k = self.best_guess_k(candies, n)
        while candies >= next_:
            prev = next_
            next_ = sum_(
                ((k + 1) * i + (((k * (k + 1)) >> 1) * n))
                for i in range_(1, n+1)
            )
            k = k + 1
        # We're done, return the array.
        if candies == next_:
            return arr_to_k(k-1, n)

        # see what's left and adjust k (must go back twice, once to go
        # to next and once again to go to previous.)
        left = candies - prev
        k = 0 if k - 2 < 0 else k - 2
        # prev == 0 => candies < n. (== case handled by candies == next_)
        # build results accordingly.
        if prev:
            # build array until k-1.
            result = arr_to_k(k, n)
        else:
            result = [0] * n
            k = k - 1

        # Add leftovers.
        k = k + 1
        for i in range_(1, n+1):
            # Subtract from next value for k the value for k-1 (result[i-1]).
            to_add = ((k + 1) * i + ((k * (k + 1)) >> 1) * n) - result[i-1]
            if to_add >= left:
                result[i-1] += left
                break
            result[i-1] += to_add
            left = left - to_add
        return result
