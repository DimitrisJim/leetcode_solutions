class Solution:

    @staticmethod
    def presized_list(n):
        """ Return a pre-sized, 1-filled list based
        on n. Sizes range in:
            [9, 9+9, 9+9+9, 9+9+9+9, 9+9+9+9+9]
        """
        slots = 19
        if n > 10000:
            slots = 46
        elif n > 1000:
            slots = 37
        else:
            slots = 28
        return [0] * slots

    def countBalls(self, lowLimit, highLimit):
        # keep these local, called often.
        def count_digits(n):
            """ Count digit sum. """
            return sum(map(int, str(n)))

        def add_from_base(l, n, start=0, end=10):
            """ Adds from a base where base in always a
            multiple of 10. This way, count_digits only needs
            to be called on multiples of ten and not on every
            number.
            """
            base = count_digits(n)
            for i in range(start, end):
                l[base + i] += 1

        l = self.presized_list(highLimit)
        # find multiples of ten, what's left, for each lim.
        start, start_left = divmod(lowLimit, 10)
        end, end_left = divmod(highLimit + 1, 10) # note: + 1.

        # start == end -> we're on the same multiple of
        # ten. Add sums to l from [start_left, end_left)
        if start == end:
            add_from_base(l, start, start_left, end_left)
        # else -> we're on different multiples. Add everything
        # from [start_left, 10), [0, end_left) and go through
        # the rest of the range in multiples of ten, adding
        # numbers.
        else:
            add_from_base(l, start, start_left)
            add_from_base(l, end, end=end_left)

            # (start + 1) because we already added [start_left, 10)
            # (end - 1) because we don't want to double count last ten values.
            # we add +1 to make the range exclusive until (end - 1) * 10.
            start = (start + 1) * 10
            end = ((end - 1) * 10) + 1
            for k in range(start, end, 10):
                add_from_base(l, k)
        # finally, return max.
        return max(l)
