class Solution:
    def validPalindrome(self, s: str) -> bool:
        start, end, diff = 0, len(s) - 1, 0
        while start < end:
            if s[start] != s[end]:
                diff = 1
                break
            start += 1
            end -= 1

        if diff == 0:
            return True
                
        if s[start+1:end+1] == s[start+1:end+1][::-1]:
            return True
        if s[start:end] == s[start:end][::-1]:
            return True
        return False