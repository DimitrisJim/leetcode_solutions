"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""


class Solution:
    def levelOrder(self, root: 'Node'):
        if not root:
            return []

        stack, results = [(root, 0)], []
        while stack:
            node, level = stack.pop()

            val = node.val
            if level < len(results):
                results[level].append(val)
            else:
                results.append([val])
            level += 1
            for child in filter(None, reversed(node.children)):
                stack.append((child, level))
        return results
