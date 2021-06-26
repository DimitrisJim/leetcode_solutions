class Solution:
    def isPerfectSquare(self, num):
        if num == 1:
            return True
        guess = num >> 1
        while guess * guess > num:
            guess = (guess + num // guess) >> 1
        return guess * guess == num

    # is this cheating?
    def _isPerfectSquare(self, num: int) -> bool:
        d = num ** .5
        return d - math.floor(d) == 0
