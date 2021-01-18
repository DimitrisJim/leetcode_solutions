# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
            
    def tree2str(self, t):
        def preorder(n):
            val, left, right = n.val, n.left, n.right
            s = f"{val}"
            if left:
                s = "".join([s, '(', preorder(left), ')'])
            else:
                if right:
                    s = "".join([s, '()'])
            if right:
                s = "".join([s, '(', preorder(right), ')'])
            return s

        if t:
            return preorder(t)
        return ""
