# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructMaximumBinaryTree(self, nums):
        # use scopes to access nums.
        def build_tree(start, end):
            # finds max value and its index.
            max_value, idx = -1, start
            for i in range(start, end):
                if nums[i] > max_value:
                    max_value, idx = nums[i], i

            # go left/right if elements will exist
            # in those ranges.
            left = build_tree(start, idx) if idx > start else None
            idx = idx + 1
            right = build_tree(idx, end) if end > idx else None

            # add left, right and return Node.
            return TreeNode(max_value, left, right)
        return build_tree(0, len(nums))
