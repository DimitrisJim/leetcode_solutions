# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        if not root:
            return []

        values = []
        stack = [root]
        while stack:
            node = stack.pop()

            values.append(node.val)
            left, right = node.left, node.right
            if right:
                stack.append(right)
            if left:
                stack.append(left)
        return values
