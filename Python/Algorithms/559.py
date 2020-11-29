class Solution:
    def maxDepth(self, root):
        max_ = max

        # tail-recursive though Python don't care.
        def height(node):
            if not node.children:
                return 1
            return 1 + max_(height(c) for c in node.children)
        return height(root) if root else 0
