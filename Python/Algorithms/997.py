class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        trust_list = [0] * n
        for i, j in trust:
            trust_list[i-1] = -1
            if trust_list[j-1] >= 0:
                trust_list[j-1] += 1
        i, t = max(enumerate(trust_list), key=itemgetter(1))
        return (i + 1) if t == n - 1 else -1
