# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        def build(start, end):
            if start == end:
                return
            node = TreeNode(preorder[start])
            max_min = start + 1
            # find max val smaller than node.val (left subtree)
            while max_min < end and preorder[max_min] < node.val:
                max_min += 1
                
            # fill left with vals < node.val and right with vals > node.val
            node.left = build(start + 1, max_min)
            node.right = build(max_min, end)
            return node
        return build(0, len(preorder))
