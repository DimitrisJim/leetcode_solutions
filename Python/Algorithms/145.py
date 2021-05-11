# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, node):
        # See wiki page for iterative traversal algorithm.
        # I, in general, don't remember iterative version by heart.
        stack, lastVisited, values = [], None, []
        while stack or node:
            # keep going left until possible.
            if node:
                stack.append(node)
                node = node.left
            elif stack:
                end = stack[-1]
                # go right, if it exists and it hasn't been
                # visited.
                if end.right and end.right != lastVisited:
                    node = end.right
                else:
                    values.append(end.val)
                    lastVisited = stack.pop()
        return values
