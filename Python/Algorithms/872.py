from itertools import zip_longest


class Solution:
    def leafSimilar(self, root1, root2) -> bool:
        # yields leaf nodes recursively.
        def yield_leafs(node):
            if not node.left and not node.right:
                yield node.val

            if node.left:
                yield from yield_leafs(node.left)
            if node.right:
                yield from yield_leafs(node.right)
        # check that they are all equal.
        yl = yield_leafs
        return all(i == j for i, j in zip_longest(yl(root1), yl(root2)))
