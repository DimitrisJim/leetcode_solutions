class Solution:
    def diStringMatch(self, S: str) -> List[int]:
        res = []
        append = res.append
        i, j = 0, len(S)
        for c in S:
            if c == 'I':
                append(i)
                i += 1
            else:
                append(j)
                j -= 1
        append(j)
        return res
