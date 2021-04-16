class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        return sum(i != j for i, j in zip(s1, s2)) <= 2 and {*s1} == {*s2}
