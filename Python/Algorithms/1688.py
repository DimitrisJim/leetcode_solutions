class Solution:
    def numberOfMatches(self, n):
        # I feel like there's a quick formula for this.
        s, dm = 0, divmod
        while n > 1:
            n, r = dm(n, 2)
            s = s + n + r
        return s
