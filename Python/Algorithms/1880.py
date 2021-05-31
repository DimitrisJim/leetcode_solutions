class Solution:

    def isSumEqual(self, firstWord: str, secondWord: str, targetWord: str) -> bool:
        def asInt(s): return int("".join(str(ord(i) - 97)
                                         for i in s).lstrip('0') or 0)
        return asInt(firstWord) + asInt(secondWord) == asInt(targetWord)
