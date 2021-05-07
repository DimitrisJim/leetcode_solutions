class Solution:
    def replaceDigits(self, s: str) -> str:
        result, i = [], 1
        # go through s and shift chars.
        while i < len(s):
            c, shift = s[i-1], s[i]
            result.append(c)
            # shift('a', '3') => chr(97 + 3) => chr(100) => 'c'
            result.append(chr(ord(c) + int(shift)))
            i += 2
        # if s is of odd length, last char is left alone at end.
        if len(s) & 1:
            result.append(s[-1])

        return "".join(result)
