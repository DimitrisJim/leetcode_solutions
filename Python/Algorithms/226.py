# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def invertTree(self, root):
        if not root:
            return None
        stack = [(root, root.left, root.right)]
        push, pop = stack.append, stack.pop
        while stack:
            parent, left, right = pop()
            # invert.
            parent.left, parent.right = right, left
            
            # if children aren't None, add them to stack:
            if left:
                push((left, left.left, left.right))
            if right:
                push((right, right.left, right.right))
        return root
