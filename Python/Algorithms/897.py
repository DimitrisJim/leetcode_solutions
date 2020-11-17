class Solution:
    def increasingBST(self, root):
        # inorder traversal
        stack = []
        inorder = []
        spop, sappend = stack.pop, stack.append
        iappend = inorder.append
        while stack or root:
            if root:
                sappend(root)
                root = root.left
            else:
                root = spop()
                root.left = None
                iappend(root) 
                root = root.right
        # re-attach
        for i in range(len(inorder) - 1, 0, -1):
            inorder[i-1].right = inorder[i]
        # return new root.
        return inorder[0]
