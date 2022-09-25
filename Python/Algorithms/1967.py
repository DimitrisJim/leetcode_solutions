class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        count = 0
        for pat in patterns:
            if pat in word:
                count += 1
        return count