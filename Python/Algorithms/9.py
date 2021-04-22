class Solution:
    def isPalindrome(self, n):
        if n < 0:
            return False
        s = str(n)
        length = len(s)
        i, j = 0, length-1
        while i < j:
            if s[i] != s[j]:
                return False
            i += 1
            j -= 1
        return True
