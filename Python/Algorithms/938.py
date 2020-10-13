# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    def iter_tree(self, root: TreeNode, L: int, R: int) -> int:
        sum = 0
        if root is None:
            return 0
        l, r, v = root.left, root.right, root.val
        f = self.iter_tree
        if l:
            sum += f(l, L, R)
        if L <= v <= R:
            sum += v
        if r:
            sum += f(r, L, R)

        return sum

    def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:
        rvalue = root.val
        # short-circuit
        if L == R:
            return L

        # re-adjust the root to shorten iteration range.
        while not (L <= rvalue <= R):
            if rvalue < L:
                # move to right sub-tree
                root = root.right
                rvalue = root.val
            else:
                # move to left subtree
                root = root.left
                rvalue = root.val
        
        it_tree = self.iter_tree
        # special cases.
        if L == rvalue:
            return rvalue + it_tree(root.right, L, R)
        if R == rvalue:
            return rvalue + it_tree(root.left, L, R)
        
        return it_tree(root, L, R)
