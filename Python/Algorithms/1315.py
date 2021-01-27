# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumEvenGrandparent(self, root) -> int:
        def traverse_sum(node, parent=None):
            sum_ = 0
            val, left, right = node.val, node.left, node.right
            if left:
                if parent is not None and parent & 1 == 0:
                    sum_ = sum_ + left.val
                sum_ = sum_ + traverse_sum(left, val)
            if right:
                if parent is not None and parent & 1 == 0:
                    sum_ = sum_ + right.val
                sum_ = sum_ + traverse_sum(right, val)
            return sum_

        # we know min nodes == 1.
        return traverse_sum(root)
