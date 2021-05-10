# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def inorderTraversal(self, node):
        stack = []
        while stack or (node is not None):
            # keep going left until possible.
            if node is not None:
                stack.append(node)
                node = node.left
            else:
                # pop left and go right
                node = stack.pop()
                yield node.val
                node = node.right
