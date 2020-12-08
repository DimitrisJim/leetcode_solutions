from collections import chain, repeat


class Solution:

    vowels = {*'aAiIeEuUoO'}

    def toGoatLatin(self, S: str) -> str:
        # Keep sets of vowels, consonants.
        vowels = self.vowels

        # hold result.
        result, from_it = [], chain.from_iterable

        # Use enumerate to have valid ammount of 'a's to add.
        for ammount, w in enumerate(S.split(), 1):
            # repeat a, find word, join.
            to_add = repeat('a', ammount)
            part = w if w[0] in vowels else (w[1:] + w[0])
            result.append("".join(from_it([part, "ma", to_add])))

        # join one last time.
        return " ".join(result)
