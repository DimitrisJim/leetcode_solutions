class Solution:

    pows = [10 ** i for i in range(10)]

    def reverse(self, x: int) -> int:
        def to_digits(n: int, dm=divmod):
            """ Bring into local scope. Returns digits as list for n."""
            digits = []
            while n:
                n, r = dm(n, 10)
                digits.append(r)
            return digits

        bound = -0x80000000 if x > 0 else 0x7FFFFFFF
        # handle x == -0x80000000 case, no positive counterpart in 32bit space
        if x == -0x80000000:
            return 0
        x = abs(x)
        digits = to_digits(x)

        # Check we *can* build the number.
        if len(digits) == 10:
            # check against the limit (2 ** 31 - 1 or -2 ** 31) to make sure
            # we do not exceed it. This doesn't create the number honoring the
            # assumption that 64 bit integers can't be used.
            # abs(bound + 1) and limit[-1] += 1 are used again in order to
            # not create a number larger than 2 ** 31.
            limit = to_digits(abs(bound + 1) if bound < 0 else bound)
            if bound < 0:
                limit[0] += 1
            for i in range(10):
                # compares digits of would-be number.
                a, b = digits[i], limit[-i-1]
                if a > b:
                    return 0
                if a < b:
                    break

        # Build the result by reversing digits and adding sign as necessary.
        pairs = zip(reversed(digits), self.pows)
        return sum(i * j for i, j in pairs) * (1 if bound < 0 else -1)
