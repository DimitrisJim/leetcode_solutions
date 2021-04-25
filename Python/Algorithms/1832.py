class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        return len({*sentence}) == 26
