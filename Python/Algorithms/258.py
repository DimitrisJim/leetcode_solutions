class Solution:
    def addDigits(self, num):
        if not num:
            return num
        res = num % 9
        return res if res else 9
