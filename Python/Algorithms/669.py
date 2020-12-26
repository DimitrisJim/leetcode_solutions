class Solution:

    __slots__ = 'root', 'keep'

    def trimmer(self, node, parent=None):
        # reached leaf
        if not node:
            return

        keep = self.keep
        value, left, right = node.val, node.left, node.right
        if value not in keep:
            # When we need to adjust root. This will only happen when
            # parent is None (and we only continuously re-adjust
            # roots in the first steps, when parent is set as non-None
            # it means we've found our root.)
            if parent is None:
                if value < keep.start:
                    self.root = parent = right
                # drop right subtree and keep left.
                else:
                    self.root = parent = left
                return self.trimmer(parent)

            # parent update based on value of val. if
            # val is smaller, we *know* we're on the left
            # subtree since parent is inside range and due to
            # BST property, a smaller value will be on the left.
            # Similarly if val is > range
            # drop left subtree and keep right subtree
            if value < keep.start:
                parent.left = right
                # go trim new left child.
                self.trimmer(right, parent)
            # drop right subtree and keep left.
            else:
                parent.right = left
                # go and trim new right child.
                self.trimmer(left, parent)
        else:
            # we're in range, call on children.
            self.trimmer(left, node)
            self.trimmer(right, node)

    def trimBST(self, root, low, high):
        # keep could be arg to trimmer; for root we need to
        # hold a reference which we can continuously update
        # if needed.
        self.root, self.keep = root, range(low, high + 1)
        # start trimming
        self.trimmer(root)
        return self.root
