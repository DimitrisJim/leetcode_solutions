from collections import deque
from operator import attrgetter


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def mergeTrees(self, t1, t2):
        # Handle edge cases
        if t1 is None and t2 is None:
            return None
        if t1 is None:
            return t2
        if t2 is None:
            return t1
        # Use attrgetter to quickly grab left + right
        left_right = attrgetter('left', 'right')
        val = attrgetter('val')
        # Both are not None here.
        # Create root from tree roots
        root = TreeNode(val(t1) + val(t2))
        # breadth-first search using deque as queue
        queue = deque()
        enqueue, dequeue = queue.appendleft, queue.pop
        enqueue([root, left_right(t1), left_right(t2)])
        while queue:
            r, (l1, r1), (l2, r2) = dequeue()
            # Nothing to do for left.
            if l1 is None and l2 is None:
                r.left = None
            # Build left and add left-right subnodes to queue.
            elif l1 is not None and l2 is not None:
                r.left = TreeNode(val(l1) + val(l2))
                enqueue([r.left, left_right(l1), left_right(l2)])
            else:
                # attach immediately:
                if l1 is not None:
                    r.left = TreeNode(val(l1), *left_right(l1))
                else:
                    r.left = TreeNode(val(l2), *left_right(l2))

            # Nothing to do for right.
            if r1 is None and r2 is None:
                r.right = None
            # Build right and add left-right subnodes to queue.
            elif r1 is not None and r2 is not None:
                r.right = TreeNode(val(r1) + val(r2))
                enqueue([r.right, left_right(r1), left_right(r2)])
            else:
                # attach immediately
                if r1 is not None:
                    r.right = TreeNode(val(r1), *left_right(r1))
                # attach immediately
                else:
                    r.right = TreeNode(val(r2), *left_right(r2))
        return root
