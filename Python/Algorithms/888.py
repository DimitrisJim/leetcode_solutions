class Solution:
    def fairCandySwap(self, A, B):
        sA, sB = sum(A), sum(B)
        max_, minSet = (A, {*B}) if sA > sB else (B, {*A})
        diff_mid = abs(sA - sB) // 2

        for i in max_:
            j = i - diff_mid
            if j in minSet:
                return [j, i] if max_ == B else [i, j]
