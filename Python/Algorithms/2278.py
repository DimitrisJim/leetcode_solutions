class Solution:
    def percentageLetter(self, s: str, letter: str) -> int:
        return int(sum(1 for c in s if c == letter) / len(s) * 100)