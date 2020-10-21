class Solution:
    def maxDepth(self, s):
        depth = max_ = 0
        ord_ = ord
        for c in s:
            v = ord_(c)
            if v == 40:
                depth = depth + 1
                if depth > max_:
                    max_ = depth
            if v == 41:
                depth = depth - 1
        return max_
