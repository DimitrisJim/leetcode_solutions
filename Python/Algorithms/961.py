class Solution:
    def repeatedNTimes(self, A):
        seen = set()
        add = seen.add
        for i in A:
            if i in seen:
                return i
            add(i)
