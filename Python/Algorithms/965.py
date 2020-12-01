# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isUnivalTree(self, root) -> bool:       
        value, stack = root.val, [root]
        push, pop = stack.append, stack.pop
        while stack:
            node = pop()
            # if value is the same, push on stack,
            # else, bail.
            for child in (node.left, node.right):
                if child:
                    if child.val != value:
                        return False
                    push(child)
        return True
