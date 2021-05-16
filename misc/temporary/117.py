"""
Using a Queue, this isn't as hard. Going with recursion and (by their definition, O(1) space) is
trickier. This is a first inefficient solution. `total_nodes` and `visited` show how this isn't O(N)
(for 1043 nodes, we visit 23k times). I need to look into this again.
"""


class Solution:
    def connect(self, root: 'Node') -> 'Node':
        total_nodes = set()
        visited = 0

        def recursive_connect(node):
            nonlocal visited
            total_nodes.add(node)
            visited += 1

            left, right = node.left, node.right
            to_link = None
            if left and right:
                left.next = right
                to_link = right
            else:
                # one of left or right is not None.
                to_link = left or right

            # link 'to_link' to its next node in tree or
            # None if parent.next reaches None without
            # any nodes in the link having children.
            if node.next:
                uncle = node.next
                while uncle and uncle.left is None and uncle.right is None:
                    uncle = uncle.next
                # if uncle is None, next of to_link is None (no cousins?)
                if to_link:
                    if uncle is None:
                        to_link.next = None
                    else:
                        to_link.next = uncle.left or uncle.right
                if uncle and uncle.left:
                    uncle.left.next = uncle.right
                recursive_connect(node.next)
            if left:
                l, r = left.left, left.right
                if (l and l.next is None) or (r and r.next is None):
                    recursive_connect(left)
            if right:
                l, r = right.left, right.right
                if (l and l.next is None) or (r and r.next is None):
                    recursive_connect(right)

        if root:
            root.next = None
            recursive_connect(root)
            print(len(total_nodes), visited)
            return root
