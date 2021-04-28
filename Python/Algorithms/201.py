class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        if left == right:
            return left

        # First interesting property, took me some time to notice.
        #
        # if there's a difference in 1 bit it means, in the range
        # [left, right] there exists a number with the binary repr
        # 100....000 (right.bit_length() - 1 zeroes) that completely
        # zeroes out all numbers smaller than it. The result, regardless
        # the range, will be 0.
        bits = left.bit_length()
        if bits < right.bit_length():
            return 0

        # Second interesting property, way more time to notice.
        #
        # The result, when the number of bits in the numbers is equal, is
        # equal to the binary number who's prefix is equal to the equal
        # prefixes of left and right. The rest of the bits are zero.
        # An example might better illustrate this:
        #
        # left = 2146738493, right = 2147483647
        #
        # And, in binary:
        #
        #   left  = '1111111111101001010000100111101'
        #   right = '1111111111111111111111111111111'
        #
        # The result will be:
        #
        #   '1111111111100000000000000000000' == 2146435072
        #
        # I.e the common prefix of left and right, '11111111111' followed by zeroes '00000000000000000000'.
        # This makes sense in the same way the first observation does. In the range between left and right,
        # the different combinations of 0 and 1 completely cancel each other out (and, by definition, all
        # combinations will exist between '11110..' and '11111..').
        result = mask = 1 << (bits - 1)
        while mask := mask >> 1:
            # continue until the prefix matches
            if mask & left == mask & right:
                result |= mask & left
            else:
                break
        return result
