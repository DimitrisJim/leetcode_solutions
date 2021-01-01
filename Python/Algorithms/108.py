# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:

    def sortedArrayToBST(self, nums):
        # bring it in function allow quicker look-ups.
        def build_tree(lst, low, high):
            """ Need to balance resulting tree i.e max 1 difference
            between two children of a given node.

            Since we have a sorted array, we know we can separate the array in
            a triplet: (lower_than_mid, mid, higher_than_mid).

            mid: then becomes our new node
            lower_than_mid: our left branch.
            higher_than_mid: our right branch.

            Recursively solving this is straight-forward.
            """
            # base case.
            if low == high:
                return None
            mid = (high + low) // 2
            node = TreeNode(lst[mid])
            node.left = build_tree(lst, low, mid)
            node.right = build_tree(lst, mid + 1, high)

            return node
        return build_tree(nums, 0, len(nums))
