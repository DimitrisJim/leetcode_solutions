class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        """ Go through pairs until the length of the smallest
        input string.
        
        Then compare lengths and extend with whats left from the
        largest one.
        """
        result = []
        for pair in zip(word1, word2):
            result.extend(pair)

        lw1, lw2 = len(word1), len(word2)
        if lw1 > lw2:
            result.extend(word1[lw2:])
        elif lw1 < lw2:
            result.extend(word2[lw1:])
        return "".join(result)
