class Solution:

    def isBalanced(self, root) -> bool:
        cache, abs_, id_ = {}, abs, id

        def height(n):
            # check if leaf or if we're in cache.
            if not n:
                return 0
            nid = id_(n)
            if nid in cache:
                return cache[nid]

            # Find height and place it in cache.
            cache[nid] = max(height(n.left), height(n.right)) + 1
            return cache[nid]

        def recurse(node):
            if not node:
                return True
            if not (recurse(node.left) and recurse(node.right)):
                return False
            return abs_(height(node.left) - height(node.right)) <= 1

        # kick-start recursions
        return recurse(root)
