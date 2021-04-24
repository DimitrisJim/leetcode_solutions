class Solution:
    def isSymmetric(self, root) -> bool:
        left, right = root.left, root.right
        if not left and not right:
            return True
        if any(i is None for i in [left, right]):
            return False

        # Use a stack for each subtree.
        sleft, sright = [left], [right]
        while sleft or sright:
            left, right = sleft.pop(), sright.pop()

            # Value check.
            if left.val != right.val:
                return False

            # grab children for each
            lleft, lright = left.left, left.right
            rleft, rright = right.left, right.right
            # and append them symmetrically.
            if lleft and rright:
                sleft.append(lleft)
                sright.append(rright)
            else:
                # One of them is None. If not both,
                # we got a mismatch.
                if lleft != rright:
                    return False
            if lright and rleft:
                sleft.append(lright)
                sright.append(rleft)
            else:
                if lright != rleft:
                    return False
        return sleft == sright
