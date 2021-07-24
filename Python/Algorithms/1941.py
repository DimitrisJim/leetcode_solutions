class Solution:
    def areOccurrencesEqual(self, s: str) -> bool:
        return len({*Counter(s).values()}) == 1
