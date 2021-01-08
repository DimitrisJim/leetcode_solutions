class Solution:
    def countBinarySubstrings(self, s):
        # keep track of consequtive ones, zeros
        c_ones = c_zeros = 0
        clear_on_next_zero = clear_on_next_one = False
        count = 0
        for i in s:
            if i == '0':
                if clear_on_next_zero:
                    clear_on_next_zero = False
                    c_zeros = 0
                c_zeros = c_zeros + 1
                # we have seen ones
                if c_ones:
                    if c_zeros <= c_ones:
                        count = count + 1
                    clear_on_next_one = True
            else:
                if clear_on_next_one:
                    clear_on_next_one = False
                    c_ones = 0
                c_ones = c_ones + 1
                # we have seen ones
                if c_zeros:
                    if c_ones <= c_zeros:
                        count = count + 1
                    clear_on_next_zero = True
        return count
