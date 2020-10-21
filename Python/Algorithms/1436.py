class Solution:
    def destCity(self, paths):
        sources, dests = set(), set()
        sa, da = sources.add, dests.add
        for s, d in paths:
            sa(s)
            da(d)
        return (dests - sources).pop()
