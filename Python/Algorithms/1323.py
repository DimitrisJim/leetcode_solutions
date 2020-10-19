class Solution:
    def maximum69Number (_, num: int) -> int:
        if num == 6 or num == 9:
            return 9
        if num == 99 or num == 999 or num == 9999:
            return num
        divmod_ = divmod
        # Get correct multiplier for 9. (i.e how manhy digits is num)
        d = 10 ** (num.bit_length() // 4)
        d = d * 9
        div, t = divmod_(num, d)
        # Continuously reduce d and t until we find the part
        # of num we can't divide with d.
        while div:
            d, _ = divmod_(d, 10)
            div, t = divmod_(t, d)
        # Then, we just add d // 3 to the final number.
        # I.e num = 9969 => d is reduced to 90
        # so add 90 // 3 (30)
        return num + (d // 3)
