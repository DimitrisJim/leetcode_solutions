from collections import Counter

class Solution:
    def judgeCircle(self, moves: str) -> bool:
        c = Counter(moves)
        return (c['L'] == c['R']) and (c['U'] == c['D'])
