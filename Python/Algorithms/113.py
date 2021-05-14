# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: TreeNode, targetSum: int) -> List[List[int]]:
        if not root:
            return

        # keep current node, running sum and level in stack.
        stack = [[root, root.val, 0]]
        path = []
        while stack:
            node, current_sum, level = stack.pop()
            # we've gone back, trim path.
            if level <= len(path):
                del path[level:]
            path.append(node.val)

            left, right = node.left, node.right
            # leaf ? if so and if current_sum == targetSum, return.
            if not left and not right and current_sum == targetSum:
                yield path
            # else, traverse.
            if right:
                stack.append([right, current_sum + right.val, level + 1])
            if left:
                stack.append([left, current_sum + left.val, level + 1])
