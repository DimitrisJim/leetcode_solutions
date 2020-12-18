from collections import deque


class Solution:
    def averageOfLevels(self, root):
        res = []
        # use None as a marker for levels.
        q = deque([root, None])
        numNodes, value = 0, 0
        while True:
            n = q.popleft()
            if n is None:
                if not numNodes:
                    break
                res.append(value / numNodes)
                value, numNodes = 0, 0
                # place marker again
                q.append(None)
                continue
            # Non-None, increase counters, add children:
            val, left, right = n.val, n.left, n.right
            value = value + val
            numNodes = numNodes + 1
            if left:
                q.append(left)
            if right:
                q.append(right)
        return res
