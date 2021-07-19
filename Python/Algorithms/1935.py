class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        broken = set(brokenLetters)
        i, end = 0, len(text)
        count = 0
        for w in text.split(" "):
            for c in w:
                if c in broken:
                    break
            else:
                count += 1
        return count
