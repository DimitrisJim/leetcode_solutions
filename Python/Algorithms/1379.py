class Solution:
    """ Note on Follow-up: If repeated value are allowed, a good option would be to check
    for paths. Traverse the original tree looking for the *path* to target and then follow
    that same path (based on values) to the node in cloned.
    """
    def getTargetCopy(self, _original, cloned, target):
        def traverse(node):
            if node.val == self.targetVal:
                return node

            left, right = node.left, node.right
            if left:
                n = traverse(left)
                if n:
                    return n
            if right:
                n = traverse(right)
                if n:
                    return n
        self.targetVal = target.val
        return traverse(cloned)
