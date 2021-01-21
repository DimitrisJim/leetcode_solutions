class Solution:
    def isSameTree(self, p, q):
        # Handle empty cases.
        if p is None and q is None:
            return True
        elif (p and not q) or (q and not p):
            return False

        s1, s2 = [p], [q]
        # go through until both have elements.
        while s1 and s2:
            n1, n2 = s1.pop(), s2.pop()

            n1left, n1right, n1val = n1.left, n1.right, n1.val
            n2left, n2right, n2val = n2.left, n2.right, n2.val

            if n1val != n2val:
                return False
            # bail early if one is None and the other isn't
            if n1left:
                if not n2left:
                    return False
                s1.append(n1left)
                s2.append(n2left)
            else:
                if n2left:
                    return False
            if n1right:
                if not n2right:
                    return False
                s1.append(n1right)
                s2.append(n2right)
            else:
                if n2right:
                    return False

        # If any of the structures still has elements,
        # the trees are different.
        if s1 or s2:
            return False
        return True
