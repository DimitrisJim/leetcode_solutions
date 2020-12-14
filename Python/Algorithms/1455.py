class Solution:
    def isPrefixOfWord(self, sentence, searchWord):
        isprefix = str.startswith
        for idx, s in enumerate(sentence.split(), start=1):
            if isprefix(s, searchWord):
                return idx
        return -1
