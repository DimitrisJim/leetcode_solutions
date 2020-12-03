from collections import Counter


class Solution:
    def countCharacters(self, words, chars):
        counter, len_, all_ = Counter, len, all
        cs, cc, lc = {*chars}, counter(chars), len_(chars)

        # filter by length first and then by contents.
        length = 0
        for word in words:
            lw = len_(word)
            if lw <= lc and all_(c in cs for c in word):
                if not counter(word) - cc:
                    length = length + lw
        return length
