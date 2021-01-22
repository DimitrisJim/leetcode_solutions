# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root):
        def get_paths(node, prev):
            # build the result partially.
            sval = repr(node.val)
            res = "->".join([prev, sval]) if prev else sval

            # until we have left or right, recurse.
            left, right = node.left, node.right
            if left:
                yield from get_paths(left, res)
            if right:
                yield from get_paths(right, res)
            # yield back when we reach a leaf.
            if not left and not right:
                yield res

        if root:
            return [*get_paths(root, "")]
        return []
