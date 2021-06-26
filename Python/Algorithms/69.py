class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 1:
            return 1
        # Rough initial estimate can only be >= x.
        # Use Babylonian (?) method. Next guess is
        # arithmetic mean of [g, x/g].
        guess = x >> 1
        while guess * guess > x:
            guess = (guess + x // guess) >> 1
        return guess
