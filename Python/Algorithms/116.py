"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""


class Solution:
    def connect(self, root):
        def recursive_connect(node):
            left, right = node.left, node.right

            if left and right:
                left.next = right
            elif left is None and right is None:
                # leaf, return.
                return

            # link 'to_link' to its next node in tree or
            # None (i.e leave as is) if node.next is None
            if uncle := node.next:
                # ugly or cute?
                (right or left).next = uncle.left or uncle.right

            # visit children.
            if left:
                recursive_connect(left)
            if right:
                recursive_connect(right)

        # recurse if root.
        if root:
            recursive_connect(root)
            return root
