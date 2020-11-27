from itertools import chain, zip_longest


class Solution:
    def arrayStringsAreEqual(self, word1, word2):
        chain_one = chain.from_iterable(word1)
        chain_two = chain.from_iterable(word2)

        for ca, cb in zip_longest(chain_one, chain_two):
            if ca != cb:
                return False
        return True
