# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def hasPathSum(self, root: TreeNode, targetSum: int) -> bool:
        if not root:
            return False
        # keep current node and running sum in stack.
        stack = [[root, root.val]]
        while stack:
            node, current_sum = stack.pop()

            left, right = node.left, node.right
            # leaf ? if so and if current_sum == targetSum, return.
            if not left and not right and current_sum == targetSum:
                return True
            # else, traverse.
            if left:
                stack.append([left, current_sum + left.val])
            if right:
                stack.append([right, current_sum + right.val])
        return False
