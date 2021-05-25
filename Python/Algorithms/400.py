class Solution:
    # digits until 10 * i for i in {1..9}
    limits = [
        9, 189, 2889, 38889, 488889, 5888889,
        68888889, 788888889, 8888888889
    ]

    def findNthDigit(self, n: int) -> int:
        if n < 10:
            return n
        lims, i = self.limits, 0
        while n > lims[i]:
            i += 1

        # need the largest value smaller than n.
        base = lims[i-1]
        # i == 0 => 1 digits. i == 1 => 2 digits..
        pos, digit = divmod(n - (base + 1), i+1)
        # just go from int to str to int for convenience.
        return int(str((10 ** i) + pos)[digit])
