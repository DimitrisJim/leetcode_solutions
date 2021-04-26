class Solution:
    def largestValues(self, root):
        maxes = []
        if not root:
            return maxes
        stack = [(root, 0)]

        while stack:
            node, level = stack.pop()

            if level >= len(maxes):
                # first time reaching this level]
                # append directly.
                maxes.append(node.val)
            else:
                # update maxes if node.val is larger.
                maxes[level] = max(node.val, maxes[level])

            left, right = node.left, node.right
            if left:
                stack.append((left, level+1))
            if right:
                stack.append((right, level+1))
        return maxes
