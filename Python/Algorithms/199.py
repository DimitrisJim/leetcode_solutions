# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root):
        if not root:
            return []

        nodes = [root.val]
        stack = [(root, 0)]
        while stack:
            node, level = stack.pop()

            # will only append first node seen with this specific
            # level (rightmost due to our pushing.)
            if level >= len(nodes):
                nodes.append(node.val)

            left, right = node.left, node.right
            if left:
                stack.append((left, level + 1))
            # we wanna see rightmost first so push second
            # on stack.
            if right:
                stack.append((right, level + 1))
        return nodes
