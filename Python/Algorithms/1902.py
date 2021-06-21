class Solution:
    def largestOddNumber(self, num: str) -> str:
        odds = {*"13579"}
        for i in range(len(num) - 1, -1, -1):
            if num[i] in odds:
                return num[:i+1]
        return ""
