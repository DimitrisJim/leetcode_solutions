# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def deepestLeavesSum(self, root):
        l_sum = depth = 0
        def traverse(node, d=0):
            nonlocal depth, l_sum
            val, left, right = node.val, node.left, node.right

            if not left and not right:
                if d > depth:
                    depth = d
                    l_sum = val
                elif d == depth:
                    l_sum = l_sum + val
            else:
                if left:
                    traverse(left, d + 1)
                if right:
                    traverse(right, d + 1)
        traverse(root)
        return l_sum
