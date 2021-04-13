class Solution:
    def truncateSentence(self, s: str, k: int) -> str:
        for idx, c in enumerate(s):
            if c == ' ':
                k -= 1
            if k == 0:
                return s[:idx]
        return s