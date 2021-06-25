class Solution:
    def myPow(self, x: float, n: int) -> float:
        if x == 0:
            return 0
        # flip sign of exponent.
        pos_exp, n = (True, n) if n > 0 else (False, -n)

        result = 1
        while n > 0:
            if n & 1:
                result *= x
            x *= x
            n //= 2

        # a ** (-b) => 1 / a ** b
        if pos_exp:
            return result
        return 1 / result
