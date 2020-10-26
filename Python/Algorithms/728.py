class Solution:

    def selfDividingNumbers(self, left, right):
        ret = []
        divmod_ = divmod
        for num in range(left, right+1):
            # Find number of digits.
            digits, temp = 0, num
            while temp:
                digits, temp = digits + 1, temp // 10
            div = 10 ** (digits - 1)
            # go through digits and count number of
            # digits that divide num.
            count, red = 0, num
            while div:
                d, red = divmod_(red, div)
                if d and not num % d:
                    count = count + 1
                else:
                    break
                div = div // 10
            # If all digits divide add it to result.
            if count == digits:
                ret.append(num)

        return ret
