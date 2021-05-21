"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""


class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        # keep track of what we've already visited as
        # a mapping from node values to (cloned) nodes.
        visited = dict()

        def clone(node):
            # return the created node if it has already been
            # visited.
            if node.val in visited:
                return visited[node.val]
            # create node *first* w/o neighbors, add to cache
            # and *then* recurse.
            n = Node(node.val)
            visited[n.val] = n
            n.neighbors = [clone(n) for n in node.neighbors]
            return n
        return clone(node) if node else node
