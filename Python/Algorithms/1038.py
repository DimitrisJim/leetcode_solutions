# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstToGst(self, root):
        # dfs, inorder, right first.
        def dfs_inorder(node, s=0):
            val, left, right = node.val, node.left, node.right
            # go right and get accumulated values in s.
            if right:
                (nr, s) = dfs_inorder(right, s)
                node.right = nr
            # add to our value.
            node.val = val + s
            if left:
                (nl, s) = dfs_inorder(left, node.val)
                node.left = nl
                # need to return value accumulated from left if it
                # exists. Take care to return same node, through.
                return node, s
            # No left, return current value accumulated (node.val) and
            # the right node.
            return node, node.val

        # (root, val) return value, keep 0 element of tuple.
        return dfs_inorder(root)[0]
