class Solution:
    def sortSentence(self, s: str) -> str:
        words = s.split()
        result = [None] * len(words)
        for w in words:
            word, pos = w[:-1], int(w[-1]) - 1
            result[pos] = word
        return " ".join(result)
