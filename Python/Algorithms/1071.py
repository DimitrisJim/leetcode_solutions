class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        s, l = (str1, str2) if len(str1) < len(str2) else (str2, str1)
        
        while s and l.startswith(s):
            while l.startswith(s):
                l = l[len(s):]
            s, l = l, s
        # if s not empty, not divisor, else return remainder.
        return "" if s else l