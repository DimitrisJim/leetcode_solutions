class Solution:
    def plusOne(self, digits):
        i = len(digits) - 1
        while i >= 0:
            if digits[i] == 9:
                digits[i] = 0
                i = i - 1
            else:
                digits[i] += 1
                break
        if i == -1 and digits[0] == 0:
            digits.append(1)
            return reversed(digits)
        return digits
