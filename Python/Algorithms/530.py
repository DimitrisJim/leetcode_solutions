# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def getMinimumDifference(self, root):
        def dfs(node):
            """ DFS traverse and yield back node values. """
            val, left, right = node.val, node.left, node.right
            if left:
                yield from dfs(left)
            yield val
            if right:
                yield from dfs(right)

        # Find min from values.
        g = [*dfs(root)]
        return min(g[i] - g[i-1] for i in range(1, len(g)))
