from itertools import cycle


class Solution:

    def minOperations(self, s: str) -> int:
        def _(s, seq='01'):
            toggle = cycle(seq)
            return sum(c != next(toggle) for c in s)

        return min(_(s), _(s, '10'))
