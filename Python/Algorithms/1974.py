class Solution:
    def minTimeToType(self, word: str) -> int:
        result = len(word)
        prev = 'a'
        for c in word:
            dst = abs(ord(c) - ord(prev))
            result += min(dst, 26 - dst)
            prev = c
        return result
