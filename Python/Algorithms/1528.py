class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        # uses correct space.
        l = list(s)
        # go through and perform assignments.
        for i, j in enumerate(indices):
            l[j] = s[i]
        return "".join(l)
