from string import ascii_uppercase


class Solution:

    # (l)etters to decimal
    ltod = {c: i for i, c in enumerate(ascii_uppercase, start=1)}

    def titleToNumber(self, s):
        ltod, col, n = self.ltod, 0, len(s) - 1
        # Follows formula: (where s is the string and n = len(s) - 1)
        # (s[0] * (26 ** n) + (s[1] * (26 ** (n - 1)) + ... + s[n])
        for c in s:
            col = col + ltod[c] * 26 ** n
            n = n - 1
        return col
