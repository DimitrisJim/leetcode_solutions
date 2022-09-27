class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        if pos := word.find(ch):
            return "".join([word[:pos+1][::-1], word[pos+1:]])
        return word