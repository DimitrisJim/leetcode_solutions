class Solution:
    def countPrefixes(self, words: List[str], s: str) -> int:
        partial = s.startswith
        return len(list(filter(partial, words)))