from collections import deque

class Solution:
    def sortArrayByParity(self, A):
        # O(N) since append and appendleft are O(1)
        # but O(N) space.
        d = deque()
        a, al = d.append, d.appendleft
        for i in A:
            a(i) if i & 1 else al(i)
        return d

    def sortArrayByParity2(self, A):
        # O(nlogn) but O(1) space.
        A.sort(key=lambda x: x & 1)
        return A
