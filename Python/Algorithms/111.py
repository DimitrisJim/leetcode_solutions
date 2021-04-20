class Solution:
    def minDepth(self, root) -> int:
        if root is None:
            return 0
        # we always have a root.
        min_depth = float('inf')
        stack = [(root, 1)]

        while stack:
            node, depth = stack.pop()

            # bail early if height > min_height
            if depth >= min_depth:
                continue
            else:
                # Add min height if we're on leaf, else
                # go through children.
                left, right = node.left, node.right
                if not left and not right:
                    min_depth = depth
                    continue
                if right:
                    stack.append((right, depth + 1))
                if left:
                    stack.append((left, depth + 1))
        # return found min_height
        return min_depth
