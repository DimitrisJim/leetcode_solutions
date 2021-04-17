class Solution:
    def reverseBits(self, n):
        # count leading_zeros -- i.e zero bits at the beginning
        # of n. (where n is assumed 32bit)
        c = 1 << 31
        rev = leading_zeros = 0
        while n and n & c == 0:
            leading_zeros += 1
            c >>= 1
        # after finding leading_zeros, go through n and add
        # set bits (n & 1) to rev. rev is shifted left while
        # n is shifted right.
        while n:
            rev = (rev << 1) | n & 1
            n >>= 1
        return rev << leading_zeros
