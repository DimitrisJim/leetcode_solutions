class Solution:
    def levelOrderBottom(self, root):
        if not root:
            return []
        d, level = [(root, 0)], 0
        res = [[]]
        while d:
            n, lvl = d.pop()
            left, right = n.left, n.right
            # First right, then left.
            if right:
                d.append((right, lvl + 1))
            if left:
                d.append((left, lvl + 1))

            # We have another level, add another empty
            # list for us to populate.
            if lvl > level:
                res.append([])
                level = lvl
            res[lvl].append(n.val)
        return reversed(res)
