# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root):
        if not root:
            return []

        stack, results = [(root, 0)], []
        while stack:
            node, level = stack.pop()
            left, right, val = node.left, node.right, node.val
            if level < len(results):
                results[level].append(val)
            else:
                results.append([val])
            level += 1
            if right:
                stack.append((right, level))
            if left:
                stack.append((left, level))
        return results
