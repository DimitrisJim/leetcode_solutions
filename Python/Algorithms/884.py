class Solution:
    def uncommonFromSentences(self, A, B):
        sA, seenA = set(), set()
        for i in A.split():
            if i not in seenA:
                sA.add(i)
                seenA.add(i)
            else:
                sA.discard(i)

        sB, seenB = set(), set()
        for i in B.split():
            if i not in seenB:
                sB.add(i)
                seenB.add(i)
            else:
                sB.discard(i)

        sA -= seenB
        sB -= seenA
        return sA | sB
