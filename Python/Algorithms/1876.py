class Solution:
    def countGoodSubstrings(self, s: str) -> int:
        count, i, end = 0, 2, len(s)
        while i < end:
            a, b, c = s[i-2], s[i-1], s[i]
            if a == b == c:
                i += 2
                continue
            count += a != b and b != c and a != c
            i += 1
        return count
