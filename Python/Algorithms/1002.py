from collections import Counter


class Solution:
    # 40 - 92.66, 14.3 - 54.19
    def commonChars(self, A):
        # Build counter of characters
        Counter_ = Counter
        commons = Counter_(A[0])
        for i in range(1, len(A)):
            # In-place intersection of minimum of elements. 
            commons &= Counter_(A[i])
            # bail whenever it becomes empty.
            if not commons:
                return []
        return commons.elements()
