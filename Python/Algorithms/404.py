class Solution:
    def sumOfLeftLeaves(self, root) -> int:
        def yield_left_values(node):
            left, right = node.left, node.right

            # if left has no children, it is a leaf,
            # yield its value.
            if left:
                if not left.left and not left.right:
                    yield left.val
                else:
                    yield from yield_left_values(left)
            if right:
                yield from yield_left_values(right)

        # pass generator to sum and return.
        return sum(yield_left_values(root), 0)
