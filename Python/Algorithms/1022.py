class Solution:
    def sumRootToLeaf(self, root):       
        paths, stack = [], [root]
        while stack:
            node = stack.pop()
            val = node.val
            if node.left is None and node.right is None:
                paths.append(val)
                continue
                
            if node.right:
                node.right.val = (val << 1) | node.right.val
                stack.append(node.right)
            if node.left:
                node.left.val = (val << 1) | node.left.val
                stack.append(node.left)

        return sum(paths)
