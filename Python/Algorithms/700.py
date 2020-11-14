class Solution:
    def searchBST(self, root, val):
        # perform simple binary search.
        while root:
            rval = root.val
            if val == rval:
                return root
            root = root.right if val > rval else root.left
        return None
